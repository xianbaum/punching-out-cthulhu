#include "Angle.h"

Angle::Angle()
{
    //ctor
    this -> angle = 0;
}

Angle::Angle( double angle )
{
    this -> angle = angle;
}

void Angle::set( double angle )
{
    this -> angle = angle;
    checkAngle();
}

void Angle::set( Angle angle )
{
    this -> angle = angle . get();
    checkAngle();
}

void Angle::add( double angle )
{
    this -> angle += angle;
    checkAngle();
}

double Angle::get()
{
    return angle;
}

double Angle::getOffset( double angle )
{
    angle = this -> angle - angle;
    if( angle < -180 )
        angle += 360;
    if( angle > 180 )
        angle -= 360;
    return angle;
}

void Angle::checkAngle()
{
    while( angle >= 360 )
        angle -=360;

    while( angle < 0 )
        angle += 360;
}

Angle::~Angle()
{
    //dtor
}
