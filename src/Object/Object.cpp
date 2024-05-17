/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Object
*/

#include "Object.hpp"

Object::Object()
{
}

Object::~Object()
{
}

Object::Object(std::string file, int posx, int posy, float scalex, float scaley)
{
    if (!_Texture.loadFromFile(file)) {
        std::cerr << "Erreur de chargement l'image." << std::endl;
    } else {
        _Sprite.setTexture(_Texture);
        _Sprite.setPosition(posx, posy);
        _Sprite.setScale(scalex, scaley);
        _isVisible = false;
    }
}

Object::Object(std::string file, int posx, int posy, float scalex, float scaley, int rotation)
{
    if (!_Texture.loadFromFile(file)) {
        std::cerr << "Erreur de chargement l'image." << std::endl;
    } else {
        _Sprite.setTexture(_Texture);
        _Sprite.setPosition(posx, posy);
        _Sprite.setScale(scalex, scaley);
        _Sprite.rotate(rotation);
        _isVisible = false;
    }
}

void Object::drawBackground(sf::RenderWindow &window)
{
    window.draw(_Sprite);
}

void Object::setScale(const sf::Vector2f& scale)
{
    _Sprite.setScale(scale);
}

void Object::setPosition(int posx, int posy)
{
    _Sprite.setPosition(posx, posy);
}

void Object::setTexture(std::string png)
{
    _Texture.loadFromFile(png);
    _Sprite.setTexture(_Texture);
}