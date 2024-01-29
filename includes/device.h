#ifdef DEVICE_H
#define DEVICE_H

#include <iostream>

class Device {
public:
    Device(int numberOfMotors, int sizeOfMatrix);
    void initialize();
    void printStates();
};


#endif // DEVICE_H
