// AccelStepperSim.cpp
#include "../includes/AccelStepperSim.h"
#include <chrono>
#include <iostream>

unsigned long micros() {
    auto now = std::chrono::high_resolution_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto value = now_ms.time_since_epoch();
    return value.count();
}

AccelStepperSim::AccelStepperSim(int type, int pin1, int pin2, int pin3, int pin4)
: _interfaceType(type), _currentPos(0), _targetPos(0), _maxSpeed(1000), _acceleration(100), _speed(0), _lastStepTime(0), _stepInterval(1000000 / _maxSpeed), _direction(true) {}

void AccelStepperSim::moveTo(long absolute) {
    _targetPos = absolute;
    computeNewSpeed();
}

void AccelStepperSim::move(long relative) {
    moveTo(_currentPos + relative);
}

bool AccelStepperSim::runSpeed() {
    if (_stepInterval == 0) {
        return false;
    }
    unsigned long currentTime = micros();
    if (currentTime - _lastStepTime >= _stepInterval) {
        if (_direction) {
            _currentPos++;
        } else {
            _currentPos--;
        }
        _lastStepTime = currentTime;
        return true;
    }
    return false;
}

void AccelStepperSim::setCurrentPosition(long position) {
    _currentPos = position;
}

void AccelStepperSim::computeNewSpeed() {
    long distanceToGo = this->distanceToGo();
    _direction = (distanceToGo > 0);
}

bool AccelStepperSim::run() {
    if (_targetPos == _currentPos) return false;
    runSpeed();
    return true;
}

void AccelStepperSim::stop() {
    _targetPos = _currentPos; // Stops any movement
}

long AccelStepperSim::distanceToGo() const {
    return _targetPos - _currentPos;
}

long AccelStepperSim::targetPosition() const {
    return _targetPos;
}

long AccelStepperSim::currentPosition() const {
    return _currentPos;
}

void AccelStepperSim::setMaxSpeed(float speed) {
    _maxSpeed = speed;
    _stepInterval = 1000000 / _maxSpeed;
}

void AccelStepperSim::setAcceleration(float acceleration) {
    _acceleration = acceleration;
}

void AccelStepperSim::setSpeed(float speed) {
    _speed = speed;
    // Recalculate _stepInterval based on new speed
    _stepInterval = 1000000 / _speed;
}

float AccelStepperSim::speed() const {
    return _speed;
}

void AccelStepperSim::printState() {
    std::cout << "Current Pos: " << _currentPos << std::endl;
    std::cout << "Target Pos: " << _targetPos << std::endl;
    std::cout << "Speed: " << _speed << std::endl;
}

float AccelStepperSim::getRotations() const {
    // Assuming 200 steps per revolution as an example
    return _currentPos / 200.0;
}
