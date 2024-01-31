// import packages
#include <AccelStepper.h>


// initialize the pins for each motor
const int motor1Pins[4] = {46, 48, 50, 52};
/*const int motor2Pins[4] = {26, 27, 28, 29};
const int motor3Pins[4] = {30, 31, 32, 33};
const int motor4Pins[4] = {34, 35, 36, 37};
const int motor5Pins[4] = {38, 39, 40, 41};
const int motor6Pins[4] = {38, 39, 40, 41};
*/

int SIZE = 5;

// adjust the speed and acceleration of all motors
float motor_speed = 2200.0;
float motor_Acceleration = 15000.0;
int init_position = 0;

// stop flag is used to set the pinMode
int stop_flag1 = 44;
/*
int stop_flag2 = 44;
int stop_flag3 = 44;
int stop_flag4 = 44;
int stop_flag5 = 44;
*/

// matrix that determines the positions of the pins
float disp_matrix[ 5 ][ 5 ] = {   { 0, 0, 0, 0, 0 }, 
                                { 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0 },
                                { 0, 0, 0, 0, 0 } };


// Some Patterns
int disp_pyramid[ 5 ][ 5 ] = {  { 0, 0, 1, 0, 0 }, 
                                { 0, 0, 1, 0, 0 },
                                { 0, 1, 1, 1, 0 },
                                { 0, 1, 1, 1, 0 },
                                { 1, 1, 1, 1, 1 } };

int disp_half_matrix[ 5 ][ 5 ] = {  { 1, 0, 0, 0, 0 }, 
                                    { 1, 1, 0, 0, 0 },
                                    { 1, 1, 1, 0, 0 },
                                    { 1, 1, 1, 1, 0 },
                                    { 1, 1, 1, 1, 1 } };

int disp_square[ 5 ][ 5 ] = { { 1, 1, 1, 1, 1 }, 
                              { 1, 0, 0, 0, 1 },
                              { 1, 0, 0, 0, 1 },
                              { 1, 0, 0, 0, 1 },
                              { 1, 1, 1, 1, 1 } };

// initialize the pins for AccelStepper package
AccelStepper motor1(AccelStepper::FULL4WIRE, motor1Pins[0], motor1Pins[1], motor1Pins[2], motor1Pins[3]);
/*
AccelStepper motor2(AccelStepper::FULL4WIRE, motor2Pins[0], motor2Pins[1], motor2Pins[2], motor2Pins[3]);
AccelStepper motor3(AccelStepper::FULL4WIRE, motor3Pins[0], motor3Pins[1], motor3Pins[2], motor3Pins[3]);
AccelStepper motor4(AccelStepper::FULL4WIRE, motor4Pins[0], motor4Pins[1], motor4Pins[2], motor4Pins[3]);
AccelStepper motor5(AccelStepper::FULL4WIRE, motor5Pins[0], motor5Pins[1], motor5Pins[2], motor5Pins[3]);
AccelStepper motor6(AccelStepper::FULL4WIRE, motor5Pins[0], motor5Pins[1], motor5Pins[2], motor5Pins[3]);
*/

void setup() { 
  Serial.begin(9600);
  // initializing motor1
  pinMode(stop_flag1, OUTPUT);
  motor1.setMaxSpeed(motor_speed);
  motor1.setAcceleration(motor_Acceleration);

  //init position
  //motor1.setCurrentPosition(0);
  // motor1.runToNewPosition(400);
  //motor2.setCurrentPosition(0);
  // motor2.runToNewPosition(400);
  //motor3.setCurrentPosition(0);
  // motor3.runToNewPosition(400);
  //motor4.setCurrentPosition(0);
  // motor4.runToNewPosition(400);
  //motor5.setCurrentPosition(0);
  // motor5.runToNewPosition(400);
}

// get input from user for the matrix
void user_input(){
  int i, j;
  float val;
  // ask user for input
  Serial.println("Enter the 5x5 Values:");
  // iterate through loop and update values
  for(i=0; i<SIZE; i++){
    for(j=0; j<SIZE; j++){
      // check if any values are available in serial com
      while (Serial.available() == 0) {
      }
      val = Serial.parseFloat();
      if(val <= 1){
        disp_matrix[i][j] = val;
      }
    }
  }
  for(i=0; i<SIZE; i++){
    for(j=0; j<SIZE; j++){
      Serial.print(disp_matrix[i][j]);
      Serial.print(" ");
    }
    Serial.println(" ");
  }
}

void test_Run(){
  delay(1000);                      // wait for a second
  digitalWrite(stop_flag1, HIGH);
  motor1.runToNewPosition(350);
  motor1.runToNewPosition(0);
  motor1.runToNewPosition(350);
  digitalWrite(stop_flag1, LOW);
  //for(;;);
}

void spin_motor(int num){
  int stop_flag;
  if(num == 0){
    digitalWrite(stop_flag, HIGH);
    motor1.runToNewPosition(350);
    digitalWrite(stop_flag, LOW);
  }
  if(num == 1){
    digitalWrite(stop_flag, HIGH);
    motor2.runToNewPosition(350);
    digitalWrite(stop_flag, LOW);
  }
  if(num == 2){
    digitalWrite(stop_flag, HIGH);
    motor3.runToNewPosition(350);
    digitalWrite(stop_flag, LOW);
  }
  if(num == 3){
    digitalWrite(stop_flag, HIGH);
    motor4.runToNewPosition(350);
    digitalWrite(stop_flag, LOW);
  }
  if(num == 4){
    digitalWrite(stop_flag, HIGH);
    motor5.runToNewPosition(350);
    digitalWrite(stop_flag, LOW);
  }
  if(num == 5){
    digitalWrite(stop_flag, HIGH);
    motor6.runToNewPosition(350);
    digitalWrite(stop_flag, LOW);
  }
}

void update_positions(){
  int i, j;
  for(j=0; j<SIZE; j++){
    for(i=0; i<SIZE; i++){
      if(disp_matrix[i][j]!=0){
        spin_motor(i);
      }
      spin_motor(5);
    }
  }
}

// Main Loop
void loop() {
  user_input();
}





