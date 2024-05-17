/*** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Player
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "../IFeature/IFeature.hpp"

class Player {
public:
    Player(std::string textureurl);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity{0, 0};
    float gravity = 500.0f;
};