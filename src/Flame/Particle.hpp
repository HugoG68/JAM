#pragma once
#include <SFML/Graphics.hpp>

class Particle {
public:
    Particle(float x, float y);

    void updateParticle(float dt);
    void drawParticle(sf::RenderWindow& window) const;

    bool isFlameAlive() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float lifetime;
    float maxLifetime;
};
