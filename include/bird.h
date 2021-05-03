#ifndef FINAL_PROJECT_BIRD_H
#define FINAL_PROJECT_BIRD_H

#include "cinder/gl/gl.h"
#include <vector>

namespace flappybird {
    /**
     * Class for Bird
     */
    class Bird {
    public:
        Bird() = default;

        /**
         * Explicit constructor
         * @param position vec2 for position
         * @param velocity vec2 for velocity
         */
        Bird(const glm::vec2 &position, const glm::vec2 &velocity);

        /**
         * Getter for position
         * @return vec2& for position
         */
        glm::vec2 &GetPosition();
   
        /**
         * Getter for velocity
         * @return vec2& for velocity
         */
        glm::vec2 &GetVelocity();

        /**
         * Adjusts position based on velocity vector
         */
        void UpdatePosition();

        /**
         * Adjusts y-velocity based on gravitational acceleration
         */
        void UpdateVelocity();

        /**
         * Sets velocity to 0
         */
        void StopMoving();
        
        void SetPositionAtTop();

        const ci::Color GetColor() const;
        
        const float GetDragAcceleration() const;

    private:
        glm::vec2 position_;
        glm::vec2 velocity_;
        float gravity_ = 0.19f;
        float drag_acceleration_ = 10;

        ci::Color color_;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_BIRD_H
