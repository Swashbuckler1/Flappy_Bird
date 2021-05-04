#ifndef FINAL_PROJECT_SCREEN_H
#define FINAL_PROJECT_SCREEN_H

#include "barrel.h"
#include "bird.h"
#include "cinder/Font.h"
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

        /**
         * Getter for Barrels
         * @return vector for barrels
         */
        std::vector<Barrel> &GetBarrels();

        /**
         * Checks if the bird's y value is at the bottom
         * @return bool if on ground
         */
        bool IsBirdOnGround();

        /**
         * Checks if the bird's y value is at the top
         * @return bool if at the top 
         */
        bool IsBirdAtTop();

        /**
         * Adds barrel pairs (top/bottom) of random heights from the right
         */
        void AddBarrel();

        /**
         * 
         */
        void ResetGameState();

        /**
         * Pauses game when 'p' is pressed
         */
        void Pause();

        /**
         * Resumes game when 'r' is pressed
         */
        void Resume();

    private:
        glm::vec2 top_left_;
        glm::vec2 bottom_right_;
        const float kRadius_ = 40;
        int screen_size_;

        const glm::vec2 kInitialPosition_ = glm::vec2(50, (bottom_right_.y - top_left_.y) / 2);
        const glm::vec2 kInitialVelocity_ = glm::vec2(0, 0);
        Bird bird_ = Bird(kInitialPosition_, kInitialVelocity_);

        std::vector<Barrel> barrels_;
        const int kBarrelWidth_ = 30;
        const int kMinimumBarrelLength_ = 40;
        const int kMinimumSpaceBetweenBarrels_ = 200;
        const glm::vec2 kBarrelVelocity_ = glm::vec2(1.5, 0);
        bool keep_adding_barrels_;

        size_t frame_rate_;
        const size_t kFramePartition_ = 200;

        size_t score_;
        const glm::vec2 kScorePoint_ = glm::vec2(10, 20);
        const float kFontSize_ = 50;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_SCREEN_H
