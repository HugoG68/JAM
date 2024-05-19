#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Particle.hpp"

class Flame {
public:
    Flame(float x, float y);

    void updateFlame(float dt);
    void drawFlame(sf::RenderWindow& window);

private:
    std::vector<std::unique_ptr<Particle>> particles;
    float spawnInterval;
    float timeSinceLastSpawn;
    float originX;
    float originY;

    void spawnParticle();
};
