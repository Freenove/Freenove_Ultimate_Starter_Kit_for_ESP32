from machine import ADC,Pin,DAC
import time

adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)
dac =DAC(Pin(25))
try:
    while True:
        adcVal=adc.read()
        dacVal=adcVal//16
        voltage = adcVal / 4095.0 * 3.3
        dac.write(dacVal)
        print("ADC Val:",adcVal,"\tDACVal:",dacVal,"\tVoltage:",voltage,"V")
        time.sleep_ms(100)
except:
    adc.deinit()


# Please note that if an error occurs when running the code as follows, please press the RST button on the board.
# The DAC can only be initialized in the firmware and cannot be disabled. Therefore, using it for the second time will cause an abnormality.
# MPY: soft reboot
# Traceback (most recent call last):
#   File "<stdin>", line 7, in <module>
# OSError: (-259, 'ESP_ERR_INVALID_STATE')