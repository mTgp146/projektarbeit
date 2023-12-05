#include "background.h"
#include <stdlib.h>

Background::Background() {
    for (int x = 0; x < 512; x += 2) {
        int y = rand() % 512; 
        int color = rand() % 3;
        if (color == 0) {
            particles.push_back(BackgroundParticle(x, y, BackgroundParticle::COLOR::RED));
        } else if (color == 1) {
            particles.push_back(BackgroundParticle(x, y, BackgroundParticle::COLOR::GREEN));
        } else {
            particles.push_back(BackgroundParticle(x, y, BackgroundParticle::COLOR::BLUE));
        }
    }
}

void Background::update() {
    for (auto& particle : particles) {
        particle.update();
    }
}

std::list<BackgroundParticle> Background::getParticles() const {
    return particles;
}