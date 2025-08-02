#include "DHT.h"


#define DHTPIN 2        
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);   

int ledPin = 7;  

void setup() {
  Serial.begin(9600);     
  dht.begin();           
  pinMode(ledPin, OUTPUT); 
}

void loop() {
 
   float h = dht.readHumidity();      
  float t = dht.readTemperature();   


  if (isnan(h) || isnan(t)) {
    Serial.println(" Error ");
    return;
  }


  Serial.print(" Humidity : ");
  Serial.print(h);
  Serial.print(" %  |   heat: ");
  Serial.print(t);
  Serial.println(" °C");


  if (t > 25.0) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW);    
  }

  delay(1000);   
}
