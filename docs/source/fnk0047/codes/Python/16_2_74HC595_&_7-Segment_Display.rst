


Project 4-Digit 7-Segment Display
***************************************************

Now, let's try to control more digit 7-segment display

Component List
==========================================

+------------------------------------+----------------------------------------------------+
| ESP32-WROVER x1                    | GPIO Extension Board x1                            |
|                                    |                                                    |
| |Chapter01_00|                     | |Chapter01_01|                                     |
+------------------------------------+----------------------------------------------------+
| Breadboard x1                                                                           |
|                                                                                         |
| |Chapter01_02|                                                                          |
+-----------------+------------------+------------------------+---------------------------+
| 74HC595         | Resistor 220Ω x8 | Jumper M/M x15         | 7-segment display x1      |
|                 |                  |                        |                           |
| |Chapter15_00|  | |Chapter01_04|   | |Chapter01_05|         | |Chapter16_07|            |
+-----------------+------------------+------------------------+---------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter15_00| image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_00.png 
.. |Chapter01_04| image:: ../_static/imgs/1_LED/Chapter01_04.png    
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png
.. |Chapter16_07| image:: ../_static/imgs/16_74HC595_&_7-Segment_Display./Chapter16_07.png

Component knowledge
=============================================

4 Digit 7-Segment Display
---------------------------------------------

A 4 Digit 7-segment display integrates four 7-segment displays into one module, therefore it can display more characters. All of the LEDs contained have a common anode and individual cathodes. Its internal structure and pin designation diagram is shown below:

.. image:: ../_static/imgs/16_74HC595_&_7-Segment_Display/Chapter16_08.png
    :align: center

The internal electronic circuit is shown below, and all 8 LED cathode pins of each 7-segment display are connected together.

.. image:: ../_static/imgs/16_74HC595_&_7-Segment_Display/Chapter16_09.png
    :align: center

Display method of 4 digit 7-segment display is similar to 1 digit 7-segment display. The difference between them is that the 4-digit displays each Digit is visible in turn, one by one and not together. We need to first send high level to the common end of the first digit display, and send low level to the remaining three common ends, and then send content to 8 LED cathode pins of the first Digit Display. At this time, the first 7-segment display will show visible content and the remaining three will be OFF.

Similarly, the second, third and fourth 7-segment displays will show visible content in turn by scanning the display. Although the four number characters are displayed in turn separately, this process is so fast that it is imperceptible to the naked eye. This is due to the principle of optical afterglow effect and the vision persistence effect in human sight. This is how we can see all 4 number characters at the same time. However, if each number character is displayed for a longer period, you will be able to see that the number characters are displayed separately. 

Circuit
===============================================

.. list-table:: 
   :width: 100%
   :header-rows: 1 
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter16_10|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter16_11|

.. |Chapter16_10| image:: ../_static/imgs/16_74HC595_&_7-Segment_Display/Chapter16_10.png    
.. |Chapter16_11| image:: ../_static/imgs/16_74HC595_&_7-Segment_Display/Chapter16_11.png 

Code
===================================================

In this code, we use the 74HC595 IC Chip to control the 4-Digit 7-Segment Display, and use the dynamic scanning method to show the changing number characters.

Open "Thonny", click "This computer"  ->  "D:"  ->  "Micropython_Codes"  ->  "16.2_4_Digit_7_Segment_Display". Select "my74HC595.py", right click your mouse to select "Upload to /", wait for "my74HC595.py" to be uploaded to ESP32-WROVER and double click "4_Digit_7_Segment_Display.py". 

4_Digit_7_Segment_Display
---------------------------------------------------

.. image:: ../_static/imgs/16_74HC595_&_7-Segment_Display/Chapter16_15.png
    :align: center

Click "Run current script", and the Nixie tube display as shown in the image below.

.. image:: ../_static/imgs/16_74HC595_&_7-Segment_Display/Chapter16_13.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/16.2_4_Digit_7_Segment_Display/4_Digit_7_Segment_Display.py
    :language: python
    :dedent:

Import time, my74HC595 and Pin modules.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/16.2_4_Digit_7_Segment_Display/4_Digit_7_Segment_Display.py
    :language: python
    :lines: 1-3
    :dedent:

Define common anode pins for digital tubes and request a list to put character encodings in it.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/16.2_4_Digit_7_Segment_Display/4_Digit_7_Segment_Display.py
    :language: python
    :lines: 5-7
    :dedent:

Request an object to drive 74HC595 and associate pins with it.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/16.2_4_Digit_7_Segment_Display/4_Digit_7_Segment_Display.py
    :language: python
    :lines: 18-18
    :dedent:

Make the digital tube display "0123".

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/16.2_4_Digit_7_Segment_Display/4_Digit_7_Segment_Display.py
    :language: python
    :lines: 9-15
    :dedent: