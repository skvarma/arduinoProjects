const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Open a serial port @ 9600 bits/sec

  for (int pinNumber=3; pinNumber<6; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temp = (voltage - .5) * 100;

  Serial.print("\n Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print("***Votage Value: ");
  Serial.print(voltage);
  Serial.print("***Temperature: ");
  Serial.print(temp);

  if (temp <= baselineTemp) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (temp >= baselineTemp + 4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  } else if (temp > baselineTemp + 3) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else if (temp > baselineTemp) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  

  delay(1000);

}
