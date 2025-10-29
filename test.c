#include<Servo.h>
Servo s1;
int sv=A0;//flame sensor pin connect with analog pin A0
int op;// varial which is take value of sensor
int buzzer=8;// buzzer connect with digital pin 8
int relay=3;//relay is connect with didital pin of 3
int rled=6;//red led is connect with digital pin 6
int gled=5;//green led connect with digital pin 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sv,INPUT);
  pinMode(rled,OUTPUT);
  pinMode(gled,OUTPUT);
  s1.attach(7);
  
}

void loop() {
  op=analogRead(sv);
  Serial.println(op);
  if(op<200)
  {
    s1.write(90);
    digitalWrite(gled,LOW);
    digitalWrite(relay,LOW);
    digitalWrite(buzzer,HIGH);
    digitalWrite(rled,HIGH);
    delay(500);
    digitalWrite(rled,LOW);
    digitalWrite(buzzer,LOW);
    delay(500);
   
  }
  else if(op>200)
  {
    delay(1000);
    digitalWrite(relay,HIGH);
    digitalWrite(buzzer,LOW);
    digitalWrite(rled,LOW);
    digitalWrite(gled,HIGH);
    delay(1000);
    s1.write(0);
  }
  else
  {
        Serial.println("error is code");
  }

}