/**
 * @file This file holds all vertex specfic definitions and operations.
 * @attention Vertices are used within Rasterfari to represent points on meshes.
 * For more general points in space, see point.hpp
 */
#pragma once

namespace Rasterfari {

/**
 * MARK: Vertex3
 * @brief A general class representing 3D vertices.
 */
template <typename Type> struct Vertex3 {
private:
    Type m_x, m_y, m_z; // data

public:
    // Default constructor for 2D points, inits x and y to 0 if no params given
    explicit Vertex3(Type x = Type(0), Type y = Type(0), Type z = Type(0))
        : m_x(x), m_y(y), m_z(z) {}

    Vertex3(const Vertex3 &other)
        : m_x(other.x()), m_y(other.y()), m_z(other.z()) {}

    // Getters and Setters

    const Type &x() const { return m_x; }
    const Type &y() const { return m_y; }
    const Type &z() const { return m_z; }
    Type &x() { return m_x; }
    Type &y() { return m_y; }
    Type &z() { return m_z; }

    // Operator overloads

    Vertex3 operator+(const Vertex3 &other) const {
        return Vertex3(this->x() + other.x(),
                       this->y() + other.y(),
                       this->z() + other.z());
    }
    Vertex3 operator-(const Vertex3 &other) const {
        return Vertex3(this->x() - other.x(),
                       this->y() - other.y(),
                       this->z() - other.z());
    }
    Vertex3 operator*(const Vertex3 &other) const {
        return Vertex3(this->x() * other.x(),
                       this->y() * other.y(),
                       this->z() * other.z());
    }
    Vertex3 operator/(const Vertex3 &other) const {
        return Vertex3(this->x() / other.x(),
                       this->y() / other.y(),
                       this->z() / other.z());
    }
    // Vertex3 operator+(const Vector3<Type> &vec) const {
    //     return Vertex3(
    //         this->x() + vec.x(), this->y() + vec.y(), this->z() + vec.z());
    // }
    bool operator==(const Vertex3 &other) const {
        return this->x() == other->x() && this->y() == other->y() &&
               this->z() == other->z();
    }
    bool operator!=(const Vertex3 &other) const {
        return this->x() != other->x() && this->y() != other->y() &&
               this->z() != other->z();
    }
};

} // namespace Rasterfari