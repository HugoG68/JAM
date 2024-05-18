/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::string textureurl) : frameWidth(284), frameHeight(267), currentFrame(0), animationTimer(10.0f), animationSpeed(0.40f), anim(false) {    texture.loadFromFile(textureurl);
    sprite.setTexture(texture);
    sprite.setPosition(100, 300);
    sf::Vector2f scale (0.5, 0.5);
    sprite.setScale(scale);
}

void Player::update(float deltaTime) {
    sf::Vector2f position2 = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && have_fuel() && _is_alive) {
        burn_fuel();
        texture.loadFromFile("assets/solo_man_jetpack.png");
        sprite.setTexture(texture);
        sf::Vector2f fly(0.55, 0.55);
        sprite.setScale(fly);
        sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
        velocity.y = -300;
    } else if (position2.y > 720 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        sf::Vector2f run(1.1, 1.1);
        texture.loadFromFile("assets/run.png");
        sprite.setTexture(texture);
        sprite.setScale(run);
        animationTimer += deltaTime;
        if (animationTimer >= animationSpeed) {
            animationTimer = 0.0f;
            currentFrame = (currentFrame + 1) % (texture.getSize().x / frameWidth);
            sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
        }
    } else {
        texture.loadFromFile("assets/man_sans_flamme.png");
        sprite.setTexture(texture);
        sf::Vector2f fly(0.55, 0.55);
        sprite.setScale(fly);
    }
    velocity.y += gravity * deltaTime;
    sprite.move(velocity * deltaTime);
    sf::Vector2f position = sprite.getPosition();

    if (position.y >= 760) {
        position.y = 760;
        sprite.setPosition(position);   
        velocity.y = 0;
    }
    set_pos({position.x, position.y});
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Player::setTexture(std::string textureurl) {
    if (texture.loadFromFile(textureurl)) {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    }
}

void Player::setScale(float x, float y) {
    sprite.setScale(x, y);
}