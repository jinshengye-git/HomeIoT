Thanks to the answer of [Codebreaker007](https://stackoverflow.com/users/10245581/codebreaker007)

[Pre-requisites for flashing](https://stackoverflow.com/questions/61828099/esp32cam-failed-to-connect-to-esp32-timed-out-waiting-for-packet-header/61829032#61829032):

- Select board **AI Thinker Cam**
- uplooad speed 921600
- freq 240Mhz
- flashfreq 80Mhz
- mode QIO (if not working try DIO)
- partition scheme default
- Serial monitor is closed
- NO hardware connected to the pins of the ESPcam
- Make sure the USB cable is a data cable and NO loading cable only
- connect GPIO 0 (IO0) with a dupont wire connected to GND
- press reset
- compile and upload (use AI THINKER CAM)

- disconnect GPIO 0 and GND
- press reset again.
- code should execute
- on Serial monitor you will find the IP of the camera. open browser and input http://192.168.11.xx

    - you will see the control panel, click 'Start Stream'


**Note: Yes, you have to do it every upload, on my dev board I soldered a little switch with proper isolation**

**Some more solutions from experience:**

If there is still a problem use a 10K (or so) pull-down resistor between RX0 and GND (test on breadboard before soldering)
Pressing and holding (!) the boot-button while uploading on some "bad" boards
Happened with a "normal" ESP32 board to me - just to be sure - I got an ESP8266 in an ESP32 packaging. Configuring for the ESP8266 solved the issue of uploading.


Thanks to [techiesms](https://www.youtube.com/watch?v=ukWvHX-JTgI)
I can find a walk around to make a https server to stream the video.