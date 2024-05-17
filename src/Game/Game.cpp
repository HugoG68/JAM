/*
** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** Game
*/

#include "Game.hpp"
#include "../Player/Player.hpp"

Game::Game() : _window(sf::VideoMode(1920, 1080), "Crimson Clicker"), _score(0),
    _clickValue(1)
{
    Player p("ttt");
    _window.setFramerateLimit(60);
}

Game::~Game()
{
    _window.close();
}

void Game::run()
{
    while (_window.isOpen())
    {
        handleInput();
        update();
    }
}

void Game::update()
{
    _window.clear(); 
    _window.display();
}

void Game::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

void Game::addScore(int value)
{
    _score += value;
}

int Game::getScore() const
{
    return _score;
}

void Game::setClickValue(int value)
{
    _clickValue = value;
}

int Game::getClickValue() const
{
    return _clickValue;
}