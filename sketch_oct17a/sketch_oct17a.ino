#include <Servo.h>
Servo servo;

int trig = 2,echo = 3;
int servoPin = 7, agl = 90,i = 1;
long distance,duration;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(agl);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration * 340/10000)/2;

  agl +=i;
  if(agl>180){
    agl = 179;
    i=-1;
    }else if(agl<0){
      agl = 1;
      i=1;
      }

  servo.write(agl);
  Serial.print(agl);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  delay(70);



}
