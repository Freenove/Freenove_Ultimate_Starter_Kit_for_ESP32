/**********************************************************************
  Filename    : FlowingLight2
  Description : More cool flowing light.
  Auther      : www.freenove.com
  Modification: 2024/06/18
**********************************************************************/
const byte ledPins[] = {15, 2, 0, 4, 5, 18, 19, 21, 22, 23};    //define led pins
const byte chns[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};             //define the pwm channels
const int dutys[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     1023, 512, 256, 128, 64, 32, 16, 8, 4, 2,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    };      //define the pwm dutys
int ledCounts;    
int delayTimes = 50;  //flowing speed ,the smaller, the faster
void setup() {
  ledCounts = sizeof(ledPins);    //get the led counts
  for (int i = 0; i < ledCounts; i++) {   //setup the pwm channels
    ledcAttachChannel(ledPins[i], 1000, 10, chns[i]);
  }
}

void loop() {
  for (int i = 0; i < 20; i++) {        //flowing one side to other side
    for (int j = 0; j < ledCounts; j++) {
      ledcWrite(ledPins[j], dutys[i + j]);
    }
    delay(delayTimes);
  }
  for (int i = 0; i < 20; i++) {      //flowing one side to other side
    for (int j = ledCounts - 1; j > -1; j--) {
      ledcWrite(ledPins[j], dutys[i + (ledCounts - 1 - j)]);
    }
    delay(delayTimes);
  }
}
