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
        if (event.getCode() == ci::app::KeyEvent::KEY_SPACE) {
            for (Bird &bird : screen_.GetBirds())
                bird.GetVelocity().y -= bird.GetDragAcceleration();
        }
    }
}// namespace flappybird