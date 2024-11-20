#pragma once

// Vertices

/**
 * A general class representing 2D vertices.
 */
template <typename Type> struct Vertex2 {
private:
    Type m_x, m_y; // data

public:
    // Default constructor for 2D points, inits x and y to 0 if no params given
    Vertex2(Type x = Type(0), Type y = Type(0)) : m_x(x), m_y(y) {}

    // Get x-coord
    Type x() const { return m_x; }
    // Get y-coord
    Type y() const { return m_y; }
    // Set x-coord
    void setX(const Type x) { m_x = x; }
    // Set y-coord
    void setY(const Type y) { m_y = y; }

    // Operator overloads

    Vertex2<Type> operator+(const Vertex2 &other) const {
        return Vertex2<Type>(this->x() + other->x(), this->y() + other->y());
    }
    Vertex2<Type> operator-(const Vertex2 &other) const {
        return Vertex2<Type>(this->x() - other->x(), this->y() - other->y());
    }
    Vertex2<Type> operator*(const Vertex2 &other) const {
        return Vertex2<Type>(this->x() * other->x(), this->y() * other->y());
    }
    Vertex2<Type> operator/(const Vertex2 &other) const {
        return Vertex2<Type>(this->x() / other->x(), this->y() / other->y());
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
    Vertex3(Type x = Type(0), Type y = Type(0), Type z = Type(0))
        : m_x(x), m_y(y), m_z(z) {}

    // Get x-coord
    Type x() const { return m_x; }
    // Get y-coord
    Type y() const { return m_y; }
    // Get z-coord
    Type z() const { return m_z; }
    // Set x-coord
    void setX(const Type x) { m_x = x; }
    // Set y-coord
    void setY(const Type y) { m_y = y; }
    // Set z-coord
    void setZ(const Type z) { m_z = z; }

    // Operator overloads

    Vertex3<Type> operator+(const Vertex3 &other) const {
        return Vertex3<Type>(this->x() + other->x(),
                             this->y() + other->y(),
                             this->z() + other->z());
    }
    Vertex3<Type> operator-(const Vertex3 &other) const {
        return Vertex3<Type>(this->x() - other->x(),
                             this->y() - other->y(),
                             this->z() - other->z());
    }
    Vertex3<Type> operator*(const Vertex3 &other) const {
        return Vertex3<Type>(this->x() * other->x(),
                             this->y() * other->y(),
                             this->z() * other->z());
    }
    Vertex3<Type> operator/(const Vertex3 &other) const {
        return Vertex3<Type>(this->x() / other->x(),
                             this->y() / other->y(),
                             this->z() / other->z());
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

using Vertex2f = Vertex2<float>; // 2D float vertex
using Vertex2i = Vertex2<int>;   // 2D integer vertex
using Vertex3f = Vertex3<float>; // 3D float vertex
using Vertex3i = Vertex3<int>;   // 3D integer vertex