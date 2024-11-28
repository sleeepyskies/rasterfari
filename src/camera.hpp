#pragma once

#include "mathy.hpp"

/**
 * TODO: add documentation
 */

namespace Rasterfari {
class Camera {
private:
    Point3f m_position;
    Vector3f m_direction;

public:
    Camera();
    Camera(Point3f position, Vector3f direction);
};

} // namespace Rasterfari