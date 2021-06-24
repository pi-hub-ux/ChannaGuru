#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
   pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    myservo.attach(9);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5)==LOW)
  {
    myservo.write(180);
    delay(1000);
    Serial.println("180");
  }
  if(digitalRead(6)==LOW){
       myservo.write(0);
      delay(1000);
       Serial.println("0");
  }
  
 }
