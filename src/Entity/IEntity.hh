/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** IEntity
*/


#pragma once
#include "Error.hpp" 
#include <tuple>

namespace Entity
{
    
typedef enum {
    Unknow = -1,
    Player,
} EntityType;


class IEntity {
    public:
        ~IEntity() = default;
    virtual void go_up(void) = 0;
    virtual void go_left(void) = 0;
    virtual void go_right(void) = 0;
    virtual void go_down(void) = 0;
    virtual std::tuple<double, double> get_pos() const = 0;
    virtual std::tuple<double, double> start_pos() const = 0;
    virtual double speed() const = 0;
    virtual EntityType get_type() const = 0;
};
}