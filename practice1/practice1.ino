#include <Servo.h> 

#define sw1_pin 4
#define sw2_pin 5
#define sw3_pin 6

Servo myservo;

int c = 0;

volatile boolean sw1 = false;
volatile boolean sw2 = false;
volatile boolean sw3 = false;

uint8_t sw1ButtonState = 0;
uint8_t sw2ButtonState = 0;
uint8_t sw3ButtonState = 0;

uint8_t lastsw1ButtonState = 0;
uint8_t lastsw2ButtonState = 0;
uint8_t lastsw3ButtonState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sw1_pin, INPUT_PULLUP);
  pinMode(sw2_pin, INPUT_PULLUP);
  pinMode(sw3_pin, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkIfSw1ButtonIsPressed();
  checkIfSw2ButtonIsPressed();
  checkIfSw3ButtonIsPressed();

     if(sw1)
     {
      Serial.println(sw1);
       sw1 = false;
       Serial.println(sw1);
       myservo.write(180);
       delay(5);
     }

     else if(sw2)
     {
      Serial.println(sw2);
       sw2 = false;
       myservo.write(0);
       delay(5);
     }
     else if(sw3)
     {
      if(c==1)
      {
        Serial.println("sw3");
        digitalWrite(12, HIGH);
       sw3 = false;
 
       delay(4000);
        digitalWrite(12, LOW);
        delay(200);
      }
      else if(c==2)
      {
           Serial.println("sw3");
        digitalWrite(13, HIGH);
       sw3 = false;
 
       delay(4000);
        digitalWrite(13, LOW);
        delay(200);
      }
      else if(c==3)
      {
        Serial.println("sw3");
        digitalWrite(11, HIGH);
       sw3 = false;
 
       delay(4000);
        digitalWrite(11, LOW);
        delay(200);
      }
      else
      {
        c=0;
        delay(5);
      }
      
     }
}

void checkIfSw1ButtonIsPressed()
{
    sw1ButtonState = digitalRead(sw1_pin);

    if (sw1ButtonState != lastsw1ButtonState)
  {
    if (sw1ButtonState == 0)
    {
      sw1=true;
        Serial.println(sw1);
    }
    delay(10);
  }
   lastsw1ButtonState = sw1ButtonState;
 
 }

void checkIfSw2ButtonIsPressed()
{
    sw2ButtonState = digitalRead(sw2_pin);
  
    if (sw2ButtonState != lastsw2ButtonState)
  {
    if (sw2ButtonState == 0)
    {
      sw2=true;
    }
    delay(10);
  }
   lastsw2ButtonState = sw2ButtonState;

 }
 void checkIfSw3ButtonIsPressed()
{
    sw3ButtonState = digitalRead(sw3_pin);
  
    if (sw3ButtonState != lastsw3ButtonState)
  {
    if (sw3ButtonState == 0)
    {
      c=c+1;
      sw3=true;
    }
    delay(10);
  }
   lastsw3ButtonState = sw3ButtonState;

 }
