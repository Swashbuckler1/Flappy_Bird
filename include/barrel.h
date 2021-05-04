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

        /**
         * Getter for top left
         * @return vec2 for top left
         */
        glm::vec2 GetTopLeft();

        /**
         * Getter for bottom right
         * @return vec2 for bottom right
         */
        glm::vec2 GetBottomRight();
        
        /**
         * Getter for velocity
         * @return vec2 for velocity
         */
        glm::vec2 GetVelocity();

        /**
         * Getter for color
         * @return color_ member variable
         */
        const ci::Color GetColor() const;

        /**
         * Checks if bird collided with barrel
         * @param bird Bird reference
         * @return bool if bird hit or not
         */
        bool HasBirdHit(Bird& bird);

        /**
         * Checks if bird has hit vertical
         * @param bird Bird reference 
         * @return bool is bird hit vertical or not
         */
        bool HasBirdHitVertical(Bird& bird);

        /**
         * Checks if bird is within the width of the barrel
         * @param bird Bird reference
         * @return bool if within width
         */
        bool BarrelWidthContainsBird(Bird& bird);

        /**
         * Stops bird when it hits the barrel
         * @param bird Bird reference
         */
        void HandleBirdCollision(Bird& bird);

        /**
         * Moves barrel to the left
         */
        void UpdatePosition();
        
        /**
         * Sets velocity to 0
         */
        void StopMoving();
        
        /**
         * Setter for velocity
         * @param velocity vec2 for velocity
         */
        void SetVelocity(const glm::vec2 &velocity);

    private:
        glm::vec2 top_left_;
        glm::vec2 bottom_right_;
        glm::vec2 velocity_;
        ci::Color color_;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_BARREL_H
