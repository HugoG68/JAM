/*
** EPITECH PROJECT, 2024
** JAM
** File description:
** AEntity
*/

#pragma once
#include "IEntity.hh"

namespace Entity
{

class AEntity : public IEntity
{
private:
    std::tuple<double, double> _pos;
    double _speed;

public:
    AEntity(std::tuple<double, double> pos, double speed) :_pos(pos), _speed(speed) {};
    ~AEntity() = default;
    virtual void go_up(void) {
        double pos_y = std::get<1>(_pos);
        double new_pos_y = pos_y - _speed; 
        if (new_pos_y >= 0.0)
            std::get<1>(_pos) = new_pos_y;
    }
    virtual void go_left(void){
        double pos_x = std::get<0>(_pos);
        double new_pos_x = pos_x - _speed; 
        if (new_pos_x >= 0.0)
            std::get<0>(_pos) = new_pos_x;
    }
    virtual void go_right(void){
        double pos_x = std::get<0>(_pos);
        double new_pos_x = pos_x + _speed; 
        if (new_pos_x <= 1.0)
            std::get<0>(_pos) = new_pos_x;
    }
    virtual void go_down(void){
        double pos_y = std::get<1>(_pos);
        double new_pos_y = pos_y + _speed; 
        if (new_pos_y <= 1.0)
            std::get<1>(_pos) = new_pos_y;
    }
    virtual std::tuple<double, double> get_pos() const {
        return _pos;
    };
    virtual EntityType get_type() const {
        return UnknowType;
    };
};

} // namespace Entity