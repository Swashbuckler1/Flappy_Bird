#include "bird.h"
namespace flappybird {

    Bird::Bird(const glm::vec2 &position, const glm::vec2 &velocity) {
        position_ = position;
        velocity_ = velocity;
    }

    glm::vec2 &Bird::GetPosition() {
        return position_;
    }

    const glm::vec2 &Bird::GetVelocity() const {
        return velocity_;
    }

    void Bird::UpdatePosition() {
        UpdateVelocity();
        position_ += velocity_;
    }

    void Bird::StopMoving() {
        velocity_.x = 0;
        velocity_.y = 0;
    }

    const bool Bird::IsOnGround() const {
        return position_.y == 0;
    }

    void Bird::UpdateVelocity() {
        velocity_.y -= acceleration;
    }
}// namespace flappybird
