#include "AccelStepperSim.h"

AccelStepperSim::AccelStepperSim(int type, int pin1, int pin2, int pin3, int pin4)
    : _currentPosition(0), _targetPosition(0), _maxSpeed(0), _acceleration(0), _lastStepTime(millis()), _speed(0) {}

void AccelStepperSim::setMaxSpeed(float speed) {
    _maxSpeed = speed;
}

void AccelStepperSim::setAcceleration(float acceleration) {
    _acceleration = acceleration;
}

void AccelStepperSim::moveTo(long absolute) {
    _targetPosition = absolute;
}

void AccelStepperSim::move(long relative) {
    _targetPosition = _currentPosition + relative;
}

bool AccelStepperSim::run() {
    if (_currentPosition == _targetPosition) return false;

    unsigned long currentTime = millis();
    unsigned long timeElapsed = currentTime - _lastStepTime;

    // Simple simulation: move one step per call for simplicity
    if (timeElapsed >= (1000 / _maxSpeed)) {
        if (_currentPosition < _targetPosition) _currentPosition++;
        else if (_currentPosition > _targetPosition) _currentPosition--;
        _lastStepTime = currentTime;
    }

    return true;
}

void AccelStepperSim::setCurrentPosition(long position) {
    _currentPosition = position;
}

void AccelStepperSim::runToNewPosition(long position) {
    moveTo(position);
    while (run()) {
        simulatedDelay(10); // simulate a small delay for each step
    }
}

void AccelStepperSim::stop() {
    _targetPosition = _currentPosition; // stops any movement
}

long AccelStepperSim::distanceToGo() const {
    return _targetPosition - _currentPosition;
}

long AccelStepperSim::targetPosition() const {
    return _targetPosition;
}

long AccelStepperSim::currentPosition() const {
    return _currentPosition;
}

void AccelStepperSim::printState() {
    Serial.print("Current Position: ");
    Serial.print(_currentPosition);
    Serial.print(", Target Position: ");
    Serial.print(_targetPosition);
    Serial.print(", Max Speed: ");
    Serial.print(_maxSpeed);
    Serial.print(", Acceleration: ");
    Serial.println(_acceleration);
}

void AccelStepperSim::simulatedDelay(unsigned long delayTime) {
    // This is just a placeholder for actual delay logic if needed
    delay(delayTime);
}
