# Develop my home IoT using [Blynk](https://blynk.io/) and Arduino

## Add DHT sensor 

Add DHT sensor to get Temperature and Humidity.

1. create a template on Blynk. 
   a. define the datastream V0(Temperature) and V1(Humidity).
2. create a new device by using the template. Get the Blynk token is the key item we need to remotely access the device by using wifi or cellular.

3. Flash the code on ESP32.
   a. Connect usb on the port. Make sure /dev/ttyUSB0 is found.
   b. install the library required. e.g. Wifi, Blynk etc.
4. After flashing the board, you can check the status on device monitor of arduino IDE. if no error message your device is successfully setup.
