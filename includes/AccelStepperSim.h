// AccelStepperSim.h
#ifndef AccelStepperSim_h
#define AccelStepperSim_h

unsigned long micros();

class AccelStepperSim {
public:
    AccelStepperSim(int type, int pin1, int pin2, int pin3, int pin4);
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

    // Additional simulation-specific methods
    void printState();
    float getRotations() const;

private:
    int _interfaceType;
    long _currentPos;
    long _targetPos;
    float _maxSpeed;
    float _acceleration;
    float _speed;
    unsigned long _lastStepTime;
    float _stepInterval;
    bool _direction; // true for CW, false for CCW

    // Private methods
    void updatePosition();
};

#endif
