#include "screen.h"

using glm::vec2;

namespace flappybird {
    Screen::Screen(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;

        birds_.push_back(bird_);
        barrels_.push_back(Barrel(vec2(535, 535), vec2(565, 1070), kBarrelVelocity_));
        barrels_.push_back(Barrel(vec2(535, 0), vec2(565, 400), kBarrelVelocity_));
    }

    void Screen::Display() {
        //AddBarrel();
        for (Bird &bird : birds_) {
            ci::gl::color(bird.GetColor());
            ci::gl::drawSolidCircle(bird.GetPosition(),
                                    radius_);
        }

        for (Barrel &barrel : barrels_) {
            ci::gl::color(barrel.GetColor());
            ci::gl::drawSolidRect(ci::Rectf(barrel.GetTopLeft(), barrel.GetBottomRight()));
        }
    }

    void Screen::AdvanceOneFrame() {
        for (Barrel &barrel : barrels_) {
            for (Bird &bird : birds_) {
                if (IsBirdOnGround()) {
                    bird.StopMoving();
                } else if (IsBirdAtTop()) {
                    bird.GetPosition().y = top_left_.y;
                }
                
                barrel.HandleBirdCollision(bird);
                bird.UpdateVelocity();
                bird.UpdatePosition();
            }
        }
    }

    Bird &Screen::GetBird() {
        return bird_;
    }

    std::vector<Bird> &Screen::GetBirds() {
        return birds_;
    }

    bool Screen::IsBirdOnGround() {
        return bird_.GetPosition().y == bottom_right_.y;
    }

    bool Screen::IsBirdAtTop() {
        return bird_.GetPosition().y == top_left_.y;
    }
    void Screen::AddBarrel() {
        int top_left_x = rand() % (int) top_left_.x;
        vec2 top_left((float) top_left_x, 0);

        int bottom_right_y = rand() % (int) bottom_right_.y;
        vec2 bottom_right(top_left.x + kBarrelWidth_, bottom_right_y);

        Barrel barrel(top_left, bottom_right, kBarrelVelocity_);
        barrels_.push_back(barrel);
    }
}// namespace flappybird
