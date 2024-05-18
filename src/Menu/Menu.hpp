/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Menu
*/

#pragma once

#include "../IDisplay/IDisplay.hpp"
#include "../Text/Text.hpp"
#include "../Object/Object.hpp"
#include "../Music/Music.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

typedef enum {
    UnknowType = 0,
    Easy,
    Medium,
    Hard,
} DifficultyType;

class Menu : public IDisplay, public Button, public Text, public Object, public Music{
    public:
        Menu();
        ~Menu();
        void run() override;
        void update() override;
        void handleInput() override;
        bool isClosed();
        sf::RenderWindow _window;
        bool _close;
    protected:
        Button _start;
        Button _quit;
        Button _settings;
        Text _tittle;
        Text _tittle2;
        Object _background;
        Object _jetback;
        Music _music;
    private:
};
