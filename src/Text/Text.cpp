/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Text
*/

#include "Text.hpp"

Text::Text()
{
    _font.loadFromFile("assets/Fonts/Default.ttf");
    _text.setFont(_font);
    _text.setString("Default");
    _text.setFillColor(sf::Color::White);
    _text.setPosition(150, 60);
    _text.scale(sf::Vector2f(1, 1));
    _text.setCharacterSize(60);
}

Text::Text(std::string str, sf::Color color, int x, int y, sf::Vector2f scale)
{
    _font.loadFromFile("assets/Fonts/Default.ttf");
    _text.setFont(_font);
    _text.setString(str);
    _text.setFillColor(color);
    _text.setPosition(x, y);
    _text.scale(scale);
}

Text::Text(std::string str, sf::Color color, int x, int y, int size)
{
    _text.setFont(_font);
    _text.setString(str);
    _text.setFillColor(color);
    _text.setPosition(x, y);
    _text.setCharacterSize(size);
}

Text::Text(std::string text, std::string font,sf::Color color, int posx, int posy, sf::Vector2f scale)
{
    _font.loadFromFile(font);
    _text.setFont(_font);
    _text.setCharacterSize(140);
    _text.setString(text);
    _text.setFillColor(color);
    _text.setPosition(posx, posy);
    _text.scale(scale);
}

void Text::draw(sf::RenderWindow &window) const {
    window.draw(_text);
}

void Text::setContent(const std::string& content)
{
    _text.setString(content);
}

void Text::setPosition(const sf::Vector2f& position)
{
    _text.setPosition(position);
}