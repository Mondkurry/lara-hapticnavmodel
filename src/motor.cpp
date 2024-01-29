#include "../includes/motor.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <chrono>

Motor::Motor(int numberOfMotors, double defaultTPS)
    : states(numberOfMotors),
      mtx(), // Initialize the mutex here
      tps(Eigen::VectorXd::Constant(numberOfMotors, defaultTPS)),
      tags(numberOfMotors) {
    for (auto& state : states) {
        state.store(0.0);
    }
}

Motor::~Motor() {
  // Destructor doesn't need to do anything specific for 'mtx'.
}

void Motor::setMotorState(int motorIndex, double state) {
    if (motorIndex >= 0 && motorIndex < states.size()) {
        states[motorIndex].store(state);
        std::thread(&Motor::adjustMotorState, this, motorIndex, state).detach();
    } else {
        throw std::out_of_range("Motor index is out of range");
    }
}

void Motor::adjustMotorState(int motorIndex, double targetState) {
    while (true) {
        double currentState = states[motorIndex].load();
        if (currentState == targetState) {
            break;
        }

        double new_state = currentState;
        double currentTPS = tps[motorIndex] * 0.1;
        if (currentState < targetState) {
            new_state = std::min(currentState + currentTPS, targetState);
        } else {
            new_state = std::max(currentState - currentTPS, targetState);
        }

        states[motorIndex].store(new_state);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

double Motor::getMotorState(int motorIndex) const {
    if (motorIndex >= 0 && motorIndex < states.size()) {
        return states[motorIndex];
    } else {
        throw std::out_of_range("Motor index is out of range");
    }
}

void Motor::setMotorTPS(int motorIndex, double tpsValue) {
    if (motorIndex >= 0 && motorIndex < tps.size()) {
        tps[motorIndex] = tpsValue;
    } else {
        throw std::out_of_range("Motor index is out of range");
    }
}

double Motor::getMotorTPS(int motorIndex) const {
    if (motorIndex >= 0 && motorIndex < tps.size()) {
        return tps[motorIndex];
    } else {
        throw std::out_of_range("Motor index is out of range");
    }
}

void Motor::setMotorTag(int motorIndex, const std::string& tag) {
    if (motorIndex >= 0 && motorIndex < tags.size()) {
        tags[motorIndex] = tag;
    } else {
        throw std::out_of_range("Motor index is out of range");
    }
}

std::string Motor::getMotorTag(int motorIndex) const {
    if (motorIndex >= 0 && motorIndex < tags.size()) {
        return tags[motorIndex];
    } else {
        throw std::out_of_range("Motor index is out of range");
    }
}

void Motor::printAllMotorStates() const {
    std::lock_guard<std::mutex> lock(mtx); // Ensure thread safety

    std::cout << "\u001b[35mMotor States:\u001b[0m" << std::endl;
    for (size_t i = 0; i < states.size(); ++i) {
        std::cout << "Motor " << i << " [" << tags[i] << "]: State = " 
                  << std::fixed << std::setprecision(2) << states[i]
                  << ", TPS = " << std::setprecision(2) << tps[i] << std::endl;
    }
    std::cout << std::endl;
}

