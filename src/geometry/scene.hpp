#pragma once

#include <memory>
#include <vector>

namespace Rasterfari {

/**
 * TDOD: Add documentation to this file!!!
 */

class Object {};

class StaticObject {};

class DyanmicObject {};

class Scene {
private:
    std::vector<std::unique_ptr<StaticObject>> m_statics;

    // Camera m_camera;

public:
    Scene();
    ~Scene();

    void addDynamicObject();
};
} // namespace Rasterfari