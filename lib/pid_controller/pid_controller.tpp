#include <functional>

template <typename T>
PIDController<T>::PIDController(
    double kP, double kI, double kD, double integralLimit,
    std::function<T(const T&, const T&)> add,
    std::function<T(const T&, const T&)> subtract,
    std::function<T(const T&, double)> multiply,
    std::function<T()> zero,
    std::function<T(const T&, double)> clampLength,
    std::function<bool(const T&)> isSmall,
    T initialValue)
    : kP(kP), kI(kI), kD(kD), integralLimit(integralLimit),
    integralError(initialValue), previousError(initialValue), output(zero()),
    add(add), subtract(subtract), multiply(multiply), zero(zero),
    clampLength(clampLength), isSmall(isSmall) {}

template <typename T>
void PIDController<T>::update(const T& currentError, double dt) {
    if (isSmall(currentError)) {
        integralError = zero();
        previousError = zero();
        output = zero();
        return;
    }

    // Proportional term
    T proportional = multiply(currentError, kP);

    // Integral term
    if (kI != 0) {
        integralError = add(integralError, multiply(currentError, dt));
        integralError = clampLength(integralError, integralLimit); // Integral windup limit
    }
    T integral = multiply(integralError, kI);

    // Derivative term
    T derivative = zero();
    if (kD != 0 && dt > 0) {
        derivative = multiply(subtract(currentError, previousError), kD / dt);
    }

    // Update previous error for next iteration
    previousError = currentError;

    // Combine all terms to get the final output
    output = add(add(proportional, integral), derivative);
}

template <typename T>
T PIDController<T>::getOutput() const {
    return output;
}