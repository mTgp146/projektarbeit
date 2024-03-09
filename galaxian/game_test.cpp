#include "gtest/gtest.h"
#include "model.h"
#include <chrono>
#include <thread>

namespace {
  
TEST(GALAXIP, InitalState) {
    Galaxip galaxip;
    EXPECT_EQ(galaxip.getX(), 240);
}

TEST(GALAXIP, MoveLeft) {
    using namespace std::chrono_literals;
    Galaxip galaxip;
    std::this_thread::sleep_for(1s);
    galaxip.moveGalaxip(Galaxip::LEFT);
    EXPECT_LT(galaxip.getX(), 240);
}

TEST(GALAXIP, MoveRight) {
    using namespace std::chrono_literals;
    Galaxip galaxip;
    std::this_thread::sleep_for(1s);
    galaxip.moveGalaxip(Galaxip::RIGHT);
    EXPECT_GT(galaxip.getX(), 240);
}

TEST(ALIEN, InitalState) {
    Alien alien;
    alien.setPositionInFormation(0);
    EXPECT_EQ(alien.getRect().x, 110);
    EXPECT_EQ(alien.getRect().y, 86);
}

TEST(ALIEN, MoveLeft) {
    using namespace std::chrono_literals;
    Alien alien;
    alien.setPositionInFormation(0);
    std::this_thread::sleep_for(1s);
    alien.moveAlien();
    EXPECT_LT(alien.getRect().x, 110);
}

TEST(BACKGROUND, InitalState) {
    BackgroundParticle background;
    background.setValues(0, 0, BackgroundParticle::RED);
    EXPECT_EQ(background.getRect().x, 0);
    EXPECT_EQ(background.getRect().y, 0);
    using namespace std::chrono_literals;
    background.update();
    background.update();
    EXPECT_EQ(background.getRect().y, 1);
}

TEST(PROJECTILE, InitalState) {
    Projectile projectile(Projectile::GALAXIP, 0, 300);
    EXPECT_EQ(projectile.getRect().x, 0);
    EXPECT_EQ(projectile.getRect().y, 300);
    projectile.setAlive(true);
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    projectile.moveProjectile();
    EXPECT_LT(projectile.getRect().y, 300);
}

TEST(MODEL, InitalState) {
    Model model;
    EXPECT_EQ(model.getPoints(), 0);
    model.addPoints(Points::Values::GREEN_FORMATION);
    EXPECT_EQ(model.getPoints(), 30);
    model.resetPoints();
    EXPECT_EQ(model.getPoints(), 0);
    model.initAliens();
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    model.moveAliens();
    EXPECT_LT(model.getGreenAlien(60).getRect().x, 110);
}

}  // namespace