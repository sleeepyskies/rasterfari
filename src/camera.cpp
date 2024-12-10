#include "camera.hpp"

namespace Rasterfari {

Camera::Camera() : m_direction(Vector3f(0.f)), m_position(Point3f(0.0f)) {}

Camera::Camera(Point3f position, Vector3f direction)
    : m_direction(direction), m_position(position) {}

} // namespace Rasterfari