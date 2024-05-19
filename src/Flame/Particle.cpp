/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Particle
*/

#include "Particle.hpp"

Particle::Particle(float x, float y) : lifetime(0), maxLifetime(2.0f) {
    shape.setPosition(x, y);
    shape.setRadius(2.0f);
    shape.setFillColor(sf::Color::Yellow);

    velocity.x = static_cast<float>(rand() % 50 - 25);
    velocity.y = static_cast<float>(rand() % 50 - 50);
}

void Particle::updateParticle(float dt) {
    lifetime += dt;
    if (lifetime < maxLifetime) {
        shape.move(velocity * dt);
        float ratio = lifetime / maxLifetime;
        shape.setFillColor(sf::Color(255, 255 * (1 - ratio), 0, 255 * (1 - ratio)));
    }
}

void Particle::drawParticle(sf::RenderWindow& window) const {
    if (lifetime < maxLifetime) {
        window.draw(shape);
    }
}

bool Particle::isFlameAlive() const {
    return lifetime < maxLifetime;
}

