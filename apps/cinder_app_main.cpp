#include "flappybird_app.h"

using flappybird::FlappyBirdApp;

void prepareSettings(FlappyBirdApp::Settings* settings) {
    settings -> setResizable(false);
}

CINDER_APP(FlappyBirdApp, ci::app::RendererGl, prepareSettings);

