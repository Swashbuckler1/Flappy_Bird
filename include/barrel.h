#ifndef FINAL_PROJECT_BARREL_H
#define FINAL_PROJECT_BARREL_H

#include "cinder/gl/gl.h"
#include "bird.h"

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
        Barrel(const glm::vec2 &top_left, const glm::vec2 &bottom_right, const glm::vec2 &velocity);

        glm::vec2 GetTopLeft();

        glm::vec2 GetBottomRight();

        const ci::Color GetColor() const;

        bool HasBirdHit(Bird& bird);

        bool HasBirdHitHorizontal(Bird& bird);

        bool BarrelWidthContainsBird(Bird& bird);

        void HandleBirdCollision(Bird& bird);

        void UpdatePosition();
        
        void StopMoving();
        
        void SetVelocity(const glm::vec2 &velocity);

    private:
        glm::vec2 top_left_;
        glm::vec2 bottom_right_;
        glm::vec2 velocity_;
        ci::Color color_;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_BARREL_H
