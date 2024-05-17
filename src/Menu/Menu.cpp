/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu() : _window(sf::VideoMode(1920, 1080), "JetPack Menu"),
    _close(true),
    _start("assets/Button/Start Button.png", 950, 500, 1.0, 1.0),
    _quit("assets/Button/Quit Button.png", 950, 800, 1.0, 1.0),
    _settings("assets/Button/Settings Button.png", 950, 650, 1.0, 1.0)
{

}

Menu::~Menu()
{
    _window.close();
}

void Menu::run()
{
    while (_window.isOpen())
    {
        handleInput();
        update();
    }
}

void Menu::update()
{
    _window.clear();
    _start.display(_window);
    _quit.display(_window);
    _settings.display(_window);
    _window.display();

    if (_start.isClicked(_window)) {
        _start._sprite.setScale(0.55 , 0.55);
    } else
        _start._sprite.setScale(0.5 , 0.5);
    if (_quit.isClicked(_window)) {
        _quit._sprite.setScale(0.55 , 0.55);
    } else
        _quit._sprite.setScale(0.5 , 0.5);
    if (_settings.isClicked(_window)) {
        _settings._sprite.setScale(0.55 , 0.55);
    } else
        _settings._sprite.setScale(0.5 , 0.5);
}

void Menu::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _start.isClicked(_window)) {
            _close = false;
            _window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _quit.isClicked(_window)) {
            _window.close();
        }
    }
}