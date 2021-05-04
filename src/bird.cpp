#include "bird.h"
namespace flappybird {

    Bird::Bird(const glm::vec2 &position, const glm::vec2 &velocity) {
        position_ = position;
        velocity_ = velocity;
        color_ = ci::Color(1, 0,0);
        ResetAccelerations();
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
        drag_acceleration_ = 0;
        gravity_ = 0;
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
    void Bird::SetPositionAtTop() {
        position_.y = 0;
    }
    void Bird::SetPosition(const glm::vec2 &position) {
        position_ = position;
    }
    void Bird::SetVelocity(const glm::vec2 &velocity) {
        velocity_ = velocity;
    }
    void Bird::ResetBird(const glm::vec2 &position, const glm::vec2 &velocity) {
        ResetAccelerations();
        SetVelocity(velocity);
        SetPosition(position);
    }
    void Bird::ResetAccelerations() {
        gravity_ = initial_gravity_;
        drag_acceleration_ = initial_drag_acceleration;
    }
}// namespace flappybird
