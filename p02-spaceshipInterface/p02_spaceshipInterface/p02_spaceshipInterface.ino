
/*
 * This sketch turns LED's connected to pins 3,4 & 5on and off 
 * when input switch connected to digital pin 2 is pressed.  
 */

// Switch is currently off
int switchState = 0;

void setup() {
  // Output pins
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  //Input Pin
  pinMode(2, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW){
    //The button is not pressed
    digitalWrite(3, HIGH);//green
    digitalWrite(4, LOW);//yellow
    digitalWrite(5, LOW);//red
  }
  else{
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(1250);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(1250);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);    
    delay(1250);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(1250);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(1000);
  }
}

