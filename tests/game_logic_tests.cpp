#include <catch2/catch.hpp>
#include <screen.h>

using glm::vec2;
using flappybird::Screen;
using flappybird::Bird;

TEST_CASE("Acceleration") {
    Screen screen(vec2(100, 10), vec2(10, 100));
    screen.AdvanceOneFrame();
    REQUIRE(screen.GetBird().GetVelocity().y == -1.5);
    REQUIRE(screen.GetBird().GetPosition() == vec2(11.5, 533.5));
}

TEST_CASE("Bird on ground") {
    Screen screen(vec2(0, 0), vec2(100, 100));
    for (size_t i = 0; i < 356; i++) {
        screen.AdvanceOneFrame();
    }
    REQUIRE(screen.GetBird().IsOnGround() == true);
}
