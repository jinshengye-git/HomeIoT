/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

#define BLYNK_TEMPLATE_ID "your template ID" // add your template ID from your Blynk.console
#define BLYNK_DEVICE_NAME "DHT22" // add your device name from  your Blynk.console.
#define BLYNK_AUTH_TOKEN "your token code" //add your token from your Blynk.console

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "your wifi ssid";  // type your wifi name
char pass[] = "your wifi password";  // type your wifi password

#define DHTPIN 4          // Mention the digital pin where you connected 
#define DHTTYPE DHT22     // DHT 22 
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V0, t);
  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.print("    Humidity : ");
  Serial.println(h);


  if(t > 30){
   // Blynk.email("shameer50@gmail.com", "Alert", "Temperature over 28C!");
    Blynk.logEvent("temp_alert","Temp above 30 degree");
  }
}

void setup(){
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
