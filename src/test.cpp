#include "../includes/AccelStepperSim.h"
#include <chrono>

void delay(int ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

// Create an instance of the AccelStepperSim class
// Arguments are type, pin1, pin2, pin3, pin4. For simulation, actual pin numbers are not used.
AccelStepperSim motor(1, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600); // Start the Serial communication to print the output
  
  motor.setMaxSpeed(1000); // Set max speed in steps per second
  motor.setAcceleration(200); // Set acceleration in steps per second squared
  
 std::cout << "Starting motor simulation..." << std::endl;
}

void loop() {
  // Test different functionalities of the simulated motor

  // Move to position 1000
  
  motor.setMaxSpeed(1000); // Set max speed in steps per second
  motor.setAcceleration(200); // Set acceleration in steps per second squared

  motor.moveTo(1000);
  while(motor.distanceToGo() != 0) {
    motor.run();
    motor.printState(); // Print the state at this step
    delay(100); // Delay to simulate time steps of 0.1 second
  }

  delay(1000); // Wait a bit before moving to the next position
  
  // Move to position -500 (reverse direction)
  motor.moveTo(-500);
  while(motor.distanceToGo() != 0) {
    motor.run();
    motor.printState(); // Print the state at this step
    delay(100); // Delay to simulate time steps of 0.1 second
  }

  delay(1000); // Wait a bit before the next command

  // Testing setSpeed and runSpeed for continuous movement
  motor.setSpeed(500); // Set speed to 500 steps per second
  for(int i = 0; i < 20; i++) { // Run for 20 iterations
    motor.runSpeed();
    motor.printState(); // Print the state at this step
    delay(100); // Delay to simulate time steps of 0.1 second
  }

  // Stop the motor
  motor.stop();
  motor.printState(); // Print the final state

  while(1) {
    // End of test, halt the loop
    delay(1000); // Just to keep the Arduino loop alive without doing anything
  }
}
