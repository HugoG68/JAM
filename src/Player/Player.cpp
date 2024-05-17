/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::string textureurl) {
    texture.loadFromFile(textureurl);
    sprite.setTexture(texture);
    sprite.setPosition(100, 300);
    sf::Vector2f scale (0.5, 0.5);
    sprite.setScale(scale);
}

void Player::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        texture.loadFromFile("assets/solo_man_jetpack.png");
        sprite.setTexture(texture);
        velocity.y = -300;
    } else {
        texture.loadFromFile("assets/man_sans_flamme.png");
        sprite.setTexture(texture);
    }
    velocity.y += gravity * deltaTime;
    sprite.move(velocity * deltaTime);

    sf::Vector2f position = sprite.getPosition();
    if (position.y >= 770) {
        position.y = 770;
        sprite.setPosition(position);   
        velocity.y = 0;
    }
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}