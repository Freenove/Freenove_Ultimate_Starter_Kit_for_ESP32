.. _LED_BAR:

##############################################################################
Chapter 15 74HC595 & LED Bar Graph
##############################################################################

We have used LED bar graph to make a flowing water light, in which 10 GPIO ports of ESP32 is occupied. More GPIO ports mean that more peripherals can be connected to ESP32, so GPIO resource is very precious. Can we make flowing water light with less GPIO? In this chapter, we will learn a component, 74HC595, which can achieve the target.

Project 15.1 Flowing Water Light
*********************************************

Now let's learn how to use the 74HC595 IC chip to make a flowing water light using less GPIO.

Component List
==============================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +------------------------------------+----------------------------------------------------+
    | ESP32-WROVER x1                    | GPIO Extension Board x1                            |
    |                                    |                                                    |
    | |Chapter01_00|                     | |Chapter01_01|                                     |
    +------------------------------------+----------------------------------------------------+
    | Breadboard x1                                                                           |
    |                                                                                         |
    | |Chapter01_02|                                                                          |
    +-----------------+------------------+------------------------+---------------------------+
    | 74HC595         | Resistor 220Ω x8 | Jumper M/M x15         | LED Bar Graph x1          |
    |                 |                  |                        |                           |
    | |Chapter15_00|  | |Chapter01_04|   | |Chapter01_05|         | |Chapter15_01|            |
    +-----------------+------------------+------------------------+---------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter15_00| image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_00.png 
.. |Chapter01_04| image:: ../_static/imgs/1_LED/Chapter01_04.png    
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png
.. |Chapter15_01| image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_01.png

Related knowledge
=======================================

74HC595
----------------------------------------

A 74HC595 chip is used to convert serial data into parallel data. A 74HC595 chip can convert the serial data of one byte into 8 bits, and send its corresponding level to each of the 8 ports correspondingly. With this characteristic, the 74HC595 chip can be used to expand the IO ports of a ESP32. At least 3 ports are required to control the 8 ports of the 74HC595 chip.

.. image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_02.png
    :align: center

The ports of the 74HC595 chip are described as follows:

.. table::
    :width: 80%
    :align: center
    :class: zebra
    
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | Pin name | GPIO number | Description                                                                                           |
    +==========+=============+=======================================================================================================+
    | Q0-Q7    | 15, 1-7     | Parallel data output                                                                                  |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | VCC      | 16          | The positive electrode of power supply, the voltage is 2~6V                                           |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | GND      | 8           | The negative electrode of power supply                                                                |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | DS       | 14          | Serial data Input                                                                                     |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    |          |             | Enable output,                                                                                        |
    |          |             |                                                                                                       |
    | OE       | 13          | When this pin is in high level, Q0-Q7 is in high resistance state                                     |
    |          |             |                                                                                                       |
    |          |             | When this pin is in low level, Q0-Q7 is in output mode                                                |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | ST_CP    | 12          | Parallel Update Output: when its electrical level is rising, it will update the parallel data output. |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | SH_CP    | 11          | Serial shift clock: when its electrical level is rising, serial data input register will do a shift.  |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | MR       | 10          | Remove shift register: When this pin is in low level, the content in shift register will be cleared.  |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+
    | Q7'      | 9           | Serial data output: it can be connected to more 74HC595 in series.                                    |
    +----------+-------------+-------------------------------------------------------------------------------------------------------+

For more detail, please refer to the datasheet on the 74HC595 chip.

Circuit
=========================================

The circuit of this project is similar to the one in the last chapter. The only difference is that the photoresistor is replaced by the thermistor.

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter15_03|
   * -  **Hardware connection**
   * -  :combo:`red font-bolder:If you need any support, please contact us via:` support@freenove.com
        
        |Chapter15_04|

.. |Chapter15_03| image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_03.png    
.. |Chapter15_04| image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_04.png  

Sketch
=========================================

In this project, we will make a flowing water light with a 74HC595 chip to learn about its functions.

Sketch_15.1_FlowingLight2
-----------------------------------

.. image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_05.png
    :align: center

Download the code to ESP32-WROVER. You will see that LED bar graph starts with the flowing water pattern flashing from left to right and then back from right to left.

:combo:`red font-bolder:If you have any concerns, please contact us via:` support@freenove.com

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_15.1_FlowingLight02/Sketch_15.1_FlowingLight02.ino
    :linenos: 
    :language: c
    :dedent:

In the code, we configure three pins to control the 74HC595 chip and define a one-byte variable to control the state of the 8 LEDs (in the LED bar graph Module) through the 8 bits of the variable. The LEDs light ON when the corresponding bit is 1. If the variable is assigned to 0x01, that is 00000001 in binary, there will be only one LED ON. 

.. code-block:: c
    :linenos:

    x=0x01;

In the loop(), use "for" loop to send x to 74HC595 output pin to control the LED. In "for" loop, x will shift one bit to the LEFT in one cycle, then when data of x is sent to 74HC595, the LED that is turned ON will move one bit to the LEFT once.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_15.1_FlowingLight02/Sketch_15.1_FlowingLight02.ino
    :linenos: 
    :language: c
    :lines: 30-34
    :dedent:

In second "for" loop, the situation is the same. The difference is that x is shift from 0x80 to the RIGHT in order.

The subfunction writeTo595() is used to write data to 74HC595 and immediately output on the port of 74HC595.

Reference
----------------------------------

.. py:function:: << operator

    "<<" is the left shift operator, which can make all bits of 1 byte shift by several bits to the left (high) direction and add 0 on the right (low). For example, shift binary 00000001 by 1 bit to left:
    
    byte x = 1 << 1;

    .. image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_06.png
        :align: center

    The result of x is 2(binary 00000010)

    .. image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_07.png
        :align: center
    
    There is another similar operator" >>". For example, shift binary 00000001 by 1 bit to right:
        
        byte x = 1 >> 1;

    .. image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_08.png
        :align: center
    
    The result of x is 0(00000000).

    .. image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_09.png
        :align: center
    
    X <<= 1 is equivalent to x = x << 1 and x >>= 1 is equivalent to x = x >> 1

.. py:function:: void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

    This is used to shift an 8-bit data value in with the data appearing on the dataPin and the clock being sent out on the clockPin. Order is as above. The data is sampled after the cPin goes high. (So clockPin high, sample data, clockPin low, repeat for 8 bits) The 8-bit value is returned by the function.

    **Parameters**

    dataPin: the pin on which to output each bit. Allowed data types: int.
    
    clockPin: the pin to toggle once the dataPin has been set to the correct value. Allowed data types: int.
    
    bitOrder: which order to shift out the bits; either MSBFIRST or LSBFIRST. (Most Significant Bit First, or, Least Significant Bit First).
    
    value: the data to shift out. Allowed data types: byte.

For more details about shift function, please refer to: https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/ 