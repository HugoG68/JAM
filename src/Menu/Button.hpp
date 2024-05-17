/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** button
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
    Button();
    Button(std::string texture, int posx, int posy, float scalex, float scaley);
    ~Button();

    void display(sf::RenderWindow& window);
    bool isClicked(const sf::RenderWindow& window);
    void setScale(const sf::Vector2f& scale);

    sf::Texture _texture;
    sf::Sprite _sprite;
    bool _isBuy;
protected:
};