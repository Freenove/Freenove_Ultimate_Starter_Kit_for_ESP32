##############################################################################
Chapter Soldering Circuit Board
##############################################################################

Project Soldering a Buzzer
*************************************************

We have tried to use a buzzer in a previous chapter, and now we will solder a circuit that when the button is pressed, the buzzer sounds.

This circuit does not need programming and can work when it is powered on. And when the button is not pressed, there is no power consumption.

You can install it on your bike, bedroom door or any other places where it is needed.

Component List
============================================

.. list-table:: 
   :width: 80% 
   :align: center
   
   * -  Pin header x2
     -  Resistor 220Ω x1

   * -  |Chapter36_00|
     -  |Chapter01_04|    

   * -  Active buzzer x1
     -  Push button x1

   * -  |Chapter07_01|
     -  |Chapter02_02|

   * -  LED x1
     -  AA Battery Holder x1

   * -  |Chapter36_01|
     -  |Chapter36_02|

.. |Chapter36_00| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_00.png
.. |Chapter01_04| image:: ../_static/imgs/1_LED/Chapter01_04.png
.. |Chapter07_01| image:: ../_static/imgs/7_Buzzer/Chapter07_01.png
.. |Chapter02_02| image:: ../_static/imgs/2_Button_&_LED/Chapter02_02.png
.. |Chapter36_01| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_01.png
.. |Chapter36_02| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_02.png

Circuit
============================================

We will solder the following circuit on the main board.

.. list-table:: 
   :width: 100%
   :header-rows: 1 
   :align: center
   
   * -  Schematic diagram
     -  Hardware connection. 
   
        If you need any support, please feel free to contact us via: 
        
        support@freenove.com

   * -  |Chapter36_03|
     -  |Chapter36_04|

.. |Chapter36_03| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_03.png
.. |Chapter36_04| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_04.png

Soldering the Circuit 
==========================================

Insert the components on the main board and solder the circuit on its back.

.. image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_05.png
    :align: center

rendering after soldering:

.. list-table:: 
   :width: 100%
   :header-rows: 1 
   :align: center
   
   * -  Front
     -  Back

   * -  |Chapter36_06|
     -  |Chapter36_07|

.. |Chapter36_06| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_06.png
.. |Chapter36_07| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_07.png

Testing circuit
-----------------------------------------

Connect the circuit board to power supply (3~5V). You can use ESP32 board or battery box as the power supply.

.. image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_08.png
    :align: center

Press the push button after connecting the power, and then the buzzer will make a sound.

Project Soldering a Flowing Water Light
****************************************************

From previous chapter, we have learned to make a flowing water light with LED. Now, we will solder a circuit board, and use the improved code to make a more interesting flowing water light.

Component List
====================================

+----------------+------------------+----------------+----------------+
| Pin header x5  | Resistor 220Ω x8 | LED x1         | 74HC595 x1     |
|                |                  |                |                |
| |Chapter36_00| | |Chapter01_04|   | |Chapter01_03| | |Chapter15_00| |
+----------------+------------------+----------------+----------------+

.. |Chapter01_03| image:: ../_static/imgs/1_LED/Chapter01_03.png 
.. |Chapter15_00| image:: ../_static/imgs/15_74HC595_&_LED_Bar_Graph/Chapter15_00.png 

Circuit
===================================

Solder the following circuit on the main board.

.. list-table:: 
   :width: 100%
   :header-rows: 1 
   :align: center
   
   * -  Schematic diagram
     -  Hardware connection

   * -  |Chapter36_09|
     -  |Chapter36_10|

.. |Chapter36_09| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_09.png
.. |Chapter36_10| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_10.png

Soldering the Circuit 
====================================

Insert the components on the main board and solder the circuit on its back.

.. image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_11.png
    :align: center

Rendering after soldering:

.. list-table:: 
   :width: 100%
   :header-rows: 1 
   :align: center
   
   * -  Front
     -  Back

   * -  |Chapter36_12|
     -  |Chapter36_13|

.. |Chapter36_12| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_12.png
.. |Chapter36_13| image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_13.png

Connecting the Circuit
===================================

Connect the board to ESP32 with jumper wire in the following way.

.. image:: ../_static/imgs/36_Soldering_Circuit_Board/Chapter36_14.png
    :align: center

Sketch
================================

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_15.1_FlowingLight02/Sketch_15.1_FlowingLight02.ino
    :linenos: 
    :language: c
    :dedent:

In fact, this code is copied from chapter 15. If you have any questions for the code, please click ":ref:`Chapter 15 74HC595 & LED Bar Graph <LED_BAR>`" to return to Chapter 15 to study again.