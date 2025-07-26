##############################################################################
Chapter Stepper Motor
##############################################################################

In this project, we will learn how to drive a stepper motor, and understand its working principle.

Project Stepper Motor
*******************************************

Component List
============================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +------------------------------------+---------------------------------------------------------------+
    | ESP32-WROVER x1                    | GPIO Extension Board x1                                       |
    |                                    |                                                               |
    | |Chapter01_00|                     | |Chapter01_01|                                                |
    +------------------------------------+---------------------------------------------------------------+
    | Breadboard x1                                                                                      |
    |                                                                                                    |
    | |Chapter01_02|                                                                                     |
    +------------------------------------+------------------------+--------------------------------------+
    | Stepper Motor x1                   | Jumper F/M x6          | ULN2003 Stepper Motor Driver x1      |
    |                                    |                        |                                      |
    | |Chapter19_00|                     |  |Chapter01_05|        |   |Chapter19_01|                     |
    +------------------------------------+------------------------+--------------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png
.. |Chapter19_00| image:: ../_static/imgs/19_Stepper_Motor/Chapter19_00.png
.. |Chapter19_01| image:: ../_static/imgs/19_Stepper_Motor/Chapter19_01.png

Component knowledge
========================================

Stepper Motor
--------------------------------------

Stepper motors are an open-loop control device, which converts an electronic pulse signal into angular displacement or linear displacement. In a non-overload condition, the speed of the motor and the location of the stops depends only on the pulse signal frequency and number of pulses and is not affected by changes in load as with a DC motor. A small four-phase deceleration stepper motor is shown here:

.. image:: ../_static/imgs/19_Stepper_Motor/Chapter19_02.png
    :align: center

The electronic schematic diagram of a four-phase stepper motor is shown below:

.. image:: ../_static/imgs/19_Stepper_Motor/Chapter19_03.png
    :align: center

The outside case or housing of the stepper motor is the stator and inside the stator is the rotor. There are a specific number of individual coils, usually an integer multiple of the number of phases the motor has, when the stator is powered ON, an electromagnetic field will be formed to attract a corresponding convex diagonal groove or indentation in the rotor's surface. The rotor is usually made of iron or a permanent magnet. Therefore, the stepper motor can be driven by powering the coils on the stator in an ordered sequence (producing a series of "steps" or stepped movements).

A common driving process is as follows:

.. image:: ../_static/imgs/19_Stepper_Motor/Chapter19_04.png
    :align: center

In the course above, the stepper motor rotates a certain angle once, which is called a step. By controlling the number of rotation steps, you can control the stepper motor rotation angle. By controlling the time between two steps, you can control the stepper motor rotation speed. When rotating clockwise, the order of coil powered on is: A -> B -> C -> D -> A -> ...... . And the rotor will rotate in accordance with the order, step by step down, called four steps four pats. If the coils is powered on in the reverse order, D -> C -> B -> A -> D -> … , the rotor will rotate in anti-clockwise direction.

There are other methods to control stepper motors, such as: connect A phase, then connect A B phase, the stator will be located in the center of A B, which is called a half-step. This method can improve the stability of the stepper motor and reduces noise. The sequence of powering the coils looks like this: A ->  AB -> B  -> BC -> C  -> CD -> D -> DA -> A -> ...... , the rotor will rotate in accordance to this sequence at a half-step at a time, called four-steps, eight-part. Conversely, if the coils are powered ON in the reverse order the stepper motor will rotate in the opposite direction.

The stator in the stepper motor we have supplied has 32 magnetic poles. Therefore, to complete one full revolution requires 32 full steps. The rotor (or output shaft) of the stepper motor is connected to a speed reduction set of gears and the reduction ratio is 1:64. Therefore, the final output shaft (exiting the stepper motor's housing) requires 32 X 64 = 2048 steps to make one full revolution.

ULN2003 Stepper motor driver
--------------------------------------------

A ULN2003 stepper motor driver is used to convert weak signals into more powerful control signals in order to drive the stepper motor. In the illustration below, the input signal IN1-IN4 corresponds to the output signal A-D, and 4 LEDs are integrated into the board to indicate the state of these signals. The PWR interface can be used as a power supply for the stepper motor. By default, PWR and VCC are connected.

.. image:: ../_static/imgs/19_Stepper_Motor/Chapter19_05.png
    :align: center

Circuit
=============================================

When building the circuit, note that rated voltage of the stepper motor is 5V, and we need to use the breadboard power supply independently. Additionally, the breadboard power supply needs to share Ground with ESP32.

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter19_06|
   * -  **Hardware connection**
   * -  :combo:`red font-bolder:If you need any support, please feel free to contact us via:` support@freenove.com

        |Chapter19_09|

.. |Chapter19_06| image:: ../_static/imgs/19_Stepper_Motor/Chapter19_06.png
.. |Chapter19_09| image:: ../_static/imgs/19_Stepper_Motor/Chapter19_09.png

Sketch
========================================

This code uses the four-step, four-part mode to drive the stepper motor in the clockwise and anticlockwise directions.

Sketch_Drive_Stepper_Motor
------------------------------------------

.. image:: ../_static/imgs/19_Stepper_Motor/Chapter19_07.png
    :align: center

Compile and upload the code to the ESP32-WROVER, the stepper motor will rotate 360° clockwise and stop for 1s, and then rotate 360° anticlockwise and stop for 1s. And it will repeat this action in an endless loop.

.. image:: ../_static/imgs/19_Stepper_Motor/Chapter19_08.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :dedent:

In this project, we define four pins to drive stepper motor.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 7-8
    :dedent:

moveOneStep Function is used to drive the stepper motor to rotate clockwise or counterclockwise. The parameter "dir" indicates the direction of rotation. If "dir" returns true, the stepper motor rotates clockwise, otherwise the stepper motor rotates counterclockwise.  

.. code-block:: C

    void moveOneStep(bool dir) {
        ......
    }

Define a static byte variable, calculate the value of the variable according to the rotation direction of the motor, and use the keyword static to save the position status of the previous step of the stepper motor. Use the four low bits of the variable to control the output state of the four pins.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 36-44
    :dedent:

Make the pin to output corresponding level based on the value of the variable.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 45-48
    :dedent:

The moveSteps function can control the direction of the stepper motor, the number of rotation steps, and the speed of rotation. According to the previous knowledge, the stepper motor needs 32*64 steps for one revolution. The speed of rotation is determined by the parameter ms. The larger the ms is, the slower the rotation speed is. There is a range for the speed of the motor, which is determined by the motor itself and according to our test, the value of ms is limited to 3-20.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 27-33
    :dedent:

The function moveTurns() is a further package of moveSteps(), which is used to control the stepper motor to rotate a specified number of turns. The parameter "turns" represents the number of turns that need to be rotated.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 51-54
    :dedent:

The function moveAround () is a further package of moveSteps (), which is used to control the stepper motor to rotate by a specified angle, and the parameter "angle" represents the angle to be rotated.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 55-57
    :dedent:

In the loop function, call the moveSteps function to loop the stepper motor: rotate clockwise one turn and stop for 1s, then rotate counterclockwise one turn and stop for 1s.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_19.1_Drive_Stepper_Motor/Sketch_19.1_Drive_Stepper_Motor.ino
    :linenos: 
    :language: c
    :lines: 17-25
    :dedent: