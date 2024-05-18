/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Player
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "../IFeature/IFeature.hpp"
#include "Entity/Player.hpp"

class Player:  public Entity::AEntity {
public:
    Player(std::string textureurl);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    void setTexture(std::string textureurl);
    void setScale(float x, float y);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity{0, 0};
    float gravity = 500.0f;

    sf::Texture jetpackTexture;
    sf::Texture runTexture;
    int frameWidth;
    int frameHeight;
    int currentFrame;
    float animationTimer;
    float animationSpeed;
    void updateAnimation(float deltaTime);
    bool anim;
};