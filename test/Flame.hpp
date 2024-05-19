#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Particle.hpp"

class Flame {
public:
    Flame(float x, float y);

    void update(float dt);
    void draw(sf::RenderWindow& window);

private:
    std::vector<std::unique_ptr<Particle>> particles;
    float spawnInterval;
    float timeSinceLastSpawn;
    float originX;
    float originY;

    void spawnParticle();
};

Flame::Flame(float x, float y) : originX(x), originY(y), spawnInterval(0.05f), timeSinceLastSpawn(0.0f) {}

void Flame::update(float dt) {
    timeSinceLastSpawn += dt;

    if (timeSinceLastSpawn >= spawnInterval) {
        timeSinceLastSpawn -= spawnInterval;
        spawnParticle();
    }

    for (auto& particle : particles) {
        particle->update(dt);
    }

    particles.erase(std::remove_if(particles.begin(), particles.end(),
                                   [](const std::unique_ptr<Particle>& p) { return !p->isAlive(); }),
                    particles.end());
}

void Flame::draw(sf::RenderWindow& window) {
    for (const auto& particle : particles) {
        particle->draw(window);
    }
}

void Flame::spawnParticle() {
    particles.push_back(std::make_unique<Particle>(originX, originY));
}
