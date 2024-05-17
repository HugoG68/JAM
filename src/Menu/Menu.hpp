/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Menu
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu : public IDisplay, public Button{
    public:
        Menu();
        ~Menu();
        void run() override;
        void update() override;
        void handleInput() override;
        bool isClosed() const { return _close;};
        sf::RenderWindow _window;
        bool _close;
    protected:
        Button _start;
        Button _quit;
        Button _settings;
    private:
};