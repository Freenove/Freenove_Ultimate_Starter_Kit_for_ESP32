##############################################################################
Chapter 12 Photoresistor & LED
##############################################################################

In this chapter, we will learn how to use a photoresistor.

Project 12.1 NightLamp
***************************************

A photoresistor is very sensitive to the amount of light present. We can take advantage of the characteristic to make a nightlight with the following function: when the ambient light is less (darker environment) the LED will automatically become brighter to compensate and when the ambient light is greater (brighter environment) the LED will automatically dim to compensate.

Component List
======================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +------------------------------------+-------------------------+
    | ESP32-WROVER x1                    | GPIO Extension Board x1 |
    |                                    |                         |
    | |Chapter01_00|                     | |Chapter01_01|          |
    +------------------------------------+-------------------------+
    | Breadboard x1                                                |
    |                                                              |
    | |Chapter01_02|                                               |
    +-----------------+--------------------------------------------+
    | LED x1          | Jumper M/M x4                              |
    |                 |                                            |
    | |Chapter01_03|  | |Chapter01_05|                             |
    +-----------------+------------------+-------------------------+
    |Photoresistor x1 | Resistor 220Ω x1 | Resistor 10kΩ x2        |
    |                 |                  |                         |
    | |Chapter12_06|  | |Chapter01_04|   | |Chapter07_04|          |
    +-----------------+------------------+-------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter01_03| image:: ../_static/imgs/1_LED/Chapter01_03.png
.. |Chapter01_04| image:: ../_static/imgs/1_LED/Chapter01_04.png
.. |Chapter07_04| image:: ../_static/imgs/7_Buzzer/Chapter07_04.png
.. |Chapter12_06| image:: ../_static/imgs/12_Photoresistor_&_LED/Chapter12_06.png
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png

Component knowledge
=============================

Photoresistor 
----------------------------

A photoresistor is simply a light sensitive resistor. It is an active component that decreases resistance with respect to receiving luminosity (light) on the component's light sensitive surface. A photoresistor's resistance value will change in proportion to the ambient light detected. With this characteristic, we can use a photoresistor to detect light intensity. The photoresistor and its electronic symbol are as follows.

.. image:: ../_static/imgs/12_Photoresistor_&_LED/Chapter12_00.png
    :align: center

The circuit below is used to detect the change of a photoresistor's resistance value:

.. image:: ../_static/imgs/12_Photoresistor_&_LED/Chapter12_01.png
    :align: center

In the above circuit, when a photoresistor's resistance vale changes due to a change in light intensity, the voltage between the photoresistor and resistor R1 will also change. Therefore, the intensity of the light can be obtained by measuring this voltage.

Circuit
===============================

The circuit of this project is similar to project Soft Light. The only difference is that the input signal is changed from a potentiometer to a combination of a photoresistor and a resistor.

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter12_02|
   * -  **Hardware connection**
   * -  :combo:`red font-bolder:If you need any support, please contact us via:` support@freenove.com
        
        |Chapter12_03|

.. |Chapter12_02| image:: ../_static/imgs/12_Photoresistor_&_LED/Chapter12_02.png    
.. |Chapter12_03| image:: ../_static/imgs/12_Photoresistor_&_LED/Chapter12_03.png  

Code
=============================

Move the program folder **"Freenove_Ultimate_Starter_Kit_for_ESP32/Python/Python_Codes"** to disk(D) in advance with the path of **"D:/Micropython_Codes"**.

Codes of this project is logically the same as the project Soft Light.

12.1_Nightlamp
-----------------------------

.. image:: ../_static/imgs/12_Photoresistor_&_LED/Chapter12_05.png
    :align: center

Click "Run current script". Cover the photoresistor with your hands or illuminate it with lights, the brightness of LEDs will change.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/12.1_NightLamp/NightLamp.py
    :linenos:
    :language: python
    :lines: 1-16
    :dedent: