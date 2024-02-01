#ifndef Accel_Stepper_h
#define Accel_Stepper_h

#include <Arduino.h>

class AccelStepperSim {
public:
    AccelStepperSim(int type, int pin1, int pin2, int pin3, int pin4);
    void setMaxSpeed(float speed);
    void setAcceleration(float acceleration);
    void moveTo(long absolute);
    void move(long relative);
    bool run();
    void setCurrentPosition(long position);
    void runToNewPosition(long position);
    void stop();
    long distanceToGo() const;
    long targetPosition() const;
    long currentPosition() const;
    void printState();

private:
    long _currentPosition;
    long _targetPosition;
    float _maxSpeed;
    float _acceleration;
    unsigned long _lastStepTime;
    float _speed;
    bool computeNewSpeed();

    // Simulated time delay for movements, not part of AccelStepper
    void simulatedDelay(unsigned long delayTime);
};

#endif // Accel_Stepper_h
