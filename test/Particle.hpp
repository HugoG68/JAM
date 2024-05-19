#pragma once
#include <SFML/Graphics.hpp>

class Particle {
public:
    Particle(float x, float y);

    void update(float dt);
    void draw(sf::RenderWindow& window) const;

    bool isAlive() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float lifetime;
    float maxLifetime;
};

Particle::Particle(float x, float y) : lifetime(0), maxLifetime(2.0f) {
    shape.setPosition(x, y);
    shape.setRadius(2.0f);
    shape.setFillColor(sf::Color::Yellow);

    // Random initial velocity
    velocity.x = static_cast<float>(rand() % 50 - 25);
    velocity.y = static_cast<float>(rand() % 50 - 50);
}

void Particle::update(float dt) {
    lifetime += dt;
    if (lifetime < maxLifetime) {
        shape.move(velocity * dt);
        float ratio = lifetime / maxLifetime;
        shape.setFillColor(sf::Color(255, 255 * (1 - ratio), 0, 255 * (1 - ratio)));
    }
}

void Particle::draw(sf::RenderWindow& window) const {
    if (lifetime < maxLifetime) {
        window.draw(shape);
    }
}

bool Particle::isAlive() const {
    return lifetime < maxLifetime;
}
