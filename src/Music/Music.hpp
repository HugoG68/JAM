/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Music
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Music {
public:
    Music();
    Music(const std::string music);
    ~Music();

    void stop();
    void pause();
    void resume();
    void setVolume(float volume);
    float getVolume();
    bool _isMute;
    sf::Music _music;
protected:
};