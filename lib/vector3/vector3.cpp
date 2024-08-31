#include "vector3.h"

// Constructors
Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

// Vector operations
void Vector3::add(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector3::subtract(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector3::multiply(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void Vector3::divide(double scalar) {
    if (scalar == 0) {
        return;
    }
    x /= scalar;
    y /= scalar;
    z /= scalar;
}

double Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

void Vector3::normalize() {
    double len = length();
    if (len <= 0) {
        return;
    }
    divide(len);
}

void Vector3::clamp(double min, double max) {
    x = std::fmin(std::fmax(x, min), max);
    y = std::fmin(std::fmax(y, min), max);
    z = std::fmin(std::fmax(z, min), max);
}

void Vector3::clampLength(double max) {
    if (length() <= max) {
        return;
    }
    normalize();
    multiply(max);
}

double Vector3::dot(const Vector3& v) const {
    return x * v.x + y * v.y + z * v.z;
}

// Utility methods
Vector3 Vector3::added(const Vector3& v) const {
    Vector3 result = *this;
    result.add(v);
    return result;
}

Vector3 Vector3::subtracted(const Vector3& v) const {
    Vector3 result = *this;
    result.subtract(v);
    return result;
}

Vector3 Vector3::multiplied(double scalar) const {
    Vector3 result = *this;
    result.multiply(scalar);
    return result;
}

Vector3 Vector3::divided(double scalar) const {
    Vector3 result = *this;
    if (scalar != 0) {
        result.divide(scalar);
    }
    return result;
}

Vector3 Vector3::normalized() const {
    Vector3 result = *this;
    double len = length();
    if (len > 0) {
        result.divide(len);
    }
    return result;
}

// Static utility methods
Vector3 Vector3::static_add(const Vector3& a, const Vector3& b) {
    return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3 Vector3::static_subtract(const Vector3& a, const Vector3& b) {
    return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector3 Vector3::static_multiply(const Vector3& v, double scalar) {
    return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
}

Vector3 Vector3::zero() {
    return Vector3(0.0, 0.0, 0.0);
}

Vector3 Vector3::static_clamp(const Vector3& v, double min, double max) {
    return Vector3(
        std::fmin(std::fmax(v.x, min), max),
        std::fmin(std::fmax(v.y, min), max),
        std::fmin(std::fmax(v.z, min), max)
    );
}

Vector3 Vector3::static_clampLength(const Vector3& v, double max) {
    if (v.length() <= max) {
        return v;
    }
    Vector3 result = v.normalized();
    result.multiply(max);
    return result;
}

bool Vector3::static_isSmall(const Vector3& v) {
    double epsilon = 1e-6;
    return std::fabs(v.x) < epsilon && std::fabs(v.y) < epsilon && std::fabs(v.z) < epsilon;
}

// Overloaded operators
Vector3 Vector3::operator+(const Vector3& v) const {
    return added(v);
}

Vector3 Vector3::operator-(const Vector3& v) const {
    return subtracted(v);
}

Vector3 Vector3::operator*(double scalar) const {
    return multiplied(scalar);
}

Vector3 Vector3::operator/(double scalar) const {
    return divided(scalar);
}

// Stream operators for easy input/output
std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3& v) {
    is >> v.x >> v.y >> v.z;
    return is;
}
