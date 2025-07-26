##############################################################################
Chapter Matrix Keypad
##############################################################################

Earlier we learned about a single Push Button Switch. In this chapter, we will learn about Matrix Keyboards, which integrates a number of Push Button Switches as Keys for the purposes of Input.

Project Matrix Keypad
*************************************

In this project, we will attempt to get every key code on the Matrix Keypad to work.

Component List
=====================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +------------------------------------+----------------------------+
    | ESP32-WROVER x1                    | GPIO Extension Board x1    |
    |                                    |                            |
    | |Chapter01_00|                     | |Chapter01_01|             |
    +------------------------------------+----------------------------+
    | Breadboard x1                                                   |
    |                                                                 |
    | |Chapter01_02|                                                  |
    +------------------------------------+----------------------------+
    | 4x4 Matrix Keypad x1               | Jumper M/M x8              |
    |                                    |                            |
    | |Chapter22_00|                     |  |Chapter01_05|            |
    +------------------------------------+----------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter22_00| image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_00.png
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png

Component knowledge
===========================================

4x4 Matrix Keypad
--------------------------------------------

A keypad matrix is a device that integrates a number of keys in one package. As is shown below, a 4x4 keypad matrix integrates 16 keys:

.. image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_01.png
    :align: center

Similar to the integration of a LED matrix, the 4x4 keypad matrix has each row of keys connected with one pin and this is the same for the columns. Such efficient connections reduce the number of processor ports required. The internal circuit of the Keypad Matrix is shown below.

.. image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_02.png
    :align: center

The usage is similar to the LED matrix, using a row or column scanning method to detect the state of each key's position by column and row. Take column scanning method as an example, send low level to the first 1 column (Pin1), detect level state of row 5, 6, 7, 8 to judge whether the key A, B, C, D are pressed. Then send low level to column 2, 3, 4 in turn to detect whether other keys are pressed. Therefore, you can get the state of all of the keys.

Circuit
============================================

.. list-table:: 
   :width: 80%
   :class: table-line
   :align: center
   
   * -  **Schematic diagram**
   * -  |Chapter22_03|
   * -  **Hardware connection** 
   * -  :combo:`red font-bolder:If you need any support, please feel free to contact us via:` support@freenove.com

        |Chapter22_04|

.. |Chapter22_03| image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_03.png
.. |Chapter22_04| image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_04.png

Code
================================

This code is used to obtain all key codes of the 4x4 Matrix Keypad, when one of the keys is pressed, the key code will be printed out via serial port.

Move the program folder **"Freenove_Ultimate_Starter_Kit_for_ESP32/Python/Python_Codes"** to disk(D) in advance with the path of **"D:/Micropython_Codes"**.

Open "Thonny", click "This computer" **->** "D:" **->** "Micropython_Codes" **->** "22.1_Matrix_Keypad". Select"keypad.py", right click your mouse to select "Upload to /", wait for "keypad.py" to be uploaded to ESP32-WROVER and then double click "Matrix_Keypad.py". 

Matrix_Keypad
---------------------------------

.. image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_12.png
    :align: center

Click "Run current script", push the key board and the key value will be printed in "Shell". As shown in the illustration below:

.. image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_13.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.1_Matrix_Keypad/Matrix_Keypad.py
    :linenos:
    :language: python
    :lines: 1-14
    :dedent:

Import keypad module.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.1_Matrix_Keypad/Matrix_Keypad.py
    :linenos:
    :language: python
    :lines:  1-1
    :dedent:

Associate the keypad module to ESP32 pins. 

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.1_Matrix_Keypad/Matrix_Keypad.py
    :linenos:
    :language: python
    :lines:  4-4
    :dedent:

Call function keypad.scan() of the keypad module. When the keypad module detects that the key is pressed, it returns the value of the pressed key; when no key is pressed, the return value is None. 

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.1_Matrix_Keypad/Matrix_Keypad.py
    :linenos:
    :language: python
    :lines:  7-7
    :dedent:

Call function keyPan.scan() to obtain the value of the pressed key. Once it is obtained, print it out.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.1_Matrix_Keypad/Matrix_Keypad.py
    :linenos:
    :language: python
    :lines:  6-11
    :dedent:

Reference
-----------------------------

.. py:function:: Class keypad
    
    Before each use of the object **KeyPad** , please make sure **keypad.py** has been uploaded to "/" of ESP32 and then add the statement " **from keypad import KeyPad** " to the top of python file.
    
    **KeyPad(row1,row2,row3,row4,col1,col2,col3,col4):** Intialize keypad module and associate its pins with ESP32.
    
    **scan():** Non-blocking keypad scan function. If no key is pressed, it returns None; Otherwise, it returns the valued of the pressed key.


Project Keypad Door
******************************************************

In this project, we use keypad as a keyboard to control the action of the servo motor.

Component List
=======================================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +------------------------------------+-----------------------------------------------+
    | ESP32-WROVER x1                    | GPIO Extension Board x1                       |
    |                                    |                                               |
    | |Chapter01_00|                     | |Chapter01_01|                                |
    +------------------------------------+-----------------------------------------------+
    | Breadboard x1                                                                      |
    |                                                                                    |
    | |Chapter01_02|                                                                     |
    +------------------------------------+------------------------+----------------------+
    | Jumper M/M                         | Servo x1               | 4x4 Matrix Keypad x1 |
    |                                    |                        |                      |
    | |Chapter01_05|                     |  |Chapter18_00|        |   |Chapter22_00|     |
    +------------------------------------+------------------------+----------------------+
    | NPN transistorx1 (S8050)           | Active buzzer x1       | Resistor 1kΩ x1      |
    |                                    |                        |                      |
    | |Chapter07_02|                     |  |Chapter07_01|        |   |Chapter07_03|     |
    +------------------------------------+------------------------+----------------------+

.. |Chapter07_02| image:: ../_static/imgs/7_Buzzer/Chapter07_02.png
.. |Chapter07_01| image:: ../_static/imgs/7_Buzzer/Chapter07_01.png
.. |Chapter07_03| image:: ../_static/imgs/7_Buzzer/Chapter07_03.png
.. |Chapter18_00| image:: ../_static/imgs/18_Servo/Chapter18_00.png

Circuit
========================================================

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter22_09|
   * -  **Hardware connection** 
   * -  :combo:`red font-bolder:If you need any support, please feel free to contact us via:` support@freenove.com

        |Chapter22_10|

.. |Chapter22_09| image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_09.png
.. |Chapter22_10| image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_10.png

Code
=======================================

Move the program folder **"Freenove_Ultimate_Starter_Kit_for_ESP32/Python/Python_Codes"** to disk(D) in advance with the path of "D:/Micropython_Codes".

Open "Thonny", click "This computer" **->** "D:" **->** "Micropython_Codes" **->** "22.2_Keypad_Door". Select "keypad.py" and "myservo.py", right click your mouse to select "Upload to /", wait for "keypad.py" and "myservo.py" to be uploaded to ESP32-WROVER and then double click "Keypad_Door.py". 

Keypad_Door
-----------------------------------------

.. image:: ../_static/imgs/22_Matrix_Keypad/Chapter22_14.png
    :align: center

Click "Run current script", press the keypad to input password with 4 characters. If the input is correct, the servo will move to a certain degree, and then return to the original position. If the input is wrong, an input error alarm will be generated.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.2_Keypad_Door/Keypad_Door.py
    :linenos:
    :language: python
    :lines: 1-41
    :dedent:

Define an array and set the password.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.2_Keypad_Door/Keypad_Door.py
    :linenos:
    :language: python
    :lines: 11-11
    :dedent:

Each time a key is pressed, the buzzer will short beep once, and the key value of the key will be stored in the keyIn array.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.2_Keypad_Door/Keypad_Door.py
    :linenos:
    :language: python
    :lines: 22-28
    :dedent:

When 4 keys are pressed, it will judge whether the password is correct. If it is correct, the servo will rotate 90 degrees, and then turn back after 1 second. If the password is wrong, the buzzer will long beep once and the keyInNum value will be cleared.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/22.2_Keypad_Door/Keypad_Door.py
    :linenos:
    :language: python
    :lines: 30-41
    :dedent: