/**
 * @file This file holds all point specfic definitions and operations.
 */
#pragma once

namespace Rasterfari {
template <typename Type> struct Point3 {
private:
    Type m_x, m_y, m_z; // data
public:
    /// @brief Default constructor for Point3 inits x, y, z
    /// is given.
    Point3(Type x, Type y, Type z) : m_x(x), m_y(y), m_z(z) {}

    /// @brief Constructor that initlaizes all member variables to val.
    Point3(Type val) : m_x(val), m_y(val), m_z(val) {}

    // Getters and Setters

    const Type &x() const { return m_x; }
    const Type &y() const { return m_y; }
    const Type &z() const { return m_z; }
    Type &x() { return m_x; }
    Type &y() { return m_y; }
    Type &z() { return m_z; }

    // Operator Overloads

    Point3 operator+(const Point3 &other) const {
        return Point3(this->x() + other.x(),
                      this->y() + other.y(),
                      this->z() + other.z());
    }
    Point3 operator-(const Point3 &other) const {
        return Point3(this->x() - other.x(),
                      this->y() - other.y(),
                      this->z() - other.z());
    }
    Point3 operator*(const Point3 &other) const {
        return Point3(this->x() * other.x(),
                      this->y() * other.y(),
                      this->z() * other.z());
    }
    Point3 operator/(const Point3 &other) const {
        return Point3(this->x() / other.x(),
                      this->y() / other.y(),
                      this->z() / other.z());
    }
    bool operator==(const Point3 &other) const {
        return this->x() == other->x() && this->y() == other->y() &&
               this->z() == other->z();
    }
    bool operator!=(const Point3 &other) const {
        return this->x() != other->x() && this->y() != other->y() &&
               this->z() != other->z();
    }
};
} // namespace Rasterfari