#include "bird.h"
namespace flappybird {

    Bird::Bird(const glm::vec2 &position, const glm::vec2 &velocity) {
        position_ = position;
        velocity_ = velocity;
    }
}

