#include "Camera.h"

Camera::Camera()
{
    initVars();
}

void Camera::initVars()
{
    this -> x = 0;
    this -> y = 0;
    this -> angle = 0;
    this -> velocity = 1;
    this -> x_velocity = 0;
    this -> y_velocity = 0;
}

void Camera::update(double xrel,double x_movement, double y_movement)
{
    this->x_velocity = this->velocity*x_movement;
    this->y_velocity = this->velocity*y_movement;
    this->angle-=xrel;

    //Check angle
    if(this->angle>=360)
        this->angle-=360;
    if(this->angle<0)
        this->angle+=360;
    this->go();
}

void Camera::go()
{
    //forward movement
        this->x += goX( this -> angle, this -> y_velocity );
        this->y += goY( this -> angle, this -> y_velocity );
    //side movement
        this->x += goX( this -> angle + 90, this -> x_velocity );
        this->y += goY( this -> angle + 90, this -> x_velocity );
}

//getters and setters

void Camera::setX(double x)
{
    this->x=x;
}

void Camera::setY(double y)
{
    this->y=y;
}

void Camera::setAngle(double angle)
{
    this->angle=+angle;
}

double Camera::getY()
{
    return this->y;
}

double Camera::getX()
{
    return this->x;
}

double Camera::getZ()
{
    return this->z;
}

Angle Camera::getAngle()
{
    return this->angle;
}

double Camera::getXVelocity()
{
    return this->x_velocity;
}

double Camera::getYVelocity()
{
    return this->y_velocity;
}

Camera::~Camera()
{
    initVars();
}
