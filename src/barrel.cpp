#include "barrel.h"

namespace flappybird {

    Barrel::Barrel(const glm::vec2 &position, const glm::vec2 &velocity) {
        position_ = position;
        velocity_ = velocity;
    }
}
