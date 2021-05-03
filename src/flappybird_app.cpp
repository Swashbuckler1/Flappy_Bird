#include "flappybird_app.h"

using glm::vec2;

namespace flappybird {

    FlappyBirdApp::FlappyBirdApp() : screen_(Screen(vec2(0, 0),
                                                    vec2(kWindowSize, kWindowSize))) {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void FlappyBirdApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        screen_.Display();
    }

    void FlappyBirdApp::update() {
        screen_.AdvanceOneFrame();
    }

    void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_SPACE:
                screen_.GetBird().GetVelocity().y -= screen_.GetBird().GetDragAcceleration();
                break;
            case ci::app::KeyEvent::KEY_ESCAPE:
                screen_.ResetGameState();
        }

        switch (event.getChar()) {
            case pause_:
                screen_.Pause();
                break;
            case resume_:
                screen_.Resume();
                break;
        }
    }
}// namespace flappybird