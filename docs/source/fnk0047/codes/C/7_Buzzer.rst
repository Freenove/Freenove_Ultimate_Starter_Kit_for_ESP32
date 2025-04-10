##############################################################################
Chapter Buzzer
##############################################################################

In this chapter, we will learn about buzzers that can make sounds.

Project Doorbell
*************************************

We will make this kind of doorbell: when the button is pressed, the buzzer sounds; and when the button is released, the buzzer stops sounding.

Component List
======================================

+------------------------------------+-------------------------+
| ESP32-WROVER x1                    | GPIO Extension Board x1 |
|                                    |                         |
| |Chapter01_00|                     | |Chapter01_01|          |
+------------------------------------+-------------------------+
| Breadboard x1                                                |
|                                                              |
| |Chapter01_02|                                               |
+-----------------+------------------+-------------------------+
| LED x1          | Active buzzer x1 | Jumper M/M x6           |
|                 |                  |                         |
| |Chapter07_00|  | |Chapter07_01|   | |Chapter01_05|          |
+-----------------+------------------+-------------------------+
|NPN transistorx1 | Resistor 1kΩ x1  | Resistor 10kΩ x2        |
|(S8050)          |                  |                         |
|                 |                  |                         |
| |Chapter07_02|  | |Chapter07_03|   | |Chapter07_04|          |
+-----------------+------------------+-------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter01_01| image:: ../_static/imgs/1_LED/Chapter01_01.png
.. |Chapter01_02| image:: ../_static/imgs/1_LED/Chapter01_02.png
.. |Chapter07_00| image:: ../_static/imgs/7_Buzzer/Chapter07_00.png
.. |Chapter07_01| image:: ../_static/imgs/7_Buzzer/Chapter07_01.png
.. |Chapter07_02| image:: ../_static/imgs/7_Buzzer/Chapter07_02.png
.. |Chapter07_03| image:: ../_static/imgs/7_Buzzer/Chapter07_03.png
.. |Chapter07_04| image:: ../_static/imgs/7_Buzzer/Chapter07_04.png
.. |Chapter01_05| image:: ../_static/imgs/1_LED/Chapter01_05.png

Component knowledge
=========================================

Buzzer
----------------------------------------

Buzzer is a sounding component, which is widely used in electronic devices such as calculator, electronic warning clock and alarm. Buzzer has two types: active and passive. Active buzzer has oscillator inside, which will sound as long as it is supplied with power. Passive buzzer requires external oscillator signal (generally use PWM with different frequency) to make a sound.

.. image:: ../_static/imgs/7_Buzzer/Chapter07_05.png
    :align: center

Active buzzer is easy to use. Generally, it can only make a specific frequency of sound. Passive buzzer requires an external circuit to make a sound, but it can be controlled to make a sound with different frequency. The resonant frequency of the passive buzzer is 2kHz, which means the passive buzzer is loudest when its resonant frequency is 2kHz.

Next, we will use an active buzzer to make a doorbell and a passive buzzer to make an alarm.

How to identify active and passive buzzer?

1.	Usually, there is a label on the surface of active buzzer covering the vocal hole, but this is not an absolute judgment method.

2.	Active buzzers are more complex than passive buzzers in their manufacture. There are many circuits and crystal oscillator elements inside active buzzers; all of this is usually protected with a waterproof coating (and a housing) exposing only its pins from the underside. On the other hand, passive buzzers do not have protective coatings on their underside. From the pin holes viewing of a passive buzzer, you can see the circuit board, coils, and a permanent magnet (all or any combination of these components depending on the model.

.. image:: ../_static/imgs/7_Buzzer/Chapter07_06.png
    :align: center

Transistor
========================================

Because the buzzer requires such large current that GPIO of ESP32 output capability cannot meet the requirement, a transistor of NPN type is needed here to amplify the current.

Transistor, the full name: semiconductor transistor, is a semiconductor device that controls current. Transistor can be used to amplify weak signal, or works as a switch. It has three electrodes(PINs): base (b), collector (c) and emitter (e). When there is current passing between "be", "ce" will allow several-fold current (transistor magnification) pass, at this point, transistor works in the amplifying area. When current between "be" exceeds a certain value, "ce" will not allow current to increase any longer, at this point, transistor works in the saturation area. Transistor has two types as shown below: PNP and NPN,

.. image:: ../_static/imgs/7_Buzzer/Chapter07_07.png
    :align: center

:red:`In our kit, the PNP transistor is marked with 8550, and the NPN transistor is marked with 8050.`

Based on the transistor's characteristics, it is often used as a switch in digital circuits. As micro-controller's capacity to output current is very weak, we will use transistor to amplify current and drive large-current components.

When use NPN transistor to drive buzzer, we often adopt the following method. If GPIO outputs high level, current will flow through R1, the transistor will get conducted, and the buzzer will sound. If GPIO outputs low level, no current flows through R1, the transistor will not be conducted, and buzzer will not sound.

When use PNP transistor to drive buzzer, we often adopt the following method. If GPIO outputs low level, current will flow through R1, the transistor will get conducted, and the buzzer will sound. If GPIO outputs high level, no current flows through R1, the transistor will not be conducted, and buzzer will not sound.

.. list-table:: 
   :width: 100%
   :header-rows: 1 
   :align: center
   
   * -  NPN transistor to drive buzzer
     -  PNP transistor to drive buzzer
   
   * -  |Chapter07_08|
     -  |Chapter07_09|

.. |Chapter07_08| image:: ../_static/imgs/7_Buzzer/Chapter07_08.png    
.. |Chapter07_09| image:: ../_static/imgs/7_Buzzer/Chapter07_09.png  

Circuit
========================================

.. list-table:: 
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter07_10| 
   * -  Hardware connection. 
       
        If you need any support, please feel free to contact us via: support@freenove.com
     
   * -  |Chapter07_11|

.. |Chapter07_10| image:: ../_static/imgs/7_Buzzer/Chapter07_10.png    
.. |Chapter07_11| image:: ../_static/imgs/7_Buzzer/Chapter07_11.png  

.. note::
    
    in this circuit, the power supply for buzzer is 5V, and pull-up resistor of the button connected to the power 3.3V. The buzzer can work when connected to power 3.3V, but it will reduce the loudness.

Sketch
===========================

In this project, a buzzer will be controlled by a push button switch. When the button switch is pressed, the buzzer sounds and when the button is released, the buzzer stops. It is analogous to our earlier project that controlled a LED ON and OFF.

Sketch_Doorbell
---------------------------------

.. image:: ../_static/imgs/7_Buzzer/Chapter07_12.png
    :align: center

Download the code to ESP32-WROVER, press the push button switch and the buzzer will sound. Release the push button switch and the buzzer will stop.

.. image:: ../_static/imgs/7_Buzzer/Chapter07_13.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.1_Doorbell/Sketch_07.1_Doorbell.ino
    :linenos: 
    :language: c
    :dedent:

The code is logically the same as using button to control LED.

Project Alertor
************************************

Next, we will use a passive buzzer to make an alarm.

Component list and the circuit is similar to the last section. In the Doorbell circuit only the active buzzer needs to be replaced with a passive buzzer.

Sketch
===================================

In this project, the buzzer alarm is controlled by the button. Press the button, then buzzer sounds. If you release the button, the buzzer will stop sounding. It is logically the same as using button to control LED, but in the control method, passive buzzer requires PWM of certain frequency to sound.

Sketch_Alertor
-------------------------------------

.. image:: ../_static/imgs/7_Buzzer/Chapter07_14.png
    :align: center

Download the code to ESP32-WROVER, press the button, then alarm sounds. And when the button is released, the alarm will stop sounding.

.. image:: ../_static/imgs/7_Buzzer/Chapter07_15.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.2_Aleror/Sketch_07.2_Aleror.ino
    :linenos: 
    :language: c
    :dedent:

The code is the same as the active buzzer logically, but the way to control the buzzer is different. Passive buzzer requires PWM of certain frequency to control, so you need to create a PWM channel through ledcAttachChannal(). Here ledcWriteTone() is designed to generating square wave with variable frequency and duty cycle fixed to 50%, which is a better choice for controlling the buzzer.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.2_Aleror/Sketch_07.2_Aleror.ino
    :linenos: 
    :language: c
    :lines: 13-14
    :dedent:

In the while cycle of main function, when the button is pressed, subfunction alert() will be called and the alertor will issue a warning sound. The frequency curve of the alarm is based on the sine curve. We need to calculate the sine value from 0 to 360 degree and multiply a certain value (here is 500) and plus the resonant frequency of buzzer. 

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.2_Aleror/Sketch_07.2_Aleror.ino
    :linenos: 
    :language: c
    :lines: 26-35
    :dedent:

If you want to close the buzzer, just set PWM frequency of the buzzer pin to 0.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.2_Aleror/Sketch_07.2_Aleror.ino
    :linenos: 
    :language: c
    :lines: 22-22
    :dedent:

Reference
--------------------------------

.. py:function:: double ledcWriteTone(uint8_t channel, double freq);

    This updates the tone frequency value on the given channel. 

    This function has some bugs in the current version (V1.0.4): when the call interval is less than 20ms, the resulting PWM will have an exception. We will get in touch with the authorities to solve this problem and give solutions in the following two projects.

Project Alertor (use timer)
*****************************************

Due to some bugs in the function ledcWriteTone(), this project uses timer to generate software PWM to control the buzzer. The circuit is exactly the same as the last project.

Sketch
===========================================

The core of the code of this project is to create a timer to change the GPIO state to generate 50% pulse width PWM, and change the PWM frequency by changing the timing time of the timer.

Sketch_Alertor
--------------------------------------------

.. image:: ../_static/imgs/7_Buzzer/Chapter07_16.png
    :align: center

Download the code to ESP32-WROVER, press the button, then the alarm sounds. And when the button is released, the alarm will stop sounding.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.3_Aleror/Sketch_07.3_Aleror.ino
    :linenos: 
    :language: c
    :dedent:

In the code, first define a timer variable, timer, and then create the timer in setup(), setting the function onTimer() that the timer will execute.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.3_Aleror/Sketch_07.3_Aleror.ino
    :linenos: 
    :language: c
    :lines: 9-9, 20-23
    :dedent:

In the loop(), use the timerAlarmWrite() to set the timer time and use timerAlarmEnable() to start the timer. Using the flag bit isAlerting, the code to set and start the timer is executed only when the key is pressed.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.3_Aleror/Sketch_07.3_Aleror.ino
    :linenos: 
    :language: c
    :lines: 27-33
    :dedent:

After the key is released, stop the timer and make the buzzer's GPIO output low.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_07.3_Aleror/Sketch_07.3_Aleror.ino
    :linenos: 
    :language: c
    :lines: 36-40
    :dedent:

Reference
---------------------------

.. py:function:: typedef struct hw_timer_s hw_timer_t;
    
    Timer type, used to define a timer variable.

.. py:function:: hw_timer_t * timerBegin(uint32_t frequency);
    
    Initialize the timer.

    parameters 

    frequency: Frequency of the timer.

.. py:function:: void timerAttachInterrupt(hw_timer_t *timer, void (*fn)(void));
    
    Bind the function to execute when the interrupt is generated for the timer.

.. py:function:: void timerAlarm(hw_timer_t *timer, uint64_t interruptAt, bool autoreload, uint64_t reload_count);
    
    Set the timer time.

.. py:function:: void timerStart(hw_timer_t *timer);
                 void timerStop(hw_timer_t *timer);
                 void timerRestart(hw_timer_t *timer);
                 void timerEnd(hw_timer_t *timer);	
                
    Start/stop the timer.
