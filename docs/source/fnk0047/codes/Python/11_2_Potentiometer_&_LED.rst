


Project Soft Colorful Light 
*****************************************

In this project, 3 potentiometers are used to control the RGB LED and in principle it is the same as the Soft Light project. Namely, read the voltage value of the potentiometer and then convert it to PWM used to control LED brightness. Difference is that the original project only controlled one LED, but this project required (3) RGB LEDs.

+------------------------------------+----------------------------------------------------+
| ESP32-WROVER x1                    | GPIO Extension Board x1                            |
|                                    |                                                    |
| |Chapter01_00|                     | |Chapter01_01|                                     |
+------------------------------------+----------------------------------------------------+
| Breadboard x1                                                                           |
|                                                                                         |
| |Chapter01_02|                                                                          |
+-----------------+------------------+------------------------+---------------------------+
| RGBLED x1       | Resistor 220Ω x3 | Jumper M/M x13         | Rotary potentiometer x3   |
|                 |                  |                        |                           |
| |Chapter11_03|  | |Chapter01_04|   | |Chapter01_05|         | |Chapter09_00|            |
+-----------------+------------------+------------------------+---------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter01_04| image:: ../_static/imgs/1_LED/Chapter01_04.png    
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png
.. |Chapter09_00| image:: ../_static/imgs/9_AD_DA_Converter/Chapter09_00.png
.. |Chapter11_03| image:: ../_static/imgs/11_Potentiometer_&_LED/Chapter11_03.png

Circuit
=============================================

.. list-table:: 
   :width: 100%
   :header-rows: 1 
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter11_04|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter11_05|

.. |Chapter11_04| image:: ../_static/imgs/11_Potentiometer_&_LED/Chapter11_04.png    
.. |Chapter11_05| image:: ../_static/imgs/11_Potentiometer_&_LED/Chapter11_05.png  

Code
============================================

Open "Thonny", click "This computer"  ->  "D:"  ->  "Micropython_Codes"  ->  "11.2_Soft_Colorful_Light" and double click "Soft_Colorful_Light.py". 

Soft_Colorful_Light
------------------------------------------

Click "Run current script" and control the change of RGBLED color by rotating the handles of three rotary potentiometers.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/11.2_Soft_Colorful_Light/Soft_Colorful_Light.py
    :language: python
    :dedent:

In the code, read the ADC value of 3 potentiometers and map it into PWM duty cycle to control the control 3 LEDs with different color of RGBLED, respectively.


Project Soft Rainbow Light
********************************************

In this project, we use potentiometer to control Freenove 8 RGB LED Module.

Component List
=====================================

+------------------------------------+----------------------------------------------------+
| ESP32-WROVER x1                    | GPIO Extension Board x1                            |
|                                    |                                                    |
| |Chapter01_00|                     | |Chapter01_01|                                     |
+------------------------------------+----------------------------------------------------+
| Breadboard x1                                                                           |
|                                                                                         |
| |Chapter01_02|                                                                          |
+------------------------------------+----------------------------------------------------+
| Freenove 8 RGB LED Module x1       | Jumper F/M x3 Jumper M/M x3                        |
|                                    |                                                    |
| |Chapter11_08|                     |  |Chapter11_07|                                    |
+------------------------------------+----------------------------------------------------+

.. |Chapter11_07| image:: ../_static/imgs/11_Potentiometer_&_LED/Chapter11_07.png
.. |Chapter11_08| image:: ../_static/imgs/11_Potentiometer_&_LED/Chapter11_08.png

Code
=====================================

Open "Thonny", click "This computer"  ->  "D:"  ->  "Micropython_Codes"  ->  "11.3_Soft_Rainbow_Light" and double click "Soft_Rainbow_Light.py". 

11.3_Soft_Rainbow_Light
--------------------------------------

.. image:: ../_static/imgs/11_Potentiometer_&_LED/Chapter11_12.png
    :align: center

Click "Run current script". Rotate the handle of potentiometer and the color of the lights will change.

.. image:: ../_static/imgs/11_Potentiometer_&_LED/Chapter11_13.png
    :align: center

:red:`If you have any concerns, please contact us via:` support@freenove.com

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/11.3_Soft_Rainbow_Light/Soft_Rainbow_Light.py
    :language: python
    :dedent:

The logic of the code is basically the same as the previous project :ref:`Rainbow Light <Rainbow_Light>`. The difference is that in this code, the starting point of the color is controlled by the potentiometer.