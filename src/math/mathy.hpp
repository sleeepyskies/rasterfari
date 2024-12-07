/**
 * @file This file is used as an umbrella file for all other math classes
 * defined in Rasterfari. It avoids many import statements.
 */

#pragma once

#include "matrix.hpp"
#include "point.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include "vertex.hpp"

namespace Rasterfari {

/// Typedefs for different mathematical structures.

using Vector3f = Vector3<float>;        // 3D float vector
using Vector3i = Vector3<int>;          // 3D int vector
using Vector3u = Vector3<unsigned int>; // 3D unsigned int vector

using Vector2f = Vector2<float>;        // 2D float vector
using Vector2i = Vector2<int>;          // 2D int vector
using Vector2u = Vector2<unsigned int>; // 2D unsigned int vector

/**
 * A general class representing 2D vertices.
 */
template <typename Type> struct Vertex2 {
private:
    Type m_x, m_y; // data

public:
    // Default constructor for 2D points, inits x and y to 0 if no params given
    explicit Vertex2(Type x = Type(0), Type y = Type(0)) : m_x(x), m_y(y) {}

    // Getters and Setters

    Type &x() const { return &m_x; }
    Type &y() const { return &m_y; }

    // Operator overloads

    Vertex2 operator+(const Vertex2 &other) const {
        return Vertex2(this->x() + other->x(), this->y() + other->y());
    }
    Vertex2 operator-(const Vertex2 &other) const {
        return Vertex2(this->x() - other->x(), this->y() - other->y());
    }
    Vertex2 operator*(const Vertex2 &other) const {
        return Vertex2(this->x() * other->x(), this->y() * other->y());
    }
    Vertex2 operator/(const Vertex2 &other) const {
        return Vertex2(this->x() / other->x(), this->y() / other->y());
    }
    bool operator==(const Vertex2 &other) const {
        return this->x() == other->x() && this->y() == other->y();
    }
    bool operator!=(const Vertex2 &other) const {
        return this->x() != other->x() && this->y() != other->y();
    }
};

/**
 * A general class representing 3D vertices.
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
    Type &x() const { return &m_x; }
    Type &y() const { return &m_y; }
    Type &z() const { return &m_z; }

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
    Vertex3 operator+(const Vector3<Type> &vec) const {
        return Vertex3(
            this->x() + vec.x(), this->y() + vec.y(), this->z() + vec.z());
    }
    bool operator==(const Vertex3 &other) const {
        return this->x() == other->x() && this->y() == other->y() &&
               this->z() == other->z();
    }
    bool operator!=(const Vertex3 &other) const {
        return this->x() != other->x() && this->y() != other->y() &&
               this->z() != other->z();
    }
};

using Vertex2f = Vertex2<float>;        // 2D float vertex
using Vertex2i = Vertex2<int>;          // 2D integer vertex
using Vertex2u = Vertex2<unsigned int>; // 2D unsigned integer vertex
using Vertex3f = Vertex3<float>;        // 3D float vertex
using Vertex3i = Vertex3<int>;          // 3D integer vertex
using Vertex3u = Vertex3<unsigned int>; // 3D unsigned integer vertex

// Inline helper functions for mathematical calculations.

template <typename Type>
inline Type distance(const Vertex2<Type> &v1, const Vertex2<Type> &v2) {
    Type dx = v2.x() - v1.x();
    Type dy = v2.y() - v1.y();
    return std::sqrt(dx * dx + dy * dy);
}

template <typename Type>
inline Type distance(const Vertex3<Type> &v1, const Vertex3<Type> &v2) {
    Type dx = v2.x() - v1.x();
    Type dy = v2.y() - v1.y();
    Type dz = v2.z() - v1.z();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
} // namespace Rasterfari