#include "bird.h"
namespace flappybird {

    Bird::Bird(const glm::vec2 &position, const glm::vec2 &velocity) {
        position_ = position;
        velocity_ = velocity;
        color_ = ci::Color(1, 0,0);
    }

    glm::vec2 &Bird::GetPosition() {
        return position_;
    }

    glm::vec2 &Bird::GetVelocity() {
        return velocity_;
    }

    void Bird::UpdatePosition() {
        position_ += velocity_;
    }

    void Bird::StopMoving() {
        velocity_.x = 0;
        velocity_.y = 0;
    }

    void Bird::UpdateVelocity() {
        velocity_.y += gravity_;
    }
    
    const ci::Color Bird::GetColor() const {
        return color_;
    }
    
    const float Bird::GetDragAcceleration() const {
        return drag_acceleration_;
    }
}// namespace flappybird
