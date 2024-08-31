#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath> 
#include <iostream>

class Vector3 {
public:
    double x, y, z;

    // Constructors
    Vector3();
    Vector3(double x, double y, double z);

    // Vector operations
    void add(const Vector3& v);
    void subtract(const Vector3& v);
    void multiply(double scalar);
    void divide(double scalar);
    double length() const;
    void normalize();
    void clamp(double min, double max);
    void clampLength(double max);
    double dot(const Vector3& v) const;

    // Utility methods
    Vector3 added(const Vector3& v) const;
    Vector3 subtracted(const Vector3& v) const;
    Vector3 multiplied(double scalar) const;
    Vector3 divided(double scalar) const;
    Vector3 normalized() const;

    // Static utility methods
    static Vector3 static_add(const Vector3& a, const Vector3& b);
    static Vector3 static_subtract(const Vector3& a, const Vector3& b);
    static Vector3 static_multiply(const Vector3& v, double scalar);
    static Vector3 zero();
    static Vector3 static_clamp(const Vector3& v, double min, double max);
    static Vector3 static_clampLength(const Vector3& v, double max);
    static bool static_isSmall(const Vector3& v);

    // Overloaded operators
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(double scalar) const;
    Vector3 operator/(double scalar) const;

    // Stream operators for easy input/output
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
    friend std::istream& operator>>(std::istream& is, Vector3& v);
};

#endif // VECTOR3_H