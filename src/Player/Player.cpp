/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(sf::Texture texture) : sprite(texture) {
    sprite.setPosition(100, 300);
}

void Player::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        velocity.y = -300;
    }

    velocity.y += gravity * deltaTime;
    sprite.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow window) {
    window.draw(sprite);
}