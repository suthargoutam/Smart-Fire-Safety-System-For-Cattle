#include <Servo.h>

Servo rodServo;   // Controls metal rod
Servo doorServo;  // Controls door

int rodPin = D5;    // Servo for rod
int doorPin = D6;   // Servo for door
int fire = A0;      // Flame sensor analog pin
int buzzer = D1;    // Buzzer
int relay = D2;     // Relay for water/fan
int rled = D7;      // Red LED (fire alert)
int gled = D4;      // Green LED (safe mode)

int fireValue;

void setup() {
  Serial.begin(115200);

  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fire, INPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);

  rodServo.attach(rodPin);
  doorServo.attach(doorPin);

  // Initial (safe) state
  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(rled, LOW);
  digitalWrite(gled, HIGH);

  // Servos at initial positions
  rodServo.write(0);    // Rod up (holding rope)
  doorServo.write(0);   // Door closed
}

void loop() {
  fireValue = analogRead(fire);
  Serial.print("Flame Sensor Value: ");
  Serial.println(fireValue);

  if (fireValue < 200) {   // 🔥 Fire detected
    Serial.println("🔥 Fire detected! Releasing animal and activating safety system!");

    // 1️⃣ Drop the metal rod
    rodServo.write(90);    // Moves rod down to release rope

    // 2️⃣ Open the animal door
    doorServo.write(120);  // Adjust angle for your door mechanism

    // 3️⃣ Turn ON safety alerts
    digitalWrite(gled, LOW);
    digitalWrite(relay, LOW);   // Activate pump/fan
    digitalWrite(buzzer, HIGH);
    digitalWrite(rled, HIGH);

    delay(500);
    digitalWrite(rled, LOW);
    digitalWrite(buzzer, LOW);
    delay(500);
  } 
  else {  // ✅ No fire
    Serial.println("✅ No fire. System normal.");

    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, LOW);
    digitalWrite(rled, LOW);
    digitalWrite(gled, HIGH);

    // Reset servos to normal state
    rodServo.write(0);    // Rod up (secure rope)
    doorServo.write(0);   // Door closed

    delay(1000);
  }
}
