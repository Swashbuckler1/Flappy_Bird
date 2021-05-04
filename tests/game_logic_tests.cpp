#include <catch2/catch.hpp>
#include <screen.h>

using flappybird::Bird;
using flappybird::Barrel;
using flappybird::Screen;
using glm::vec2;

TEST_CASE("Acceleration") {
    Screen screen(vec2(0, 0), vec2(100, 100));
    screen.AdvanceOneFrame();
    REQUIRE(screen.GetBird().GetVelocity().y == 0.19f);
    REQUIRE(screen.GetBird().GetPosition() == vec2(50, .19));
}

TEST_CASE("Add barrel") {
    Screen screen(vec2(0, 0), vec2(100, 100));

    for (size_t i = 0; i < 200; i++) {
        screen.AdvanceOneFrame();
    }
    REQUIRE(screen.GetBarrels().size() == 2);

    SECTION("8 more barrels") {
        for (size_t i = 0; i < 800; i++) {
            screen.AdvanceOneFrame();
        }
        REQUIRE(screen.GetBarrels().size() == 10);
    }
}

TEST_CASE("Pause/Resume") {
    Screen screen(vec2(0, 0), vec2(100, 100));
    
    for (size_t i = 0; i < 1000; i++) {
        screen.AdvanceOneFrame();
    }
    screen.Pause();
    for (Barrel& barrel : screen.GetBarrels()) {
        REQUIRE(barrel.GetVelocity() == vec2(0, 0));
    }
    REQUIRE(screen.GetBird().GetVelocity() == vec2(0, 0));
    
    SECTION("Resume") {
        screen.Resume();
        for (Barrel& barrel : screen.GetBarrels()) {
            REQUIRE(barrel.GetVelocity() == vec2(1.5, 0));
        }
        
        REQUIRE(screen.GetBird().GetVelocity().y == 0);
        screen.AdvanceOneFrame();
        REQUIRE(screen.GetBird().GetVelocity().y == 0.19f);
    }
}
