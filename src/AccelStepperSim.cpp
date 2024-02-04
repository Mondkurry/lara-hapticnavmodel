#include "AccelStepperSim.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread> // For std::this_thread::sleep_for

unsigned long AccelStepperSim::micros() const {
    auto now = std::chrono::high_resolution_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto value = now_us.time_since_epoch();
    return value.count();
}

AccelStepperSim::AccelStepperSim(int type, int pin1, int pin2, int pin3, int pin4)
: _interfaceType(type), _currentPos(0), _targetPos(0), _maxSpeed(1000), _acceleration(100), _speed(0), _lastStepTime(0), _stepInterval(1000000 / _maxSpeed), _direction(true), _pin1(pin1), _pin2(pin2), _pin3(pin3), _pin4(pin4) {}

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
        if (_speed > 0) {
            _currentPos++;
        } else if (_speed < 0) {
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
    if (_targetPos == _currentPos) {
        _speed = 0;
        return;
    }
    long distanceToGo = this->distanceToGo();
    float requiredSpeed = sqrt(2.0 * abs(distanceToGo) * _acceleration);
    _direction = (distanceToGo > 0);
    if (!_direction) {
        requiredSpeed = -requiredSpeed;
    }
    setSpeed(requiredSpeed);
}

bool AccelStepperSim::run() {
    if (_targetPos == _currentPos) return false;
    runSpeed();
    computeNewSpeed();
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
    computeNewSpeed();
}

void AccelStepperSim::setAcceleration(float acceleration) {
    _acceleration = acceleration;
    computeNewSpeed();
}

void AccelStepperSim::setSpeed(float speed) {
    _speed = speed;
    // Recalculate _stepInterval based on new speed
    if (_speed != 0) {
        _stepInterval = 1000000 / abs(_speed);
    }
}

float AccelStepperSim::speed() const {
    return _speed;
}

void AccelStepperSim::printState() const {
    std::cout << "Current pos: " << _currentPos << ", Target pos: " << _targetPos << ", Speed: " << _speed << std::endl;
}

float AccelStepperSim::getRotations() const {
    return _currentPos / 200.0; // Assuming 200 steps per revolution
}

