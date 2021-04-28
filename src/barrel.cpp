#include "barrel.h"

namespace flappybird {


    Barrel::Barrel(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
        top_left_ = top_left;
        bottom_right_ = bottom_right;
        color_ = ci::Color(0, 1,0);
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
}
