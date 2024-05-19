/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Flame
*/

#include "Flame.hpp"

Flame::Flame(float x, float y) : spawnInterval(0.05f), timeSinceLastSpawn(0), originX(x), originY(y)
{

}

void Flame::updateFlame(float dt) {
    timeSinceLastSpawn += dt;

    if (timeSinceLastSpawn >= spawnInterval) {
        timeSinceLastSpawn -= spawnInterval;
        spawnParticle();
    }

    for (auto& particle : particles) {
        particle->updateParticle(dt);
    }

    particles.erase(std::remove_if(particles.begin(), particles.end(),
                                   [](const std::unique_ptr<Particle>& p) { return !p->isFlameAlive(); }),
                    particles.end());
}

void Flame::drawFlame(sf::RenderWindow& window) {
    for (const auto& particle : particles) {
        particle->drawParticle(window);
    }
}

void Flame::spawnParticle() {
    particles.push_back(std::make_unique<Particle>(originX, originY));
}
