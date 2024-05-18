/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** Game
*/

#include "DeadPage.hpp"

Dead::Dead(Text score) : _window(sf::VideoMode(1920, 1080), "Dead")
{
    _score = score;
    _close = true;
}

Dead::~Dead()
{
    _window.close();
}

void Dead::run()
{
    while (_window.isOpen()) {
        handleInput();
        update();
    }
}

void Dead::update()
{
    _window.clear();

    _window.display();
}

void Dead::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

bool Dead::isClosed()
{
    return _close;
}