/*
** EPITECH PROJECT, 2024
** B-PDG-300-MLH-3-1-PDGRUSH3-philippe.mahapatra
** File description:
** Main JAM
*/

#include <iostream>
#include "Game/Game.hpp"
#include "Menu/Menu.hpp"
#include "Entity/Player.hpp"

int main()
{
    Menu menu;
    menu.run();
    
    Entity::Player a;
    
    if (!menu.isClosed()) {
        Game game(menu.getCurrentDifficulty());
        game.run();
    }
    return 0;
}