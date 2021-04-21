#include "flappybird_app.h"

using glm::vec2;

namespace flappybird {

    FlappyBirdApp::FlappyBirdApp() : screen_(Screen(vec2(0, 0), 
                                                    vec2(kWindowSize, kWindowSize))) {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void FlappyBirdApp::draw() {
        screen_.Display();
    }

    void FlappyBirdApp::update() {
        screen_.AdvanceOneFrame();
    }

    void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
        if (event.getCode() == ci::app::KeyEvent::KEY_SPACE) {
            screen_.GetBird().GetPosition().y += 20;
        }
    }
}