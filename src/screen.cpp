#include "screen.h"

namespace flappybird {

    Screen::Screen(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;
    }

    void Screen::Display() {

    }

    void Screen::AdvanceOneFrame() {
        if (bird_.IsOnGround()) {
            bird_.StopMoving();
        }
        bird_.UpdatePosition();
    }

    Bird &Screen::GetBird() {
        return bird_;
    }
}

