/*
** EPITECH PROJECT, 2024
** B-PDG-300-MLH-3-1-PDGRUSH3-philippe.mahapatra
** File description:
** Main JAM
*/

#include <iostream>
#include "Game/Game.hpp"
#include "Menu/Menu.hpp"

int main()
{
    Menu menu;
    menu.run();
    
    if (!menu.isClosed()) {
        Game game;
        game.run();
    }
    return 0;
}