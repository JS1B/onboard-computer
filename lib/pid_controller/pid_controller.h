#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <functional>

template <typename T>
class PIDController {
public:
    PIDController(
        double kP, double kI, double kD, double integralLimit,
        std::function<T(const T&, const T&)> add,
        std::function<T(const T&, const T&)> subtract,
        std::function<T(const T&, double)> multiply,
        std::function<T()> zero,
        std::function<T(const T&, double)> clampLength,
        std::function<bool(const T&)> isSmall,
        T initialValue);

    void update(const T& currentError, double dt);
    T getOutput() const;

private:
    double kP, kI, kD;
    double integralLimit;
    T integralError;
    T previousError;
    T output;

    // Function pointers for operations
    std::function<T(const T&, const T&)> add;
    std::function<T(const T&, const T&)> subtract;
    std::function<T(const T&, double)> multiply;
    std::function<T()> zero;
    std::function<T(const T&, double)> clampLength;
    std::function<bool(const T&)> isSmall;
};

// Include template implementation in the header
#include "pid_controller.tpp"

#endif // PID_CONTROLLER_H