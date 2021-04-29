#include "barrel.h"

namespace flappybird {


    Barrel::Barrel(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;
        color_ = ci::Color(0, 1, 0);
    }

    glm::vec2 Barrel::GetTopLeft() {
        return top_left_;
    }

    glm::vec2 Barrel::GetBottomRight() {
        return bottom_right_;
    }

    const ci::Color Barrel::GetColor() const {
        return color_;
    }
    bool Barrel::HasBirdHit(Bird &bird) {
        return HasBirdHitHorizontal(bird) && BarrelWidthContainsBird(bird);
    }
    bool Barrel::HasBirdHitHorizontal(Bird &bird) {
        return bird.GetPosition().y < top_left_.y ||
               bird.GetPosition().y > bottom_right_.y;
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
}// namespace flappybird
