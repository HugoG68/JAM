/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** Factory
*/

#include "Factory.hpp"

IEntity *AFactory::create()
{
    return std::make_unique<IEntity>().get();
}
