#include "barrel.h"

namespace flappybird {


    Barrel::Barrel(const glm::vec2 &top_left, const glm::vec2 &bottom_right, const glm::vec2 &velocity) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;
        velocity_ = velocity;
        color_ = ci::Color(0, 1, 0);
    }

    glm::vec2 Barrel::GetTopLeft() {
        return top_left_;
    }

    glm::vec2 Barrel::GetBottomRight() {
        return bottom_right_;
    }

    glm::vec2 Barrel::GetVelocity() {
        return velocity_;
    }

    const ci::Color Barrel::GetColor() const {
        return color_;
    }
    bool Barrel::HasBirdHit(Bird &bird) {
        return HasBirdHitHorizontal(bird) && BarrelWidthContainsBird(bird);
    }
    bool Barrel::HasBirdHitHorizontal(Bird &bird) {
        return (bird.GetPosition().y < top_left_.y &&
               bird.GetPosition().y > bottom_right_.y)
                || (bird.GetPosition().y > top_left_.y && bird.GetPosition().y < bottom_right_.y);
    }
    bool Barrel::BarrelWidthContainsBird(Bird &bird) {
        return bird.GetPosition().x > top_left_.x &&
               bird.GetPosition().x < bottom_right_.x;
    }
    void Barrel::HandleBirdCollision(Bird &bird) {
        if (HasBirdHit(bird)) {
            bird.StopMoving();
        }
    }
    void Barrel::UpdatePosition() {
        top_left_.x -= velocity_.x;
        bottom_right_.x -= velocity_.x;
    }
    void Barrel::StopMoving() {
        velocity_.x = 0;
        velocity_.y = 0;
    }
    void Barrel::SetVelocity(const glm::vec2 &velocity) {
        velocity_ = velocity;
    }
}// namespace flappybird
