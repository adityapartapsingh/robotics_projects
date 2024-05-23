#include<NewPing.h>
#define TRIG_PIN A0               // trig pin for ultrasonic sensor
#define ECHO_PIN A1 
#define buzzer 7
#define MAX_DISTANCE 200

int distance;
String mode;
boolean value=false;
NewPing sonar(TRIG_PIN,ECHO_PIN,MAX_DISTANCE);

int dit=100;

void setup() {
  
  Serial.begin(9600);

pinMode(buzzer,OUTPUT);

   distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  if(Serial.available()>0){
    mode="";
    delay(100);
    mode=Serial.readString();
    delay(100);
    Serial.println(mode);
    }
int distance = readPing();


if(distance<30){
  digitalWrite(7, HIGH);
  delay(300);
  digitalWrite(7, LOW);
  Serial.println("in range");
  
}
if(mode=="ON"){
  //dit
  digitalWrite(7, HIGH);
  delay(dit);
  digitalWrite(7, LOW);
  delay(dit);
   digitalWrite(7, HIGH);
  delay(dit);
  digitalWrite(7, LOW);
  delay(dit);
   digitalWrite(7, HIGH);
  delay(dit);
  digitalWrite(7, LOW);
  delay(dit);

  Serial.println("in manual");
  value="true";
}
if(mode=="OFF")
digitalWrite(7, LOW);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0){
    cm = 250;
  }
  return cm;
}