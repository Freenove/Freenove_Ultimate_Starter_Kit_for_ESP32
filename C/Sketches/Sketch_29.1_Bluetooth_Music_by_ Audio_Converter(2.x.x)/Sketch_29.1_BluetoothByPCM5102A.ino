/**********************************************************************
  Filename    : Bluetooth Music By PCM5102
  Description : Use ESP32 to play the audio received via Bluetooth.
                Use your phone's Bluetooth connection to ESP32, 
                then open the music APP and play the music, 
                and you'll hear ESP32 play the phone's music
  Auther      : www.freenove.com
  Modification: 2024/06/20
**********************************************************************/
#include "BluetoothSerial.h"
#include "driver/i2s.h"
#include "nvs.h"
#include "nvs_flash.h"

#include "esp_bt.h"
#include "bt_app_core.h"
#include "bt_app_av.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"

#define CONFIG_I2S_LRCK_PIN 25
#define CONFIG_I2S_BCK_PIN  26
#define CONFIG_I2S_DATA_PIN 22
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32");
  Serial.println("Init seccess!");

  esp_err_t err = nvs_flash_init();
  if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    err = nvs_flash_init();
  }
  
  i2s_config_t i2s_config;
  i2s_config.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX);
  
  i2s_config.bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT;
  i2s_config.sample_rate = 44100;
  i2s_config.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT;
  i2s_config.communication_format = I2S_COMM_FORMAT_STAND_MSB;
  i2s_config.intr_alloc_flags = 0;
  i2s_config.dma_desc_num = 6;
  i2s_config.dma_frame_num = 60;
  i2s_config.tx_desc_auto_clear = true;
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  
  i2s_pin_config_t pin_config;
  pin_config.mck_io_num = I2S_PIN_NO_CHANGE;
  pin_config.bck_io_num = CONFIG_I2S_BCK_PIN;
  pin_config.ws_io_num = CONFIG_I2S_LRCK_PIN;
  pin_config.data_out_num = CONFIG_I2S_DATA_PIN;
  pin_config.data_in_num = I2S_PIN_NO_CHANGE;
  i2s_set_pin(I2S_NUM_0, &pin_config);

  bt_app_task_start_up();
  
 /* initialize A2DP sink */
  esp_a2d_register_callback(&bt_app_a2d_cb);
  esp_a2d_sink_register_data_callback(bt_app_a2d_data_cb);
  esp_a2d_sink_init();
  /* initialize AVRCP controller */
  esp_avrc_ct_init();
  esp_avrc_ct_register_callback(bt_app_rc_ct_cb);
  /* set discoverable and connectable mode, wait to be connected */
  esp_bt_gap_set_scan_mode(ESP_BT_CONNECTABLE, ESP_BT_GENERAL_DISCOVERABLE);
  Serial.println("ok");
}

void loop(){
  ;  
}
