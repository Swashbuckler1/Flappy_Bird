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
        
        void SetPosition(const glm::vec2 &position);

        void SetVelocity(const glm::vec2 &velocity);
        
        void SetPositionAtTop();

        const ci::Color GetColor() const;
        
        const float GetDragAcceleration() const;
        
        void ResetBird(const glm::vec2 &position, const glm::vec2 &velocity);

    private:
        glm::vec2 position_;
        glm::vec2 velocity_;
        const float initial_gravity_ = 0.19f;
        float gravity_;
        const float initial_drag_acceleration = 10;
        float drag_acceleration_;

        ci::Color color_;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_BIRD_H
