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
        
        const float GetRadius() const;

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

        /**
         * Setter for position
         * @param position vec2 for position
         */
        void SetPosition(const glm::vec2 &position);

        /**
         * Setter for velocity
         * @param velocity vec2 for velocity
         */
        void SetVelocity(const glm::vec2 &velocity);
        
        /**
         * Sets the y-coordinate of the bird at the top
         */
        void SetPositionAtTop();

        /**
         * Getter for color
         * @return color_ member variable
         */
        const ci::Color GetColor() const;
        
        /**
         * Getter for drag acceleration
         * @return float representing drag acceleration
         */
        const float GetDragAcceleration() const;
        
        /**
         * Resets kinematic variables
         * @param position vec2 for position
         * @param velocity vec2 for velocity
         */
        void ResetBird(const glm::vec2 &position, const glm::vec2 &velocity);
        
        /**
         * Sets gravity and drag acceleration to initial states
         */
        void ResetAccelerations();

    private:
        glm::vec2 position_;
        glm::vec2 velocity_;
        const float kRadius_ = 40;
        const float initial_gravity_ = 0.19f;
        float gravity_;
        const float initial_drag_acceleration = 10;
        float drag_acceleration_;

        ci::Color color_;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_BIRD_H
