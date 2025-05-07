#include "alphabot_drivers.h"
#include "line_follower.h"

#define NUM_SENSORS 5
int sensorValues[NUM_SENSORS];
Line_follower__main_out _res;
Line_follower__main_mem _mem;

int IR_LEFT = 3, IR_RIGHT = 2; // global
bool OBS_LEFT=false, OBS_RIGHT=false;
unsigned long previoustime=millis();

void setup()
{
  init_devices();
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  forward();
  Line_follower__main_reset(&_mem);
  Serial.begin(115200);
}

void loop()
{
  AnalogRead(sensorValues);

  OBS_LEFT = !digitalRead(IR_LEFT);
  OBS_RIGHT = !digitalRead(IR_RIGHT);
  char ir = ir_read();
  int ir_front_left = 0, ir_front_right = 0;
  if (ir == 'b') { 
    ir_front_left = 1;
    ir_front_right = 1;
  } else if (ir == 'l') {
    ir_front_left = 1;
  } else if (ir == 'r') {
    ir_front_right = 1;
  }
  unsigned long currenttime=millis();
  bool sec=0;
  if(currenttime-previoustime>=500)
  {
	sec=1;
	previoustime=currenttime;
  }
  Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], ir_front_left, ir_front_right, OBS_LEFT, OBS_RIGHT, sec, &_res, &_mem);
  Serial.print(_res.v_l);
  Serial.print(" ");
  Serial.print(_res.v_r);
  Serial.print(" ");
  //Serial.println(_res.pidvalue);

  Serial.print(sensorValues[0]);
  Serial.print(" ");
  Serial.print(sensorValues[1]);
  Serial.print(" ");
  Serial.print(sensorValues[2]);
  Serial.print(" ");
  Serial.print(sensorValues[3]);
  Serial.print(" ");
  Serial.print(sensorValues[4]);
  Serial.print(" ");
  Serial.print(ir_front_left);
  Serial.print(" ");
  Serial.print(ir_front_right);
  Serial.print(" ");
  Serial.print(OBS_LEFT);
  Serial.print(" ");
  Serial.print(OBS_RIGHT);
  Serial.print(" ");


  Serial.println(" ");

  if(_res.dir == 35){
	left();
  //delay(300);
  }
  else if(_res.dir == 45){
	right();
  //delay(300);
  }
  else if(_res.dir == 15){
    forward();
    //delay(10000);
  }
  else if(_res.dir == 5){
	backward();
  }
  else if(_res.dir == 6){
	backward();
  }
  else if(_res.dir==9)
    brake();
  else if(_res.dir == 3){
    left();
    //delay(100);
    }
    else if(_res.dir == 4){
    right();
    //delay(100);
    }
    else if(_res.dir==100)
    {
      forward();
    }
  else
	forward();
  // SetSpeed(0,0);
  SetSpeed(_res.v_l,_res.v_r);
  //delay(20);
}