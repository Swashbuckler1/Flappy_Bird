#include "screen.h"

using glm::vec2;

namespace flappybird {
    Screen::Screen(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;
        screen_size_ = (int) (bottom_right_.y - top_left_.y);
        keep_adding_barrels_ = true;
        score_ = 0;
    }

    void Screen::Display() {
        ci::gl::color(bird_.GetColor());
        ci::gl::drawSolidCircle(bird_.GetPosition(),
                                kRadius_);

        for (Barrel &barrel : barrels_) {
            ci::gl::color(barrel.GetColor());
            ci::gl::drawSolidRect(ci::Rectf(barrel.GetTopLeft(), barrel.GetBottomRight()));
        }

        ci::gl::drawString(std::to_string(score_), kScorePoint_,
                           ci::Color(255, 255, 255),
                           ci::Font(std::to_string(score_), kFontSize_));
    }

    void Screen::AdvanceOneFrame() {
        if (keep_adding_barrels_) {
            if (frame_rate_ % kFramePartition_ == 0) {
                AddBarrel();
                score_++;
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

        for (Barrel &barrel : barrels_) {
            if (barrel.HasBirdHit(bird_)) {
                keep_adding_barrels_ = false;
                for (Barrel &barrel : barrels_) {
                    barrel.StopMoving();
                }
            }
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
        int random_height_ = rand() % (screen_size_ - kMinimumBarrelLength_ - kMinimumSpaceBetweenBarrels_) +
                             kMinimumBarrelLength_;
        Barrel top_barrel(vec2(screen_size_ - kBarrelWidth_, 0), vec2(screen_size_, random_height_),
                          kBarrelVelocity_);
        Barrel bottom_barrel(vec2(screen_size_ - kBarrelWidth_, random_height_ + kMinimumSpaceBetweenBarrels_),
                             vec2(screen_size_, screen_size_), kBarrelVelocity_);
        barrels_.push_back(top_barrel);
        barrels_.push_back(bottom_barrel);
    }
    void Screen::ResetGameState() {
        barrels_.clear();
        score_ = 0;

        bird_.ResetBird(kInitialPosition_, kInitialVelocity_);
        keep_adding_barrels_ = true;
    }
    void Screen::Pause() {
        keep_adding_barrels_ = false;

        for (Barrel &barrel : barrels_) {
            barrel.StopMoving();
        }
        bird_.StopMoving();
    }
    void Screen::Resume() {
        bird_.ResetAccelerations();
        for (Barrel &barrel : barrels_) {
            barrel.SetVelocity(kBarrelVelocity_);
        }

        keep_adding_barrels_ = true;
    }
}// namespace flappybird
