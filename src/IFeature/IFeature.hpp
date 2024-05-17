/*
** EPITECH PROJECT, 2024
** CrimsonClicker
** File description:
** IFeature
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class IFeature {
    public:
        virtual void addScore(int value) = 0;
        virtual int getScore() const = 0;
        virtual void setClickValue(int value) = 0;
        virtual int getClickValue() const = 0;
    protected:
    private:
};
