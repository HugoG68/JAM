/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Player
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "../IFeature/IFeature.hpp"
#include "Entity/Player.hpp"

class Player:  public Entity::Player {
public:
    Player(std::string textureurl);
    Player(const Player& other);
    Player(Player&& other) noexcept;
    Player& operator=(const Player& other);
    Player& operator=(Player&& other) noexcept;

    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    int frameWidth;
    int frameHeight;
    std::tuple<double, double> get_pos() const {
        sf::Vector2f position = sprite.getPosition();
        return std::make_tuple(position.x, position.y);
    }
    void setTexture(std::string textureurl);
    void setScale(float x, float y);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity{0, 0};
    float gravity = 500.0f;

    sf::Texture jetpackTexture;
    sf::Texture runTexture;
    int currentFrame;
    float animationTimer;
    float animationSpeed;
    void updateAnimation(float deltaTime);
    bool anim;
};
