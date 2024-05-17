/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** button
*/

#include "Button.hpp"

Button::Button()
{

}

Button::Button(std::string texture, int posx, int posy, float scalex, float scaley)
{
    if (!_texture.loadFromFile(texture)) {
        std::cout << "Erreur de chargement de l'image" << std::endl;
    } else {
        _sprite.setTexture(_texture);
        _sprite.setPosition(posx, posy);
        _sprite.setScale(scalex, scaley);
        sf::FloatRect bounds = _sprite.getLocalBounds();
        _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
        _isBuy = false;
    }
}

Button::~Button()
{

}

void Button::display(sf::RenderWindow& window)
{
    window.draw(_sprite);
}

bool Button::isClicked(const sf::RenderWindow& window)
{
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    if (_sprite.getGlobalBounds().contains(mousePos))
        return true;
    else
        return false;
}

void Button::setScale(const sf::Vector2f& scale)
{
    _sprite.setScale(scale);
}