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

// Typedefs for different mathematical structures.

using Vector3f = Vector3<float>;        // 3D float vector
using Vector3i = Vector3<int>;          // 3D int vector
using Vector3u = Vector3<unsigned int>; // 3D unsigned int vector

using Vector2f = Vector2<float>;        // 2D float vector
using Vector2i = Vector2<int>;          // 2D int vector
using Vector2u = Vector2<unsigned int>; // 2D unsigned int vector

using Vertex3f = Vertex3<float>;        // 3D float vertex
using Vertex3i = Vertex3<int>;          // 3D integer vertex
using Vertex3u = Vertex3<unsigned int>; // 3D unsigned integer vertex

using Point3f = Point3<float>;        // 3D float point
using Point3i = Point3<int>;          // 3D integer point
using Point3u = Point3<unsigned int>; // 3D unsigned integer point

// Inline helper functions for mathematical calculations.

template <typename Type>
inline Type distance(const Vertex3<Type> &v1, const Vertex3<Type> &v2) {
    Type dx = v2.x() - v1.x();
    Type dy = v2.y() - v1.y();
    Type dz = v2.z() - v1.z();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
} // namespace Rasterfari