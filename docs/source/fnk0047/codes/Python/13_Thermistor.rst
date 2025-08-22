##############################################################################
Chapter 13 Thermistor
##############################################################################

In this chapter, we will learn about thermistors which are another kind of resistor

Project 13.1 Thermometer
******************************************

A thermistor is a type of resistor whose resistance value is dependent on temperature and changes in temperature. Therefore, we can take advantage of this characteristic to make a thermometer.

Component List
====================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +------------------------------------+------------------------+
    | ESP32-WROVER x1                    | GPIO Extension Board x1|
    |                                    |                        |
    | |Chapter01_00|                     | |Chapter01_01|         |
    +------------------------------------+------------------------+
    | Breadboard x1                                               |
    |                                                             |
    | |Chapter01_02|                                              |
    +-----------------+------------------+------------------------+
    | Thermistor x1   | Resistor 10kΩ x1 | Jumper M/M x3          |
    |                 |                  |                        |
    | |Chapter13_00|  | |Chapter07_04|   | |Chapter01_05|         |
    +-----------------+------------------+------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter13_00| image:: ../_static/imgs/13_Thermistor/Chapter13_00.png 
.. |Chapter07_04| image:: ../_static/imgs/7_Buzzer/Chapter07_04.png   
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png
.. |Chapter09_00| image:: ../_static/imgs/9_AD_DA_Converter/Chapter09_00.png

Component knowledge
==================================

Thermistor
----------------------------------

A thermistor is a temperature sensitive resistor. When it senses a change in temperature, the resistance of the thermistor will change. We can take advantage of this characteristic by using a thermistor to detect temperature intensity. A thermistor and its electronic symbol are shown below.

.. image:: ../_static/imgs/13_Thermistor/Chapter13_01.png
    :align: center

The relationship between resistance value and temperature of a thermistor is:

.. image:: ../_static/imgs/13_Thermistor/Chapter13_02.png
    :align: center

Where:

    Rt is the thermistor resistance under T2 temperature;

    R is the nominal resistance of thermistor under T1 temperature;

    EXP[n] is nth power of E;

    B is for thermal index;

    T1, T2 is Kelvin temperature (absolute temperature). Kelvin temperature=273.15 + Celsius temperature. 

    For the parameters of the thermistor, we use: B=3950, R=10k, T1=25.

    The circuit connection method of the thermistor is similar to photoresistor, as the following:

.. image:: ../_static/imgs/13_Thermistor/Chapter13_03.png
    :align: center

We can use the value measured by the ADC converter to obtain the resistance value of thermistor, and then we can use the formula to obtain the temperature value.

Therefore, the temperature formula can be derived as:

.. image:: ../_static/imgs/13_Thermistor/Chapter13_04.png
    :align: center

Circuit
=========================================

The circuit of this project is similar to the one in the last chapter. The only difference is that the photoresistor is replaced by the thermistor.

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter13_05|
   * -  **Hardware connection**
   * -  :combo:`red font-bolder:If you need any support, please contact us via:` support@freenove.com

        |Chapter13_06|

.. |Chapter13_05| image:: ../_static/imgs/13_Thermistor/Chapter13_05.png
.. |Chapter13_06| image:: ../_static/imgs/13_Thermistor/Chapter13_06.png

Code
====================================

Move the program folder **"Freenove_Ultimate_Starter_Kit_for_ESP32/Python/Python_Codes"** to disk(D) in advance with the path of **"D:/Micropython_Codes"**.

Open "Thonny", click "This computer" **->** "D:" **->** "Micropython_Codes" **->** "13.1_Thermometer" and double click "Thermometer.py". 

13.1_Thermometer
--------------------------------------

.. image:: ../_static/imgs/13_Thermistor/Chapter13_09.png
    :align: center

Click "Run current script" and "Shell" will constantly display the current ADC value, voltage value and temperature value. Try to "pinch" the thermistor (without touching the leads) with your index finger and thumb for a brief time, you should see that the temperature value increases.

If you have any concerns, please contact us via: support@freenove.com

.. image:: ../_static/imgs/13_Thermistor/Chapter13_10.png
    :align: center

The following is the code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/13.1_Thermometer/Thermometer.py
    :linenos:
    :language: python
    :lines: 1-18
    :dedent:

In the code, the ADC value of ADC module A0 port is read, and then it calculates the voltage and the resistance of Thermistor according to Ohms Law. Finally, it calculates the temperature sensed by the Thermistor, according to the formula. 