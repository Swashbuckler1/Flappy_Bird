#include "screen.h"

using glm::vec2;

namespace flappybird {
    Screen::Screen(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;
        kScreenSize_ = (int) (bottom_right_.y - top_left_.y);
        keep_adding_barrels_ = true;
    }

    void Screen::Display() {
        ci::gl::color(bird_.GetColor());
        ci::gl::drawSolidCircle(bird_.GetPosition(),
                                radius_);

        for (Barrel &barrel : barrels_) {
            ci::gl::color(barrel.GetColor());
            ci::gl::drawSolidRect(ci::Rectf(barrel.GetTopLeft(), barrel.GetBottomRight()));
        }
    }

    void Screen::AdvanceOneFrame() {
        if (keep_adding_barrels_) {
            if (frame_rate_ % frame_partition_ == 0) {
                AddBarrel();
            }
        }
        frame_rate_++;
        
        if (IsBirdOnGround()) {
            bird_.StopMoving();
        } else if (IsBirdAtTop()) {
            bird_.SetPositionAtTop();
        }
        bird_.UpdateVelocity();
        bird_.UpdatePosition();
        
        for (Barrel& barrel : barrels_) {
            barrel.HandleBirdCollision(bird_);
            barrel.UpdatePosition();
        }
    }

    Bird &Screen::GetBird() {
        return bird_;
    }

    bool Screen::IsBirdOnGround() {
        return bird_.GetPosition().y == bottom_right_.y;
    }

    bool Screen::IsBirdAtTop() {
        return bird_.GetPosition().y == top_left_.y;
    }

    void Screen::AddBarrel() {
        random_height_ = rand() % (kScreenSize_ - kMinimumBarrelLength - kMinimumSpaceBetweenBarrels) +
                     kMinimumBarrelLength;
        Barrel top_barrel(vec2(kScreenSize_ - kBarrelWidth_, 0), vec2(kScreenSize_, random_height_),
                      kBarrelVelocity_);
        Barrel bottom_barrel(vec2(kScreenSize_ - kBarrelWidth_, random_height_ + kMinimumSpaceBetweenBarrels),
                             vec2(kScreenSize_, kScreenSize_), kBarrelVelocity_);
        barrels_.push_back(top_barrel);
        barrels_.push_back(bottom_barrel);
    }
    void Screen::ResetGameState() {
        keep_adding_barrels_ = false;
        for (Barrel& barrel : barrels_) {
            barrel.StopMoving();
        }
        bird_.ResetBird(initial_position, initial_velocity);

        for (Barrel& barrel : barrels_) {
            barrel.SetVelocity(kBarrelVelocity_);
        }
        keep_adding_barrels_ = true;
    }
}// namespace flappybird
