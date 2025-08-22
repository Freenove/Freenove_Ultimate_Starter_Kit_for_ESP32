##############################################################################
Chapter 31 Play SD card music
##############################################################################

.. note::
    
    The SD card chapter only applies to the ESP32 WROVER development board with an SD card slot on the back. If your ESP32 WROVER does not have an SD card slot on the back, please skip this chapter.

In the previous study, we have learned how to use the SD card, and then we will learn to play the music in the SD card.

Project 31.1 SDMMC Music
**************************************************

In this project, we will read an mp3 file from an SD card, decode it through ESP32, and use a speaker to play it.

Component List
==================================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +-------------------+--------------------------+-------------------+
    | ESP32 WROVER x1   | USB cable x1             | SDcard x1         |
    |                   |                          |                   |
    ||Chapter01_00|     ||Chapter30_00|            ||Chapter30_02|     |
    +-------------------+--------------------------+-------------------+
    | Micro USB Wire x1 | NPN transistorx1 (S8050) | Speaker           |
    |                   |                          |                   |
    ||Chapter08_00|     ||Chapter07_02|            ||Chapter28_00|     |
    +-------------------+--------------------------+-------------------+
    | Diode x1          | Resistor 1kΩ x1          | Capacitor 10uF x1 |
    |                   |                          |                   |
    ||Chapter17_01|     ||Chapter07_03|            ||Chapter28_01|     |
    +-------------------+------------+-------------+-------------------+
    | Jumper F/M x4 Jumper F/F x2    | Card reader x1 (random color)   |
    |                                |                                 |
    | |Chapter24_08|                 ||Chapter30_01|                   |
    |                                |                                 |
    |                                | :red:`(Not a USB flash drive.)` |
    +--------------------------------+---------------------------------+

.. |Chapter01_00| image:: ../_static/imgs/1_LED/Chapter01_00.png
.. |Chapter08_00| image:: ../_static/imgs/8_Serial_Communication/Chapter08_00.png
.. |Chapter28_00| image:: ../_static/imgs/28_Bluetooth_Media_by_DAC/Chapter28_00.png
.. |Chapter24_08| image:: ../_static/imgs/24_Hygrothermograph_DHT11/Chapter24_08.png
.. |Chapter30_00| image:: ../_static/imgs/30_Read_and_Write_the_Sdcard/Chapter30_00.png
.. |Chapter30_01| image:: ../_static/imgs/30_Read_and_Write_the_Sdcard/Chapter30_01.png
.. |Chapter30_02| image:: ../_static/imgs/30_Read_and_Write_the_Sdcard/Chapter30_02.png
.. |Chapter28_01| image:: ../_static/imgs/28_Bluetooth_Media_by_DAC/Chapter28_01.png
.. |Chapter07_02| image:: ../_static/imgs/7_Buzzer/Chapter07_02.png
.. |Chapter07_03| image:: ../_static/imgs/7_Buzzer/Chapter07_03.png
.. |Chapter17_01| image:: ../_static/imgs/17_Relay_&_Motor/Chapter17_01.png

Circuit
========================

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter31_00|
   * -  Please note that before connecting the USB cable, please put the music into the SD card and insert the SD card into the card slot on the back of the ESP32.
      
        |Chapter31_01|
   * -  **Hardware connection** 
       
        :combo:`red font-bolder:If you need any support, please feel free to contact us via:` support@freenove.com

        |Chapter31_02|

.. |Chapter31_00| image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_00.png
.. |Chapter31_01| image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_01.png
.. |Chapter31_02| image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_02.png

Sketch
===================================

How to install the library
------------------------------------

In this project, we will use the ESP8266Audio.zip library to decode the audio files in the SD card, and then output the audio signal through GPIO. If you have not installed this library, please follow the steps below to install it.

Open arduino -> Sketch -> Include library -> Add .ZIP Library. 

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_03.png
    :align: center

In the new pop-up window, select "Freenove_Ultimate_Starter_Kit_for_ESP32\\C\\Libraries\\ESP8266Audio.zip". 

Then click "Open".

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_04.png
    :align: center

Sketch_31.1_PlayMP3FromSD
-------------------------------------

We placed a folder called "music" in:

**Freenove_Ultimate_Starter_Kit_for_ESP32\\Sketches\\Sketch_31.1_PlayMP3FromSD**

:combo:`red font-bolder:User needs to copy this folder to SD card.`

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_05.png
    :align: center

Click upload.

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_06.png
    :align: center

Compile and upload the code to the ESP32 WROVER and open the serial monitor. ESP32 takes a few seconds to initialize the program. When you see the message below, it means that ESP32 has started parsing the mp3 in sd and started playing music through Pin.

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_07.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.1_PlayMP3FromSD/Sketch_31.1_PlayMP3FromSD.ino
    :linenos: 
    :language: c
    :dedent:

Add music decoding header files and SD card drive files.

If you want to use the circuit in 31.2, you just need to modify **#define IIS_ENABLE 1**.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.1_PlayMP3FromSD/Sketch_31.1_PlayMP3FromSD.ino
    :linenos: 
    :language: c
    :lines: 1-14
    :dedent:

Define the drive pins for SD card. Note that the SD card driver pins cannot be modified.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.1_PlayMP3FromSD/Sketch_31.1_PlayMP3FromSD.ino
    :linenos: 
    :language: c
    :lines: 16-21
    :dedent:

Apply for audio decoding class object.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.1_PlayMP3FromSD/Sketch_31.1_PlayMP3FromSD.ino
    :linenos: 
    :language: c
    :lines: 23-31
    :dedent:

Set the audio file source and associate it with the decoder. Initialize the audio output pin and set the volume to 2.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.1_PlayMP3FromSD/Sketch_31.1_PlayMP3FromSD.ino
    :linenos: 
    :language: c
    :lines: 66-79
    :dedent:

Determine whether the mp3 player is finished. If it is playing, continue playing. If it is finished, print a message.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.1_PlayMP3FromSD/Sketch_31.1_PlayMP3FromSD.ino
    :linenos: 
    :language: c
    :lines: 84-89
    :dedent:

Project 31.2 SDMMC Music
*********************************************

In this project, we will read mp3 files from SD card, decode them through ESP32, and use Audio Converter & Amplifier module to transcode into stereo output.

Component List
==================================================

.. table::
    :width: 80%
    :align: center
    :class: table-line
    
    +-------------------+----------------------------------+-------------------+
    | ESP32 WROVER x1   | USB cable x1                     | SDcard x1         |
    |                   |                                  |                   |
    ||Chapter01_00|     ||Chapter30_00|                    ||Chapter30_02|     |
    +-------------------+----------------------------------+-------------------+
    | Micro USB Wire x1 | Audio Converter & Amplifier      | Speaker           |
    |                   |                                  |                   |
    ||Chapter08_00|     |  |Chapter29_00|                  ||Chapter28_00|     |
    |                   |                                  |                   |
    +-------------------+----------------------------------+-------------------+
    | Jumper F/M x4     | Card reader x1 (random color)                        |
    |                   |                                                      |
    | Jumper F/F x2     | |Chapter30_01|                                       |
    |                   |                                                      |
    ||Chapter24_08|     | :red:`(Not a USB flash drive.)`                      |
    +-------------------+------------------------------------------------------+

.. |Chapter29_00| image:: ../_static/imgs/29_Bluetooth_Media_by_Audio_Module/Chapter29_00.png

Circuit
==========================================

.. list-table:: 
   :width: 80%
   :align: center
   :class: table-line
   
   * -  **Schematic diagram**
   * -  |Chapter31_08|
   * -  Please note that before connecting the USB cable, please put the music into the
       
        SD card and insert the SD card into the card slot on the back of the ESP32.

        |Chapter31_09|
   * -  **Hardware connection** 
      
        :combo:`red font-bolder:If you need any support, please feel free to contact us via:` support@freenove.com

        |Chapter31_10|

.. |Chapter31_08| image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_08.png
.. |Chapter31_09| image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_09.png
.. |Chapter31_10| image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_10.png

Sketch
==========================================

How to install the library
--------------------------------------------

In this project, we will use the ESP32-audioI2S.zip library to decode the audio files in the SD card, and then output the audio signal through IIS. If you have not installed this library, please follow the steps below to install it.

Open arduino -> Sketch -> Include library -> Add .ZIP Library. 

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_11.png
    :align: center

In the new pop-up window, select **"Freenove_Ultimate_Starter_Kit_for_ESP32\\C\\Libraries\\ESP32-audioI2S.zip"**. 

Then click "Open".

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_12.png
    :align: center

Sketch_31.2_SDMMC_Music
----------------------------------------------

We placed a folder called "music" in:

**Freenove_Ultimate_Starter_Kit_for_ESP32\\Sketches\\Sketch_31.2_SDMMC_Music.**

User needs to copy this folder to SD card.

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_13.png
    :align: center

Click Tools -> Partition Scheme, Select Huge APP......, Then click upload. 

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_14.png
    :align: center

Compile and upload the code to the ESP32 WROVER and open the serial monitor. ESP32 takes a few seconds to initialize the program. 

When you see the message below, it means that ESP32 has started parsing the mp3 in sd and started playing music through iis.

.. image:: ../_static/imgs/31_Play_SD_card_music/Chapter31_15.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.2_SDMMC_Music/Sketch_31.2_SDMMC_Music.ino
    :linenos: 
    :language: c
    :dedent:

Add music decoding header files and SD card drive files.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.2_SDMMC_Music/Sketch_31.2_SDMMC_Music.ino
    :linenos: 
    :language: c
    :lines: 7-10
    :dedent:

Define the drive pins for SD card and IIS. Note that the SD card driver pins cannot be modified, but the IIS drive pins can be modified.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.2_SDMMC_Music/Sketch_31.2_SDMMC_Music.ino
    :linenos: 
    :language: c
    :lines: 12-17
    :dedent:

Declare an audio decoding object, associate it with the pin, set the volume, and set the decoding object.

.. code-block:: c
    :linenos:

    Audio audio;
    ......
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(12);  // 0...21
    audio.connecttoFS(SD_MMC, "/music/Jingle Bells.mp3");

Play music until one piece of music finishes playing. If the serial port receives data, it will call the audio object to decode it after removing the spaces at the head and tail of the data.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.2_SDMMC_Music/Sketch_31.2_SDMMC_Music.ino
    :linenos: 
    :language: c
    :lines: 53-60
    :dedent:

In other words, if you want to switch the music in the SD card, you can directly input the song through the serial port.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_31.2_SDMMC_Music/Sketch_31.2_SDMMC_Music.ino
    :linenos: 
    :language: c
    :lines: 53-60
    :dedent:

The following functions are used to print the audio decoding information. If you do not want to see the decoding information in the serial port, you can directly comment out these functions.

.. code-block:: C
    :linenos:

    void audio_info(const char *info);
    void audio_id3data(const char *info);
    void audio_eof_mp3(const char *info);
    void audio_showstation(const char *info);
    void audio_showstreamtitle(const char *info);
    void audio_bitrate(const char *info);
    void audio_commercial(const char *info);
    void audio_icyurl(const char *info);
    void audio_lasthost(const char *info);