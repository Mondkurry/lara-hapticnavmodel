#ifndef ACCELSTEPPERSIM_H
#define ACCELSTEPPERSIM_H

#include <chrono>

class AccelStepperSim {
public:
    AccelStepperSim(int type, int pin1, int pin2 = 0, int pin3 = 0, int pin4 = 0);
    
    void moveTo(long absolute);
    void move(long relative);
    bool runSpeed();
    void setCurrentPosition(long position);
    void computeNewSpeed();
    bool run();
    void stop();
    long distanceToGo() const;
    long targetPosition() const;
    long currentPosition() const;
    void setMaxSpeed(float speed);
    void setAcceleration(float acceleration);
    void setSpeed(float speed);
    float speed() const;
    void printState() const;
    float getRotations() const;

private:
    unsigned long micros() const;
    int _interfaceType;
    long _currentPos;
    long _targetPos;
    float _maxSpeed;
    float _acceleration;
    float _speed;
    unsigned long _lastStepTime;
    unsigned long _stepInterval;
    bool _direction;

    // Not implemented in simulation but required for interface compatibility
    int _pin1, _pin2, _pin3, _pin4;
};

#endif // ACCELSTEPPERSIM_H
