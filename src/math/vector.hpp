#pragma once

namespace Rasterfari {

/**
 * A general class representing 2D vectors. TODO
 */
template <typename Type> struct Vector2 {
private:
    Type m_x, m_y; // data

public:
};

/**
 * A general class representing 3D vectors.
 */
template <typename Type> struct Vector3 {
private:
    Type m_x, m_y, m_z; // data

public:
    // Default constructor for 3D vectors, inits x, y, z to 0 if no params given
    Vector3(Type x = Type(0), Type y = Type(0), Type z = Type(0))
        : m_x(x), m_y(y), m_z(z) {}

    // Getters and Setters

    const Type &x() const { return m_x; }
    const Type &y() const { return m_y; }
    const Type &z() const { return m_z; }
    Type &x() { return m_x; }
    Type &y() { return m_y; }
    Type &z() { return m_z; }

    /// @brief Find the length of this vector
    Type length() const { return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z); }

    /// @brief Normalizes the vector in place
    void makeNormal() {
        Type length = (*this).length();
        m_x /= length;
        m_y /= length;
        m_z /= length;
    }

    // Operator overloads

    Vector3 operator+(const Vector3 &other) const {
        return Vertex3(this->x() + other->x(),
                       this->y() + other->y(),
                       this->z() + other->z());
    }
    Vector3 operator-(const Vector3 &other) const {
        return Vertex3(this->x() - other->x(),
                       this->y() - other->y(),
                       this->z() - other->z());
    }
    Vector3 operator*(const Vector3 &other) const {
        return Vertex3(this->x() * other->x(),
                       this->y() * other->y(),
                       this->z() * other->z());
    }
    Vector3 operator/(const Vector3 &other) const {
        return Vertex3(this->x() / other->x(),
                       this->y() / other->y(),
                       this->z() / other->z());
    }
    Vector3 operator+(const Type value) const {
        return Vector3<Type>(
            this->x() + value, this->y() + value, this->z() + value);
    }
    Vector3 operator-(const Type value) const {
        return Vector3<Type>(
            this->x() - value, this->y() - value, this->z() - value);
    }
    Vector3 operator*(const Type value) const {
        return Vector3<Type>(
            this->x() * value, this->y() * value, this->z() * value);
    }
    Vector3 operator/(const Type value) const {
        return Vector3<Type>(
            this->x() / value, this->y() / value, this->z() / value);
    }
    Vector3 operator+=(const Vector3 &other) const {
        m_x += other.x();
        m_y += other.y();
        m_z += other.z();
    }
    Vector3 operator-=(const Vector3 &other) const {
        m_x -= other.x();
        m_y -= other.y();
        m_z -= other.z();
    }
    Vector3 operator*=(const Vector3 &other) const {
        m_x *= other.x();
        m_y *= other.y();
        m_z *= other.z();
    }
    Vector3 operator/=(const Vector3 &other) const {
        m_x /= other.x();
        m_y /= other.y();
        m_z /= other.z();
    }
    Vector3 operator+=(const Type value) const {
        m_x += value;
        m_y += value;
        m_z += value;
    }
    Vector3 operator-=(const Type value) const {
        m_x -= value;
        m_y -= value;
        m_z -= value;
    }
    Vector3 operator*=(const Type value) const {
        m_x *= value;
        m_y *= value;
        m_z *= value;
    }
    Vector3 operator/=(const Type value) const {
        m_x /= value;
        m_y /= value;
        m_z /= value;
    }
    bool operator==(const Vector3 &other) const {
        return this->x() == other->x() && this->y() == other->y() &&
               this->z() == other->z();
    }
    bool operator!=(const Vector3 &other) const {
        return this->x() != other->x() && this->y() != other->y() &&
               this->z() != other->z();
    }
};

using Vector3f = Vector3<float>;        // 3D float vector
using Vector3i = Vector3<int>;          // 3D int vector
using Vector3u = Vector3<unsigned int>; // 3D unsigned int vector

} // namespace Rasterfari