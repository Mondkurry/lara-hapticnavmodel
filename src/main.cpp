#include "../deps/Eigen/Dense"
#include "../includes/dots.h"
#include "../includes/motor.h"
#include "../includes/utils.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

void testMotorClass() {
  // Initialize a Motor object with 5 motors
  Motor motors(5);

  // Set states and tags for each motor
  motors.setMotorState(0, 10);
  motors.setMotorTag(0, "MotorA");

  motors.setMotorState(1, -5);
  motors.setMotorTag(1, "MotorB");

  motors.setMotorState(2, 15);
  motors.setMotorTag(2, "MotorC");

  motors.setMotorState(3, 20);
  motors.setMotorTag(3, "MotorD");

  motors.setMotorState(4, -10);
  motors.setMotorTag(4, "MotorE");

  // Clear the screen
  clearScreen();

  // Print all motor states
  std::cout << "Initial Motor States:" << std::endl;
  motors.printAllMotorStates();

  //sleep for 200 milliseconds
  std::this_thread::sleep_for(std::chrono::milliseconds(200));

  // Clear the screen
  clearScreen();

  // Get and print the state and tag of a specific motor
  std::cout << "testing getMotorState() and getMotorTag()..." << std::endl;
  int motorIndex = 2; // Example: Get details of the third motor
  std::cout << "\nDetails of Motor " << motorIndex << ":" << std::endl;
  std::cout << "State: " << motors.getMotorState(motorIndex) << std::endl;
  std::cout << "Tag: " << motors.getMotorTag(motorIndex) << std::endl;
}

void dynamicMotorTesting() {
  // Initialize a Motor object with 5 motors
  Motor motors(5);
  motors.setMotorTag(0, "MotorA");
  motors.setMotorTag(1, "MotorB");
  motors.setMotorTag(2, "MotorC");
  motors.setMotorTag(3, "MotorD");
  motors.setMotorTag(4, "MotorE");

  for (int i = 0; i < 5; ++i) {
      // Increment from 0 to 1.
      for (double v = 0.1; v <= 1.0; v += 0.1) {
          motors.setMotorState(i, v);
          clearScreen();
          motors.printAllMotorStates();
          std::this_thread::sleep_for(std::chrono::milliseconds(50));
      }
      // Decrement back to 0.
      for (double v = 0.9; v >= 0; v -= 0.1) {
          motors.setMotorState(i, v);
          clearScreen();
          motors.printAllMotorStates();
          std::this_thread::sleep_for(std::chrono::milliseconds(50));
      }
  }

}

void printHeart() {
  int setup_size = 5; // 5x5 Setup
  Dots dots(setup_size, setup_size); // Create a 5x5 matrix.
  dots.printStates(); // Print the initial matrix.
  
  for (int j = 0; j < setup_size; ++j) {
  // Only need to update the unlocked column because any number of rows can be updated at any time
      dots.setUnlockedColumn(j);
      switch (j) {
        case 0:
          dots.updateRow(1, 0.8);
          dots.updateRow(2, 0.8);
          break;
        case 1:
          dots.updateRow(0, 0.5);
          dots.updateRow(3, 0.5);
          break;
        case 2:
          dots.updateRow(1, 0.8);
          dots.updateRow(4, 0.8);
          break;
        case 3:
          dots.updateRow(0, 0.5);
          dots.updateRow(3, 0.5);
          break;
        case 4:
          dots.updateRow(1, 0.8);
          dots.updateRow(2, 0.8);
          break;
      }
      clearScreen();
      dots.printStates();
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
      }
      
 }


void testDotsClass() {
  int setup_size = 5; // 5x5 Setup
  Dots dots(setup_size, setup_size); // Create a 5x5 matrix.
  dots.printStates(); // Print the initial matrix.

  for (int i = 0; i < setup_size; ++i) {
      for (int j = 0; j < setup_size; ++j) {

          if (j % 2 == 0) { // Set Unlocked Column if j is divisible by 2
              dots.setUnlockedColumn(j);
          }

          for (double v = 0.1; v <= 1.0; v += 0.1) {  // Increment from 0 to 1.
              dots.updateSingleDot(i, j, v);
              clearScreen();
              dots.printStates();
          }

          for (double v = 0.9; v >= 0; v -= 0.1) {    // Decrement back to 0.
              dots.updateSingleDot(i, j, v);
              clearScreen();
              dots.printStates();
          }

      }
  }
}


int main() {
    printHeart();
    // testDotsClass();
    // testMotorClass();
    // dynamicMotorTesting();
    return 0;
}
