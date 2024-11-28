#include "camera.cpp"

Camera::Camera() {
    m_position  = Point3f(0.f);
    m_direction = Vector3f(0.f);
}

Camera::Camera(Point3f position, Vector3f direction) {
    m_position  = position;
    m_direction = direction;
}