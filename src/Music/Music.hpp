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

    void pause();
    void resume();
    bool _isMute;
    sf::Music _music;
protected:
};