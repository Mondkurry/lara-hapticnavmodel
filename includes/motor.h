#ifndef MOTOR_H
#define MOTOR_H

#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <../deps/Eigen/Dense>

class Motor {
public:
    Motor(int numberOfMotors, double defaultTPS);
    ~Motor();
    void setMotorState(int motorIndex, double state);
    double getMotorState(int motorIndex) const;
    void setMotorTag(int motorIndex, const std::string& tag);
    std::string getMotorTag(int motorIndex) const;
    void setMotorTPS(int motorIndex, double tps);
    double getMotorTPS(int motorIndex) const;
    void printAllMotorStates() const;

private:
    std::vector<std::atomic<double>> states; // std::vector of atomic<double> for motor states
    mutable std::mutex mtx;
    Eigen::VectorXd tps; // Eigen vector to hold turns per second for each motor
    std::vector<std::string> tags; // Standard vector for tags
    void adjustMotorState(int motorIndex, double targetState);
};

#endif // MOTOR_H
