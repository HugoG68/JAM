/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Create object
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Object {
    public:
        Object();
        ~Object();
        Object(std::string file, int posx, int posy, float scalex, float scaley);
        Object(std::string file, int posx, int posy, float scalex, float scaley, int rotation);
        void drawBackground(sf::RenderWindow &window);
        void setScale(const sf::Vector2f& scale);
        void setPosition(int posx, int posy);
        void setTexture(std::string png);
        bool _isVisible;
    private:
        sf::Texture _Texture;
        sf::Sprite _Sprite;
};