/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** Game
*/

#include "DeadPage.hpp"

Dead::Dead(Text score) : _window(sf::VideoMode(1920, 1080), "Dead"),
    _background("assets/Background_1.png", 0, 0, 1.0, 1.0),
    _tittle("Tu est tomber !", "assets/Fonts/Power Punchy.otf", sf::Color::Black, 400, 200, sf::Vector2f(1.0, 1.0)),
    _home("assets/Button/Home Square Button.png", 1600, 950, 0.6, 0.6),
    _restart("assets/Button/Return Square Button.png", 1800, 950, 0.6, 0.6)
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

    _background.drawBackground(_window);
    _tittle.draw(_window);
    _home.display(_window);
    _restart.display(_window);

    _window.display();

    if (_home.isClicked(_window)) {
        _home._sprite.setScale(0.7 , 0.7);
    } else
        _home._sprite.setScale(0.6 , 0.6);
    if (_restart.isClicked(_window)) {
        _restart._sprite.setScale(0.7 , 0.7);
    } else
        _restart._sprite.setScale(0.6 , 0.6);
}

void Dead::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _home.isClicked(_window)) {
            Menu _menu;
            _window.close();
            _menu.run();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _restart.isClicked(_window)) {
            Menu _menu;
            Game _game(_menu.getCurrentDifficulty());
            _window.close();
            _game.run();
        }
    }
}

bool Dead::isClosed()
{
    return _close;
}