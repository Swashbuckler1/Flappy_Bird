#ifndef FINAL_PROJECT_FLAPPYBIRD_APP_H
#define FINAL_PROJECT_FLAPPYBIRD_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "screen.h"

namespace flappybird {
    /**
     * Game Engine
     */
    class FlappyBirdApp : public ci::app::App {
    public:
        FlappyBirdApp();

        /**
         * Implements Display function of Screen
         */
        void draw() override;

        /**
         * Implements AdvanceOneFrame function of screen
         */
        void update() override;

        /**
         * When space bar is pressed, moves bird up by 20 pixels
         * @param event KeyEvent representing space bar
         */
        void keyDown(ci::app::KeyEvent event) override;

    private:
        const size_t kWindowSize = 1070;
        Screen screen_;
    };
}// namespace flappybird
#endif//FINAL_PROJECT_FLAPPYBIRD_APP_H
