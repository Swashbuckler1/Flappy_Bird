#include "plane.h"

namespace flappybird {

    Plane::Plane(const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3,
                 const glm::vec2 &velocity) {
        point1_ = point1;
        point2_ = point2;
        point3_ = point3;
        velocity_ = velocity;

        color_ = ci::Color(0, 0, 1);
    }

    void Plane::UpdatePosition() {
        point1_.x -= velocity_.x;
        point1_.y -= velocity_.y;

        point2_.x -= velocity_.x;
        point2_.y -= velocity_.y;

        point3_.x -= velocity_.x;
        point3_.y -= velocity_.y;
    }

    void Plane::SetVelocity(const glm::vec2 &velocity) {
        velocity_ = velocity;
    }

    void Plane::StopMoving() {
        velocity_.x = 0;
        velocity_.y = 0;
    }
    const ci::Color Plane::GetColor() const {
        return color_;
    }
    const glm::vec2 &Plane::GetPoint1() const {
        return point1_;
    }
    const glm::vec2 &Plane::GetPoint2() const {
        return point2_;
    }
    const glm::vec2 &Plane::GetPoint3() const {
        return point3_;
    }

    void Plane::HandleBirdCollision(Bird &bird) {
        if (HasBirdHit(bird)) {
            bird.StopMoving();
        }
    }
    
    bool Plane::HasBirdHit(Bird &bird) {
        return glm::distance(bird.GetPosition(), point3_) <= point2_.y - point1_.y
                - bird.GetRadius();
    }

}// namespace flappybird