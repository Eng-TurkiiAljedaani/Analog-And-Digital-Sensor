
int sensorPin = A0;    
int ledPin = 7;        


float temperatureC = 0;

void setup() {
  Serial.begin(9600);         
  pinMode(ledPin, OUTPUT);    
}

void loop() {

  int reading = analogRead(sensorPin);


  float voltage = reading * (5.0 / 1023.0);


  temperatureC = voltage * 100.0;  


  Serial.print("temperature : ");
  Serial.print(temperatureC);
  Serial.println(" °C");


  if (temperatureC > 36.5) {
    digitalWrite(ledPin, HIGH);  
  } else {
    digitalWrite(ledPin, LOW);    
  }

  delay(2000);   
}
