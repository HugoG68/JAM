/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Text
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Text {
public:
    Text();
    Text(std::string text, sf::Color color, int posx, int posy, sf::Vector2f scale);
    Text(std::string text, std::string font,sf::Color color, int posx, int posy, sf::Vector2f scale);
    Text(std::string str, sf::Color color, int x, int y, int size);
    void draw(sf::RenderWindow &window) const;
    void setContent(const std::string& content);
    void setPosition(const sf::Vector2f& position);

private:
    sf::Font _font;
    sf::Text _text;
};