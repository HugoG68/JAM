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
        bool isClosed() const { return _close;};
        sf::RenderWindow _window;
        bool _close;
        void cycleLevelTexture();
        DifficultyType getCurrentDifficulty() { return _currentDifficulty; }
    protected:
        Button _start;
        Button _quit;
        Button _settings;
        Text _tittle;
        Text _tittle2;
        Object _background;
        Object _jetback;
        Music _music;
        bool _settingsdraw;
        Object _backsettings;
        Button _closeSettings;
        Button _soundBtn;
        bool _isMusicPlaying;
        Button _soundBtnMute;
        Text _musicSettings;
        Text _levelSettings;
        Button _level;
        int _currentLevelIndex;
        sf::Texture _levelTextures[3];
        DifficultyType _currentDifficulty;
    private:
};
