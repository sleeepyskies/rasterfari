/**
 * @file This file holds all vector specfic definitions and operations.
 */

#pragma once

namespace Rasterfari {

/**
 * MARK: Vector2
 * @brief A Type generic class for 2 dimensional vectors.
 */
template <typename Type> struct Vector2 {
private:
    Type m_x, m_y; // data

public:
    // Default constructor for 3D vectors, inits x, y, z to 0 if no params given
    Vector2(Type x = Type(0), Type y = Type(0)) : m_x(x), m_y(y) {}

    // Getters and Setters

    const Type &x() const { return m_x; }
    const Type &y() const { return m_y; }
    Type &x() { return m_x; }
    Type &y() { return m_y; }

    /// @brief Find the length of this vector.
    Type length() const { return std::sqrt(m_x * m_x + m_y * m_y); }

    /// @brief Returns this vector but normalized.
    Vector2 normalized() const {
        Type invLength = (Type) 1 / (*this).length();
        return Vector2(m_x * invLength, m_y * invLength);
    }

    /// @brief Returns the sum of this vectors components.
    Type sum() const { return m_x + m_y; }

    /// @brief Computes the dot product between this vector and other.
    Type dot(const Vector2 &other) const { return (*this * other).sum() }

    // Operator overloads

    Vector2 operator+(const Vector2 &other) const {
        return Vector2(this->x() + other->x(), this->y() + other->y());
    }
    Vector2 operator-(const Vector2 &other) const {
        return Vector2(this->x() - other->x(), this->y() - other->y());
    }
    Vector2 operator*(const Vector2 &other) const {
        return Vector2(this->x() * other->x(), this->y() * other->y());
    }
    Vector2 operator/(const Vector2 &other) const {
        return Vector2(this->x() / other->x(), this->y() / other->y());
    }
    Vector2 operator+(const Type value) const {
        return Vector2(this->x() + value, this->y() + value);
    }
    Vector2 operator-(const Type value) const {
        return Vector2(this->x() - value, this->y() - value);
    }
    Vector2 operator*(const Type value) const {
        return Vector2(this->x() * value, this->y() * value);
    }
    Vector2 operator/(const Type value) const {
        return Vector2(this->x() / value, this->y() / value);
    }
    Vector2 operator+=(const Vector2 &other) const {
        m_x += other.x();
        m_y += other.y();
    }
    Vector2 operator-=(const Vector2 &other) const {
        m_x -= other.x();
        m_y -= other.y();
    }
    Vector2 operator*=(const Vector2 &other) const {
        m_x *= other.x();
        m_y *= other.y();
    }
    Vector2 operator/=(const Vector2 &other) const {
        m_x /= other.x();
        m_y /= other.y();
    }
    Vector2 operator+=(const Type value) const {
        m_x += value;
        m_y += value;
    }
    Vector2 operator-=(const Type value) const {
        m_x -= value;
        m_y -= value;
    }
    Vector2 operator*=(const Type value) const {
        m_x *= value;
        m_y *= value;
    }
    Vector2 operator/=(const Type value) const {
        m_x /= value;
        m_y /= value;
    }
    bool operator==(const Vector2 &other) const {
        return this->x() == other->x() && this->y() == other->y();
    }
    bool operator!=(const Vector2 &other) const {
        return this->x() != other->x() && this->y() != other->y();
    }
};

/**
 * MARK: Vector3
 * @brief A Type generic class for 3 dimensional vectors.
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

    /// @brief Returns this vec tor but normalized.
    Vector3 normalized() {
        Type invLength = (Type) 1 / (*this).length();
        return Vector3(m_x * invLength, m_y * invLength, m_z * invLength);
    }

    /// @brief Returns the sum of this vectors components.
    Type sum() const { return m_x + m_y + m_z; }

    /// @brief Computes the dot product between this vector and other.
    Type dot(const Vector3 &other) const { return (*this * other).sum() }

    // Operator overloads

    Vector3 operator+(const Vector3 &other) const {
        return Vector3(this->x() + other->x(),
                       this->y() + other->y(),
                       this->z() + other->z());
    }
    Vector3 operator-(const Vector3 &other) const {
        return Vector3(this->x() - other->x(),
                       this->y() - other->y(),
                       this->z() - other->z());
    }
    Vector3 operator*(const Vector3 &other) const {
        return Vector3(this->x() * other->x(),
                       this->y() * other->y(),
                       this->z() * other->z());
    }
    Vector3 operator/(const Vector3 &other) const {
        return Vector3(this->x() / other->x(),
                       this->y() / other->y(),
                       this->z() / other->z());
    }
    Vector3 operator+(const Type value) const {
        return Vector3(this->x() + value, this->y() + value, this->z() + value);
    }
    Vector3 operator-(const Type value) const {
        return Vector3(this->x() - value, this->y() - value, this->z() - value);
    }
    Vector3 operator*(const Type value) const {
        return Vector3(this->x() * value, this->y() * value, this->z() * value);
    }
    Vector3 operator/(const Type value) const {
        return Vector3(this->x() / value, this->y() / value, this->z() / value);
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
} // namespace Rasterfari