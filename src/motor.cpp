#include "../includes/motor.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

Motor::Motor(int numberOfMotors) : states(Eigen::VectorXd::Zero(numberOfMotors)), tags(numberOfMotors) {
}

void Motor::setMotorState(int motorIndex, double state) {
    if (motorIndex >= 0 && motorIndex < states.size()) {
        states[motorIndex] = state;
    } else {
        throw std::out_of_range("Motor index is out of range");
    }
}

double Motor::getMotorState(int motorIndex) const {
    if (motorIndex >= 0 && motorIndex < states.size()) {
        return states[motorIndex];
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
    std::cout << "\u001b[35mMotor States:\u001b[0m" << std::endl;
    for (size_t i = 0; i < states.size(); ++i) {
        std::cout << "Motor " << i << " [" << tags[i] << "]: " << std::fixed << std::setprecision(2) << states[i] << std::endl;
    }
}
