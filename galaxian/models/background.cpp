#include "background.h"
#include <stdlib.h>

Background::Background() {
    for (int x = 0; x < 128; x += 1) {
        int y = rand() % 512;
        int color = rand() % 3;
        if (color == 0) {
            particles[x].setValues(x*4, y, BackgroundParticle::COLOR::RED);
        } else if (color == 1) {
            particles[x].setValues(x*4, y, BackgroundParticle::COLOR::GREEN);
        } else {
            particles[x].setValues(x*4, y, BackgroundParticle::COLOR::BLUE);
        }
    }
}

void Background::update() {
    for (auto& particle : particles) {
        particle.update();
    }
}

std::array<BackgroundParticle, 128> Background::getParticles() const {
    return particles;
}