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
    double _speed;
    std::tuple<double, double> _pos;

public:
    AEntity() :_pos(start_pos()), _speed(speed()) {};
    ~AEntity() = default;
    void go_up(void) {
        double pos_y = std::get<1>(_pos);
        double new_pos_y = pos_y - _speed; 
        if (new_pos_y >= 0.0)
            std::get<1>(_pos) = new_pos_y;
    }
    void go_left(void){
        double pos_x = std::get<0>(_pos);
        double new_pos_x = pos_x - _speed; 
        if (new_pos_x >= 0.0)
            std::get<0>(_pos) = new_pos_x;
    }
    void go_right(void){
        double pos_x = std::get<0>(_pos);
        double new_pos_x = pos_x + _speed; 
        if (new_pos_x <= 1.0)
            std::get<0>(_pos) = new_pos_x;
    }
    void go_down(void){
        double pos_y = std::get<1>(_pos);
        double new_pos_y = pos_y + _speed; 
        if (new_pos_y <= 1.0)
            std::get<1>(_pos) = new_pos_y;
    }
    virtual std::tuple<double, double> get_pos() const {
        return _pos;
    };
    virtual std::tuple<double, double> start_pos() const {
        throw Error(Error::Type::NotInit);
    };
    virtual double speed() const {
        throw Error(Error::Type::NotInit);
    };
    virtual EntityType get_type() const {
        return Unknow;
    };
};

} // namespace Entity