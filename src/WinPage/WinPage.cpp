/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** Game
*/

#include "WinPage.hpp"

Win::Win(Text score) : _window(sf::VideoMode(1920, 1080), "Win"),
    _background("assets/Background_1.png", 0, 0, 1.0, 1.0),
    _tittle("You win !", "assets/Fonts/Power Punchy.otf", sf::Color::Black, 600, 350, sf::Vector2f(1.0, 1.0)),
    _home("assets/Button/Home Square Button.png", 1600, 950, 0.6, 0.6),
    _restart("assets/Button/Return Square Button.png", 1800, 950, 0.6, 0.6),
    _flamme("assets/jet_jo.png", 950, 30, 0.7, 0.7)
{
    sf::Vector2f pos(800, 550);
    _score = score;
    _close = true;
    _score.setPosition(pos);
}

Win::~Win()
{
    _window.close();
}

void Win::run()
{
    while (_window.isOpen()) {
        handleInput();
        update();
    }
}

void Win::update()
{
    _window.clear();

    _background.drawBackground(_window);
    _tittle.draw(_window);
    _home.display(_window);
    _restart.display(_window);
    _score.draw(_window);
    _flamme.drawBackground(_window);

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

void Win::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _home.isClicked(_window)) {
            _window.close();
            Menu _menu;
            _menu._music.stop();
            _menu._win = 1;
            _menu.run();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _restart.isClicked(_window)) {
            _window.close();
            Game _game(_game.getMultiplier());
            _game.run();
        }
    }
}

bool Win::isClosed()
{
    return _close;
}