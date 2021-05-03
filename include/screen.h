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
        
        bool IsBirdOnGround();
        
        bool IsBirdAtTop();
        
        void AddBarrel();
        
        void ResetGameState();
        
        void Pause();
        
        void Resume();
        
    private:
        glm::vec2 top_left_;
        glm::vec2 bottom_right_;
        const float radius_ = 40;
        int kScreenSize_;

        glm::vec2 initial_position = glm::vec2(50, 535);
        glm::vec2 initial_velocity = glm::vec2(0, 0);
        Bird bird_ = Bird(initial_position, initial_velocity);
        std::vector<Barrel> barrels_;
        
        const int kBarrelWidth_ = 30;
        const int kMinimumBarrelLength = 40;
        const int kMinimumSpaceBetweenBarrels = 200;
        const glm::vec2 kBarrelVelocity_ = glm::vec2(1.5, 0);
        bool keep_adding_barrels_;
        
        size_t frame_rate_;
        const size_t frame_partition_ = 200;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_SCREEN_H
