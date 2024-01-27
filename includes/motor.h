#ifndef MOTOR_H
#define MOTOR_H

#include <string>
#include <vector>
#include <../deps/Eigen/Dense>

class Motor {
public:
    Motor(int numberOfMotors);
    void setMotorState(int motorIndex, double state);
    double getMotorState(int motorIndex) const;
    void setMotorTag(int motorIndex, const std::string& tag);
    std::string getMotorTag(int motorIndex) const;
    void printAllMotorStates() const;

private:
    Eigen::VectorXd states; // Eigen vector to hold motor states
    std::vector<std::string> tags; // Standard vector for tags
};

#endif // MOTOR_H
