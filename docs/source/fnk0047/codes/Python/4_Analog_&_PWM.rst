##############################################################################
Chapter Analog & PWM
##############################################################################

In previous study, we have known that one button has two states: pressed and released, and LED has light-on/off state, then how to enter a middle state?  How to output an intermediate state to let LED "semi bright"?  That's what we're going to learn.

First, let's learn how to control the brightness of a LED.

Project Breathing LED
*************************************

Breathing light, that is, LED is turned from off to on gradually, and gradually from on to off, just like "breathing". So, how to control the brightness of a LED?  We will use PWM to achieve this target.

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
    +-----------------+------------------+-------------------------+
    | LED x1          | Resistor 220Ω x1 | Jumper M/M x2           |
    |                 |                  |                         |
    | |Chapter01_03|  | |Chapter01_04|   | |Chapter01_05|          |
    +-----------------+------------------+-------------------------+
  
.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png    
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png    
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png    
.. |Chapter01_03| image:: ../_static/imgs/1_LED/Chapter01_03.png    
.. |Chapter01_04| image:: ../_static/imgs/1_LED/Chapter01_04.png    
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png    

Related knowledge
=======================================

Analog & Digital
---------------------------------------

An analog signal is a continuous signal in both time and value. On the contrary, a digital signal or discrete-time signal is a time series consisting of a sequence of quantities. Most signals in life are analog signals. A familiar example of an analog signal would be how the temperature throughout the day is continuously changing and could not suddenly change instantaneously from 0℃ to 10℃. However, digital signals can instantaneously change in value. This change is expressed in numbers as 1 and 0 (the basis of binary code). 

Their differences can more easily be seen when compared when graphed as below.

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_00.png
    :align: center

In practical application, we often use binary as the digital signal, that is a series of 0's and 1's. Since a binary signal only has two values (0 or 1), it has great stability and reliability. Lastly, both analog and digital signals can be converted into the other.

PWM
----------------------------------------

PWM, Pulse-Width Modulation, is a very effective method for using digital signals to control analog circuits. Common processors cannot directly output analog signals. PWM technology makes it very convenient to achieve this conversion (translation of digital to analog signals)

PWM technology uses digital pins to send certain frequencies of square waves, that is, the output of high levels and low levels, which alternately last for a while. The total time for each set of high levels and low levels is generally fixed, which is called the period (Note: the reciprocal of the period is frequency). The time of high level outputs are generally called "pulse width", and the duty cycle is the percentage of the ratio of pulse duration, or pulse width (PW) to the total period (T) of the waveform.

The longer the outputs of high levels last, the longer the duty cycle and the higher the corresponding voltage in the analog signal will be. The following figures show how the analog signal voltages vary between 0V-5V (high level is 5V) corresponding to the pulse width 0%-100%:

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_01.png
    :align: center

The longer the PWM duty cycle is, the higher the output power will be. Now that we understand this relationship, we can use PWM to control the brightness of a LED or the speed of DC motor and so on. 

It is evident from the above that PWM is not real analog, and the effective value of the voltage is equivalent to the corresponding analog. Therefore, we can control the output power of the LED and other output modules to achieve different effects.

ESP32 and PWM 
------------------------------------------

The ESP32 PWM controller has 8 independent channels, each of which can independently control frequency, duty cycle, and even accuracy. Unlike traditional PWM pins, the PWM output pins of ESP32 are configurable and they can be configured to PWM.

Circuit
========================================

This circuit is the same as the one in engineering Blink.

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter04_02|
   * -  **Hardware connection** 

   * -  :combo:`red font-bolder:If you need any support, please feel free to contact us via:` support@freenove.com

        |Chapter04_03|

.. |Chapter04_02| image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_02.png    
.. |Chapter04_03| image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_03.png  

Code
===================================

This project is designed to make PWM output GPIO2 with pulse width increasing from 0% to 100%, and then reducing from 100% to 0% gradually.

Move the program folder "Freenove_Ultimate_Starter_Kit_for_ESP32/Python/Python_Codes" to disk(D) in advance with the path of "D:/Micropython_Codes".

Open "Thonny", click"This computer"  ->  "D:"  ->  "Micropython_Codes"  ->  "04.1_BreatheLight" and double click "BreatheLight.py". 

BreatheLight
------------------------------------

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_08.png
    :align: center

Click "Run current script", and you'll see that LED is turned from ON to OFF and then back from OFF to ON gradually like breathing.

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_09.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.1_BreatheLight/BreatheLight.py
    :linenos:
    :language: python
    :dedent:

The way that the ESP32 PWM pins output is different from traditionally controllers. It can change frequency and duty cycle by configuring PWM's parameters at the initialization stage. Define GPIO2's output frequency as 10000Hz, and assign them to PWM.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.1_BreatheLight/BreatheLight.py
    :linenos:
    :language: python
    :lines: 4-4
    :dedent:

The range of duty cycle is 0-1023, so we use the first for loop to control PWM to change the duty cycle value, making PWM output 0% -100%; Use the second for loop to make PWM output 100%-0%.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.1_BreatheLight/BreatheLight.py
    :linenos:
    :language: python
    :lines: 7-13
    :dedent:

Each time PWM is used, the hardware Timer will be turned ON to cooperate it. Therefore, after each use of PWM, deinit() needs to be called to turned OFF the timer. Otherwise, the PWM may fail to work next time.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.1_BreatheLight/BreatheLight.py
    :linenos:
    :language: python
    :lines: 15-15
    :dedent:

Reference
---------------------------------

.. py:function:: Class PWM(pin, freq)	
    
    Before each use of PWM module, please add the statement "from machine import PWM" to the top of the python file.

    **pin:** PWM pins are supported, such as Pin(0)、Pin(2)、Pin(4)、Pin(5)、Pin(10)、Pin(12~19)、Pin(21)、Pin(22)、Pin(23)、Pin(25~27).
    
    **freq:** Output frequency, with the range of 0-78125 Hz
    
    **duty:** Duty cycle, with the range of 0-1023.
    
    **PWM.init(freq, duty):** Initialize PWM, parameters are the same as above.
    
    **PWM.freq([freq_val]):** When there is no parameter, the function obtains and returns PWM frequency; When parameters are set, the function is used to set PWM frequency and returns nothing.
    
    **PWM.duty([duty_val]):** When there is no parameter, the function obtains and returns PWM duty cycle; When parameters are set, the function is used to set PWM duty cycle.
    
    **PWM.deinit():** Turn OFF PWM.

Project Meteor Flowing Light
******************************************

After learning about PWM, we can use it to control LED Bar Graph and realize a cooler Flowing Light.

Component List
=====================================

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
    +-----------------+------------------+-------------------------+
    |Jumper M/M x10   | Resistor 220Ω x10| LED bar graph x1        |
    |                 |                  |                         |
    | |Chapter01_05|  | |Chapter01_04|   | |Chapter03_00|          |
    +-----------------+------------------+-------------------------+

.. |Chapter03_00| image:: ../_static/imgs/3_LED_Bar/Chapter03_00.png

Circuit
===================================

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter04_10|
   * -  **Hardware connection** 

   * -  :combo:`red font-bolder:If you need any support, please feel free to contact us via:` support@freenove.com

        |Chapter04_11|

        :combo:`red font-bolder:If LED bar does not work, try to rotate it for 180°. The label is random.`

.. |Chapter04_10| image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_10.png
.. |Chapter04_11| image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_11.png

Code
================================

Flowing Light with tail was implemented with PWM.

Open "Thonny", click "This computer"  ->  "D:"  ->  "Micropython_Codes"  ->  "04.2_FlowingLight". Select"pwm.py", right click to select "Upload to /", wait for "pwm.py" to be uploaded to ESP32-WROVER and then double click "FlowingLight.py" 

FlowingLight
-------------------------------

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_12.png
    :align: center

Click "Run current script", and LED Bar Graph will gradually light up and out from left to right, then light up and out from right to left.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.2_FlowingLight/FlowingLight.py
    :linenos:
    :language: python
    :dedent:

Import the object myPWM from pwm.py and set corresponding pins for PWM channel.

.. code-block:: python
    :linenos:

    from pwm import myPWM
    ......
    mypwm = myPWM(15,2,0,4,5,18,19,21)

First we defined 8 GPIO, 8 PWM channels, and 24 pulse width values.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.2_FlowingLight/FlowingLight.py
    :linenos:
    :language: python
    :lines: 5-7
    :dedent:

Call ledcWrite()to set duty cycle dutys[i+j] for the chns[j] channel of PWM.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.2_FlowingLight/FlowingLight.py
    :linenos:
    :language: python
    :lines: 14-14
    :dedent:

Close the PWM of the object myPWM.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.2_FlowingLight/FlowingLight.py
    :linenos:
    :language: python
    :lines: 22-22
    :dedent:

In the code, a nesting of two for loops are used to achieve this effect. 

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/04.2_FlowingLight/FlowingLight.py
    :linenos:
    :language: python
    :lines: 12-20
    :dedent:

In the main function, a nested for loop is used to control the pulse width of the PWM. Every time i in the first for loop increases by 1, the LED Bar Graph will move one grid, and gradually change according to the value in the array dutys. As shown in the following table, the value in the second row is the value of the array dutys, and the 8 green grids in each row below represent the 8 LEDs on the LED Bar Graph. Each time i increases by 1, the value of the LED Bar Graph will move to the right by one grid, and when it reaches the end, it will move from the end to the starting point, achieving the desired effect.

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_13.png
    :align: center

How to import a custom python module
--------------------------------------------

Each Python file, as long as it's stored on the file system of ESP32, is a module. To import a custom module, the module file needs to be located in the MicroPython environment variable path or in the same path as the currently running program.

First, customize a python module "custom.py". Create a new py file and name it "custom.py". Write code to it and save it to ESP32.

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_14.png
    :align: center

Second, import custom module "custom" to main.py

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_15.png
    :align: center