/**********************************************************************
  Filename    : Camera Tcp Serrver
  Description : Users use Freenove's APP to view images from ESP32's camera
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include "esp_camera.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define CAMERA_MODEL_WROVER_KIT
#include "camera_pins.h"
#define LED_BUILT_IN  2

const char* ssid_Router     =   "********";
const char* password_Router =   "********";
const char *ssid_AP         =   "********";
const char *password_AP     =   "********";

WiFiServer server_Cmd(5000);
WiFiServer server_Camera(8000);
extern TaskHandle_t loopTaskHandle;

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  Serial.println();
  pinMode(LED_BUILT_IN, OUTPUT);
  cameraSetup();

  WiFi.softAP(ssid_AP, password_AP);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server_Camera.begin(8000);
  server_Cmd.begin(5000);
  /////////////////////////////////////////////////////
  WiFi.begin(ssid_Router, password_Router);
  Serial.print("Connecting ");
  Serial.print(ssid_Router);
  while (WiFi.isConnected() != true) {
    delay(500);
    Serial.print(".");
    //WiFi.begin(ssid_Router, password_Router);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  /////////////////////////////////////////////////////
  Serial.print("Camera Ready! Use '");
  Serial.print(WiFi.softAPIP());
  Serial.print(" or ");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect in Freenove app.");

  disableCore0WDT();
  xTaskCreateUniversal(loopTask_Cmd, "loopTask_Cmd", 8192, NULL, 1, &loopTaskHandle, 0);		//loopTask_Cmd uses core 0.
  xTaskCreateUniversal(loopTask_Blink, "loopTask_Blink", 8192, NULL, 1, &loopTaskHandle, 0);//loopTask_Blink uses core 0.
}
//task loop uses core 1.
void loop() {
  WiFiClient client = server_Camera.available();           // listen for incoming clients
  if (client) {                                            // if you get a client,
    Serial.println("Camera Server connected to a client.");// print a message out the serial port
    String currentLine = "";                               // make a String to hold incoming data from the client
    while (client.connected()) {                           // loop while the client's connected
      camera_fb_t * fb = NULL;
      while (client.connected()) {
        fb = esp_camera_fb_get();
        if (fb != NULL) {
          uint8_t slen[4];
          slen[0] = fb->len >> 0;
          slen[1] = fb->len >> 8;
          slen[2] = fb->len >> 16;
          slen[3] = fb->len >> 24;
          client.write(slen, 4);
          client.write(fb->buf, fb->len);
          esp_camera_fb_return(fb);
        }
        else {
          Serial.println("Camera Error");
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Camera Client Disconnected.");
  }
}

void loopTask_Cmd(void *pvParameters) {
  Serial.println("Task Cmd_Server is starting ... ");
  while (1) {
    WiFiClient client = server_Cmd.available(); // listen for incoming clients
    if (client) {                               // if you get a client,
      Serial.println("Command Server connected to a client.");// print a message out the serial port
      String currentLine = "";                 // make a String to hold incoming data from the client
      while (client.connected()) {             // loop while the client's connected
        if (client.available()) {              // if there's bytes to read from the client,
          char c = client.read();              // read a byte, then
          client.write(c);
          Serial.write(c);                     // print it out the serial monitor
          if (c == '\n') {                     // if the byte is a newline character
            currentLine = "";
          }
          else {
            currentLine += c;                  // add it to the end of the currentLine
          }
        }
      }
      // close the connection:
      client.stop();
      Serial.println("Command Client Disconnected.");
    }
  }
}
void loopTask_Blink(void *pvParameters) {
  Serial.println("Task Blink is starting ... ");
  while (1) {
    digitalWrite(LED_BUILT_IN, !digitalRead(LED_BUILT_IN));
    delay(1000);
  }
}

void cameraSetup() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  psramFound();
  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 10;
  config.fb_count = 1;

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
  Serial.println("Camera configuration complete!");
}
