#include<AFMotor.h>
#include<Servo.h>

Servo myservo;

AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);


String command;

void setup(){
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
myservo.attach(9);
myservo.write(90);
  pinMode(A5,INPUT); //ir
  pinMode(A0,OUTPUT);//buzzer
  

}

void loop(){
    if(Serial.available()>0){
    command="";
    delay(200);
    command=Serial.readString();
    Serial.println(command);
    delay(2);
    }

    if (command=="L"){
      turnLeft(); 
      delay(500);
    }
    else if (command=="R"){
      turnRight();
      delay(500);
    }
    else if (command=="F"){
      Forward();
    }
    else if (command=="B"){
      Backward();
    }

    else if (command=="0"|| command=="S"){
      moveStop();
    }
   else if (command=="M"){
      boton();
    }
    else if (command=="N"){
      botoff();
    }
else if(command=="A"){
  myservo.write(90);
  delay(500);
   myservo.write(120);
  delay(500);
   myservo.write(150);
  delay(500);
   myservo.write(180);
  delay(500);
   myservo.write(150);
  delay(500);
   myservo.write(120);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(60);
  delay(500);
  myservo.write(30);
  delay(500);
  myservo.write(0);
  delay(500);
  myservo.write(30);
  delay(500);
   myservo.write(60);
  delay(500);
   myservo.write(90);
  delay(500);

}
   

    if(digitalRead(A5)==1){
      command='N';
      digitalWrite(A0, HIGH);
      delay(200);
       digitalWrite(A0, LOW);
      delay(200);
       digitalWrite(A0, HIGH);
      delay(200);
       digitalWrite(A0, LOW);
      delay(200);
       digitalWrite(A0, HIGH);
      delay(200);
      digitalWrite(A0, LOW);
      delay(200);
    }
    
  }
   


void moveStop(){
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  
}

void Forward(){
    motor2.run(FORWARD);
    motor3.run(FORWARD);
}

void Backward(){
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
}


void turnRight(){
  motor2.run(BACKWARD);
  motor3.run(FORWARD);

}

void turnLeft(){
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
}

void boton(){
  motor1.run(FORWARD); 
  motor4.run(FORWARD);
}
void botoff(){
  motor1.run(RELEASE); 
  motor4.run(RELEASE);
}