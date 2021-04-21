#ifndef FINAL_PROJECT_BARREL_H
#define FINAL_PROJECT_BARREL_H

#include "cinder/gl/gl.h"

namespace flappybird {
    /**
     * Class for green barrels
     */
    class Barrel {
    public:
        Barrel() = default;
        
        /**
         * Explicit constructor
         * @param position vec2 for position
         * @param velocity vec2 for velocity
         */
        Barrel(const glm::vec2& position, const glm::vec2& velocity);
        
    private:
        const size_t kWidth = 30;
        glm::vec2 position_;
        glm::vec2 velocity_;
    };
}
#endif //FINAL_PROJECT_BARREL_H
