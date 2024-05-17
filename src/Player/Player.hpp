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
    Player(sf::Texture texture) {}
    void update(float deltaTime) {}
    void draw(sf::RenderWindow window) {}

private:
    sf::Sprite sprite;
    sf::Vector2f velocity{0, 0};
    const float gravity = 500.0f;
};