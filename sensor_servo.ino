#include<Servo.h>
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm,thresh=30;
 Servo myservo;
void setup() {
  myservo.attach(9);
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  for(int i=1;i<10;i++){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;     
  if(cm<=30)
  {
    myservo.write(180);
    delay(3000);
    myservo.write(0);
  }}
}
