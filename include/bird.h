#ifndef FINAL_PROJECT_BIRD_H
#define FINAL_PROJECT_BIRD_H

#include <vector>
#include "cinder/gl/gl.h"

namespace flappybird {
    class Bird {
    public:
        Bird() = default;
        
        Bird(const glm::vec2& position, const glm::vec2& velocity);
        
    private:
        glm::vec2 position_;
        glm::vec2 velocity_;
    };
}
#endif //FINAL_PROJECT_BIRD_H
