#include "screen.h"

using glm::vec2;

namespace flappybird {
    Screen::Screen(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;
        screen_size_ = (int) (bottom_right_.y - top_left_.y);
        keep_adding_barrels_ = true;
        keep_adding_planes_ = true;
        score_ = 0;
    }

    void Screen::Display() {
        ci::gl::color(bird_.GetColor());
        ci::gl::drawSolidCircle(bird_.GetPosition(),
                                bird_.GetRadius());

        for (Barrel &barrel : barrels_) {
            ci::gl::color(barrel.GetColor());
            ci::gl::drawSolidRect(ci::Rectf(barrel.GetTopLeft(), barrel.GetBottomRight()));
        }

        for (Plane &plane : planes_) {
            ci::gl::color(plane.GetColor());
            ci::gl::drawSolidTriangle(plane.GetPoint1(), plane.GetPoint2(), plane.GetPoint3());
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
        
        if (keep_adding_planes_) {
            if (frame_rate_ % kFramePartition_ == 0) {
                AddPlane();
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
                keep_adding_planes_ = false;
                for (Barrel &barrel : barrels_) {
                    barrel.StopMoving();
                }

                for (Plane &plane : planes_) {
                    plane.StopMoving();
                }
            }
            barrel.HandleBirdCollision(bird_);
            barrel.UpdatePosition();
        }
        
        for (Plane &plane : planes_) {
            if (plane.HasBirdHit(bird_)) {
                keep_adding_planes_ = false;
                keep_adding_barrels_ = false;
                for (Plane &plane : planes_) {
                    plane.StopMoving();
                }

                for (Barrel &barrel : barrels_) {
                    barrel.StopMoving();
                }
            }
            plane.HandleBirdCollision(bird_);
            plane.UpdatePosition();
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
        int random_height = rand() % (screen_size_ - kMinimumSpaceBetweenBarrels_ - kMinimumBarrelLength_) +
                             kMinimumBarrelLength_;
        Barrel top_barrel(vec2(screen_size_ - kBarrelWidth_, 0), vec2(screen_size_, random_height),
                          kBarrelVelocity_);
        Barrel bottom_barrel(vec2(screen_size_ - kBarrelWidth_, random_height + kMinimumSpaceBetweenBarrels_),
                             vec2(screen_size_, screen_size_), kBarrelVelocity_);
        barrels_.push_back(top_barrel);
        barrels_.push_back(bottom_barrel);
    }

    void Screen::AddPlane() {
        int random_point = rand() % (screen_size_ - kPlaneEdgeLength_);
        
        Plane plane(vec2(screen_size_, random_point), vec2(screen_size_, random_point + kPlaneEdgeLength_),
                    vec2(screen_size_ - (kPlaneEdgeLength_ * sqrt(3) / 2), 
                         (random_point + random_point + kPlaneEdgeLength_) / 2),
                    kPlaneVelocity_);
        planes_.push_back(plane);
    }
    
    void Screen::ResetGameState() {
        barrels_.clear();
        planes_.clear();
        score_ = 0;

        bird_.ResetBird(kInitialPosition_, kInitialVelocity_);
        keep_adding_barrels_ = true;
        keep_adding_planes_ = true;
    }
    void Screen::Pause() {
        keep_adding_barrels_ = false;
        keep_adding_planes_ = false;

        for (Barrel &barrel : barrels_) {
            barrel.StopMoving();
        }
        
        for (Plane& plane : planes_) {
            plane.StopMoving();
        }
        
        bird_.StopMoving();
    }
    void Screen::Resume() {
        bird_.ResetAccelerations();
        for (Barrel &barrel : barrels_) {
            barrel.SetVelocity(kBarrelVelocity_);
        }

        for (Plane& plane : planes_) {
            plane.SetVelocity(kPlaneVelocity_);
        }

        keep_adding_barrels_ = true;
        keep_adding_planes_ = true;
    }
    
    std::vector<Barrel> &Screen::GetBarrels() {
        return barrels_;
    }
}// namespace flappybird
