#include <Servo.h>

Servo s1;
Servo s2;

int sp1 = D3;
int sp2 = D4;
int fire = A0;     // Flame sensor connected to analog pin A0
int buzzer = D1;   // Buzzer connected to digital pin D1
int relay = D2;    // Relay connected to digital pin D2
int rled = D5;     // Red LED connected to digital pin D5
int gled = D6;     // Green LED connected to digital pin D6

int op;            // Variable to store flame sensor value

void setup() {
  Serial.begin(9600);

  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fire, INPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);

  s1.attach(sp1);
  s2.attach(sp2);

  // Start with everything off
  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(rled, LOW);
  digitalWrite(gled, HIGH);
}

void loop() {
  op = analogRead(fire);
  Serial.print("Flame Sensor Value: ");
  Serial.println(op);

  if (op < 200) {  // Flame detected
    Serial.println("🔥 Fire detected!");
    
    s1.write(90);
    s2.write(180);

    digitalWrite(gled, LOW);
    digitalWrite(relay, LOW);   // Activate relay (assuming LOW triggers it)
    digitalWrite(buzzer, HIGH);
    digitalWrite(rled, HIGH);
    
    delay(500);
    digitalWrite(rled, LOW);
    digitalWrite(buzzer, LOW);
    delay(500);
  } 
  else if (op >= 200) {  // No flame
    Serial.println("✅ No fire detected.");
    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, LOW);
    digitalWrite(rled, LOW);
    digitalWrite(gled, HIGH);
    
    s1.write(0);
    s2.write(0);
    delay(1000);
  } 
  else {
    Serial.println("⚠️ Sensor error");
  }
}
