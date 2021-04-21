#ifndef FINAL_PROJECT_SCREEN_H
#define FINAL_PROJECT_SCREEN_H

#include "barrel.h"
#include "bird.h"
#include "cinder/gl/gl.h"
#include <vector>

namespace flappybird {
    /**
     * Class for screen
     */
    class Screen {
    public:
        /**
         * Explicit constructor
         * @param top_left vec2 for top left pixel
         * @param bottom_right vec2 for bottom right pixel
         */
        Screen(const glm::vec2 &top_left, const glm::vec2 &bottom_right);
        
        /**
         * Displays screen
         */
        void Display();

        /**
         * Updates position and velocity of bird
         */
        void AdvanceOneFrame();

        /**
         * Getter for Bird
         * @return Bird& for bird in screen
         */
        Bird &GetBird();

    private:
        glm::vec2 top_left_;
        glm::vec2 bottom_right_;

        glm::vec2 initial_position = glm::vec2(10, 535);
        glm::vec2 initial_velocity = glm::vec2(1.5, 0);
        Bird bird_ = Bird(initial_position, initial_velocity);
        std::vector<Barrel> barrels_;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_SCREEN_H
