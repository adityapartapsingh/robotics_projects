#include<AFMotor.h>
#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK driver(2000,13,12,10,false);

AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);


String command;

void setup(){
  Serial.begin(9600);
if (!driver.init())
         Serial.println("init failed");

  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  pinMode(A1,INPUT); //ir
  pinMode(A0,INPUT);//buzzer

}

void loop(){
//*************** bluetooth***************************
    if(Serial.available()>0){
    command="";
    delay(200);
    command=Serial.readString();
    Serial.println(command);
    delay(2);
    }

// ******************rf for gesture******************************

    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf); 
      command=(char*)buf;        
    }
 
//*****************************************************

    if (command=="L"){
      turnLeft();
      delay(500);
    }
    if (command=="R"){
      turnRight();
      delay(500);
    }
     if (command=="F"){
      Forward();
      stop();
    }
     if (command=="B"){
      Backward();
    }

     if (command=="0"|| command=="S" || command=="*"){
      moveStop();
    }
   
    
  }
   
void stop(){
  if(digitalRead(A0)==0 || digitalRead(A1)==0){
    command="0";
  }
}

void moveStop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}

void Forward(){
   motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void Backward(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}


void turnRight(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}

void turnLeft(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
