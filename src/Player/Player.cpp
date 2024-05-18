/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::string textureurl) : frameWidth(250), frameHeight(400), currentFrame(0), animationTimer(0.0f), animationSpeed(0.00f) {
    texture.loadFromFile(textureurl);
    sprite.setTexture(texture);
    sprite.setPosition(100, 300);
    sf::Vector2f scale (0.5, 0.5);
    sprite.setScale(scale);
}

void Player::update(float deltaTime) {
    sf::Vector2f position2 = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        texture.loadFromFile("assets/solo_man_jetpack.png");
        sprite.setTexture(texture);
        velocity.y = -300;
    } else if (position2.y > 650 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        texture.loadFromFile("assets/run.png");
        sprite.setTexture(texture);
        animationTimer += deltaTime;
        if (animationTimer >= animationSpeed) {
            animationTimer = 0.0f;
            currentFrame = (currentFrame + 1) % (texture.getSize().x / frameWidth);
            sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
        }
    } else {
        texture.loadFromFile("assets/man_sans_flamme.png");
        sprite.setTexture(texture);
    }
    velocity.y += gravity * deltaTime;
    sprite.move(velocity * deltaTime);
    sf::Vector2f position = sprite.getPosition();

    if (position.y >= 760) {
        position.y = 760;
        sprite.setPosition(position);   
        velocity.y = 0;
    }
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}