/**********************************************************************
  Filename    : Thermomter
  Description : Making a thermometer by thermistor (Using IDF_SDK Function).
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include "esp_adc_cal.h"
#define PIN_ANALOG_IN   4           // A10, ADC2_CHANNEL_0

#define DEFAULT_VREF    1100        //Default vref
#define NO_OF_SAMPLES   64          //Multisampling

adc_channel_t channel = ADC_CHANNEL_0;      // ADC1:GPIO36, ADC2:GPIO4
adc_unit_t unit = ADC_UNIT_2;               // ADC2
adc_atten_t atten = ADC_ATTEN_DB_11;        // Full scale 0-3.9V, precision range 150mV-2450mV

esp_adc_cal_characteristics_t *adc_chars;

esp_adc_cal_value_t val_type;

void setup() {
    Serial.begin(115200);
    if (unit == ADC_UNIT_1) {
        adc1_config_width(ADC_WIDTH_BIT_12);
        adc1_config_channel_atten((adc1_channel_t)channel, atten);
    }
    else {
        adc2_config_channel_atten((adc2_channel_t)channel, atten);
    }

    //Characterize ADC
    adc_chars = (esp_adc_cal_characteristics_t*)calloc(1, sizeof(esp_adc_cal_characteristics_t));
    esp_adc_cal_value_t val_type = esp_adc_cal_characterize(unit, atten, ADC_WIDTH_BIT_12, DEFAULT_VREF, adc_chars);

}

void loop() {
    uint32_t adc_reading = 0;
    //Multisampling
    for (int i = 0; i < NO_OF_SAMPLES; i++) {
        if (unit == ADC_UNIT_1) {
            adc_reading += adc1_get_raw((adc1_channel_t)channel);
        }
        else {
            int raw;
            adc2_get_raw((adc2_channel_t)channel, ADC_WIDTH_BIT_12, &raw);
            adc_reading += raw;
        }
    }
    adc_reading /= NO_OF_SAMPLES;
    //Convert adc_reading to voltage in mV
    uint32_t voltage = esp_adc_cal_raw_to_voltage(adc_reading, adc_chars);
    //printf("Raw: %d\tVoltage: %dmV\n", adc_reading, voltage);

    double vol = voltage / 1000.0f;
    double Rt = 10 * vol / (3.3 - vol); //calculate resistance value of thermistor
    double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0); //calculate temperature (Kelvin)
    double tempC = tempK - 273.15;     //calculate temperature (Celsius)
    Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature : %.2fC\n", adc_reading, vol, tempC);

    delay(1000);
}
