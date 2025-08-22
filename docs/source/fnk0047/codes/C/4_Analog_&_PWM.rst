##############################################################################
Chapter 4 Analog & PWM
##############################################################################

In previous study, we have known that one button has two states: pressed and released, and LED has light-on/off state, then how to enter a middle state?  How to output an intermediate state to let LED "semi bright"?  That's what we're going to learn.

First, let's learn how to control the brightness of a LED.

Project 4.1 Breathing LED
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

On ESP32, the LEDC(PWM) controller has 16 separate channels, each of which can independently control frequency, duty cycle, and even accuracy. Unlike traditional PWM pins, the PWM output pins of ESP32 are configurable, with one or more PWM output pins per channel. The relationship between the maximum frequency and bit precision is shown in the following formula, where the maximum value of bit is 31.

.. math::
   
   Freq_{\max} = \frac{80\,000\,000}{1 \ll bit}

For example, generate a PWM with an 8-bit precision (2^8=256. Values range from 0 to 255) with a maximum frequency of 80,000,000/256 = 312,500Hz.

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

Sketch
=================================

This project is designed to make PWM output GPIO2 with pulse width increasing from 0% to 100%, and then reducing from 100% to 0% gradually.

Sketch_04.1_BreathingLight
-----------------------------------

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_04.png
    :align: center

Download the code to ESP32-WROVER, and you'll see that LED is turned from on to off and then from off to on gradually like breathing.

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_05.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_04.1_BreathingLight/Sketch_04.1_BreathingLight.ino
    :linenos: 
    :language: c
    :dedent:

The PWM pin output mode of ESP32 is not the same as the traditional controller. It controls each parameter of PWM by controlling the PWM channel. Any number of GPIO can be connected with the PWM channel to output PWM. In ledcAttachChannal(), you first configure a PWM channel and set the frequency and precision. Then the GPIO is associated with the PWM channel.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_04.1_BreathingLight/Sketch_04.1_BreathingLight.ino
    :linenos: 
    :language: c
    :lines: 12-12
    :dedent:

In the loop(), There are two "for" loops. The first makes the ledPin output PWM from 0% to 100% and the second makes the ledPin output PWM from 100% to 0%. This allows the LED to gradually light and extinguish.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_04.1_BreathingLight/Sketch_04.1_BreathingLight.ino
    :linenos: 
    :language: c
    :lines: 16-23
    :dedent:

You can also adjust the rate of the state change of LED by changing the parameters of the delay() function in the "for" loop.

.. py:function:: bool ledcAttachChannel(uint8_t pin, uint32_t freq, uint8_t resolution, uint8_t channel)

    Set the pin, frequency and accuracy of a PWM channel.

    **Parameters**
    
    **pip** : The pin of PWM.
    
    **freq** : Frequency value of PWM.
    
    **resolution** : Pwm precision control bit.
    
    **channal**: channel index. Value range :0-15

.. py:function:: void ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);
.. py:function:: void ledcDetach(uint8_t pin);

    Bind/unbind a GPIO to a PWM channel.

.. py:function:: void ledcWrite(uint8_t pin, uint32_t duty);

    Writes the pulse width value to a PWM channel.

Project 4.2 Meteor Flowing Light
****************************************************

After learning about PWM, we can use it to control LED bar graph and realize a cooler flowing light.

The component list, circuit, and hardware are exactly consistent with the project Flowing Light.

Sketch
===============================================

Meteor flowing light will be implemented with PWM.

Sketch_04.2_FlowingLight2
--------------------------------------------------

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_06.png
    :align: center

Download the code to ESP32-WROVER, and LED bar graph will gradually light up and out from left to right, then light up and out from right to left.

The following is the program code: 

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_04.2_FlowingLight2/Sketch_04.2_FlowingLight2.ino
    :linenos: 
    :language: c
    :dedent:

First we defined 10 GPIO, 10 PWM channels, and 30 pulse width values.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_04.2_FlowingLight2/Sketch_04.2_FlowingLight2.ino
    :linenos: 
    :language: c
    :lines: 7-12
    :dedent:

In setup(), set the frequency of 10 PWM channels to 1000Hz, the accuracy to 10bits, and the maximum pulse width to 1023. Attach GPIO to these PWM channels.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_04.2_FlowingLight2/Sketch_04.2_FlowingLight2.ino
    :linenos: 
    :language: c
    :lines: 24-26
    :dedent:

In loop(), a nested for loop is used to control the pulse width of the PWM, and LED bar graph moves one grid after each 1 is added in the first for loop, gradually changing according to the values in the array duties. As shown in the table below, the value of the second row is the value in the array duties, and the 10 green squares in each row below represent the 10 LEDs on the LED bar graph. Every 1 is added to I, the value of the LED bar graph will move to the right by one grid, and when it reaches the end, it will move from the end to the starting point, achieving the desired effect.

.. image:: ../_static/imgs/4_Analog_&_PWM/Chapter04_07.png
    :align: center

In the code, two nested for loops are used to achieve this effect.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_04.2_FlowingLight2/Sketch_04.2_FlowingLight2.ino
    :linenos: 
    :language: c
    :lines: 23-34
    :dedent: