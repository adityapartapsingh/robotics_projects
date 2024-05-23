#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

#define x A0
#define y A1
#define z A2

char *data;

int x_val;
int y_val;
int z_val;

int x_val2;
int y_val2;
int z_val2;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    
    pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(z, INPUT);
    x_val2 = analogRead(x);
  y_val2 = analogRead(y);
  z_val2 = analogRead(z);
}

void loop()
{   x_val = analogRead(x);
  y_val = analogRead(y);
  z_val = analogRead(z);

  int x_axis = x_val - x_val2;
  int y_axis = y_val - y_val2;
  int z_axis = z_val - z_val2;
// Serial.println(x_axis);
// Serial.println(y_axis);
// Serial.println(z_axis);

if(y_axis >= 30)
  {
    data="F";
    Serial.println("Forward");
  }
  else if(y_axis <= -40)
  {
    data="B";
    Serial.println("Backward");
  }
  else if(x_axis >=38)
  {
    data="R";
    Serial.println("Right");
  }
  else if(x_axis <= -35)
  {
    data="L";
    Serial.println("Left");
  }
  else
  {
    data="0";
    Serial.println("Stop");
  }

  
    driver.send((uint8_t *)data, strlen(data));
    driver.waitPacketSent();
    delay(1000);
}