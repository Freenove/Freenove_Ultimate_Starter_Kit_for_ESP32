##############################################################################
Chapter 14 Joystick
##############################################################################

In the previous chapter, we have learned how to use rotary potentiometer. Now, let's learn a new electronic module joystick which working on the same principle as rotary potentiometer.

Project 14.1 Joystick
***************************************

In this project, we will read the output data of a joystick and display it to the Terminal screen.

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
    | Joystick x1                        | Jumper M/M x3          |
    |                                    |                        |
    | |Chapter14_00|                     | |Chapter01_05|         |
    +-----------------+------------------+------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter07_04| image:: ../_static/imgs/7_Buzzer/Chapter07_04.png   
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png
.. |Chapter14_00| image:: ../_static/imgs/14_Joystick/Chapter14_00.png

Component knowledge
======================================

Joystick
--------------------------------------

A joystick is a kind of input sensor used with your fingers. You should be familiar with this concept already as they are widely used in gamepads and remote controls. It can receive input on two axes (Y and or X) at the same time (usually used to control direction on a two dimensional plane). And it also has a third direction capability by pressing down (Z axis/direction).

.. image:: ../_static/imgs/14_Joystick/Chapter14_01.png
    :align: center

This is accomplished by incorporating two rotary potentiometers inside the joystick Module at 90 degrees of each other, placed in such a manner as to detect shifts in direction in two directions simultaneously and with a push button switch in the "vertical" axis, which can detect when a User presses on the Joystick.

.. image:: ../_static/imgs/14_Joystick/Chapter14_02.png
    :align: center

When the joystick data is read, there are some differences between the axes: data of X and Y axes is analog, which needs to use the ADC. The data of the Z axis is digital, so you can directly use the GPIO to read this data or you have the option to use the ADC to read this.

Circuit
=========================================

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter14_03|
   * -  **Hardware connection**  
   * -  :combo:`red font-bolder:If you need any support, please contact us via:` support@freenove.com
        
        |Chapter14_04|

.. |Chapter14_03| image:: ../_static/imgs/14_Joystick/Chapter14_03.png    
.. |Chapter14_04| image:: ../_static/imgs/14_Joystick/Chapter14_04.png

Code
======================================

In this project's code, we will read the ADC values of X and Y axes of the Joystick, and read digital quality of the Z axis, then display these out in Terminal.

Move the program folder "**Freenove_Ultimate_Starter_Kit_for_ESP32/Python/Python_Codes**" to disk(D) in advance with the path of "**D:/Micropython_Codes**".

Open "Thonny", click "This computer" **->** "D:" **->** "Micropython_Codes" **->** "14.1_Joystick" and double click "Joystick.py". 

14.1_Joystick
--------------------------------------

.. image:: ../_static/imgs/14_Joystick/Chapter14_06.png
    :align: center

Click "Run current script". Shifting the Joystick or pressing it down will make the printed data in "Shell" change.

.. image:: ../_static/imgs/14_Joystick/Chapter14_07.png
    :align: center

The flowing is the code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/14.1_Joystick/Joystick.py
    :language: python
    :dedent:

Set the acquisition range of voltage of the two ADC channels to 0-3.3V, and the acquisition width of data to 0-4095.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/14.1_Joystick/Joystick.py
    :language: python
    :lines: 8-11
    :dedent:

In the code, configure Z_Pin to pull-up input mode. In loop(), use Read () to read the value of axes X and Y and use value() to read the value of axis Z, and then display them.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/14.1_Joystick/Joystick.py
    :language: python
    :lines: 14-14
    :dedent: