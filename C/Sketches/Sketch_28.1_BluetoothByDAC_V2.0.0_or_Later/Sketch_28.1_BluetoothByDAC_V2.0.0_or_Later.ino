/**********************************************************************
  Filename    : BluetoothByDAC
  Description : Use ESP32 to play the audio received via Bluetooth.
                Use your phone's Bluetooth connection to ESP32, 
                then open the music APP and play the music, 
                and you'll hear ESP32 play the phone's music
  Auther      : www.freenove.com
  Modification: 2021/12/02
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

#define CONFIG_CLASSIC_BT_ENABLED
#define CONFIG_BT_ENABLED 
#define CONFIG_BLUEDROID_ENABLED

BluetoothSerial SerialBT;

static void bt_av_hdl_stack_evt(uint16_t event, void *p_param){
  if(event==0) {
    /* initialize A2DP sink */
    esp_a2d_register_callback(&bt_app_a2d_cb);
    esp_a2d_sink_register_data_callback(bt_app_a2d_data_cb);
    esp_a2d_sink_init();
    /* initialize AVRCP controller */
    esp_avrc_ct_init();
    esp_avrc_ct_register_callback(bt_app_rc_ct_cb);
    /* set discoverable and connectable mode, wait to be connected */
    esp_bt_gap_set_scan_mode(ESP_BT_CONNECTABLE, ESP_BT_GENERAL_DISCOVERABLE);
  }
}

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
  i2s_config.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_PDM);
  i2s_config.bits_per_sample = I2S_BITS_PER_SAMPLE_24BIT;
  i2s_config.sample_rate = 44100;
  i2s_config.channel_format = I2S_CHANNEL_FMT_ALL_LEFT;  //GPIO25|GPIO26 output left channel
  i2s_config.communication_format = I2S_COMM_FORMAT_PCM;
  i2s_config.intr_alloc_flags = 0;
  i2s_config.dma_buf_count = 6;
  i2s_config.dma_buf_len = 60;
  i2s_config.tx_desc_auto_clear = true;
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN);
  i2s_set_pin(I2S_NUM_0, NULL);

  esp_bluedroid_init();
  esp_bluedroid_enable();
  bt_app_task_start_up();
  bt_app_work_dispatch(bt_av_hdl_stack_evt, 0, NULL, 0, NULL);
  Serial.println("Please use your bluetooth device to connect the ESP32");
}

void loop(){
  ;  
}
