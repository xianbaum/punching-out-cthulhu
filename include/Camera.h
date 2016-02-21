#ifndef CAMERA_H
#define CAMERA_H
#include "movement.h"

class Camera
{
    public:
        Camera();//ctor
        virtual ~Camera();//dtor

        //the meat
        void update(double xrel, double x_movement, double y_movement);

        //getters
        double getAngle();
        double getX();
        double getY();
        double getZ();
        double getXVelocity();
        double getYVelocity();

        //setters
        void setAngle(double angle);
        void setX(double x);
        void setY(double y);
        void go();
    protected:
    private:
        double angle,
        x,
        y,
        z,
        velocity,
        x_velocity,
        y_velocity;
        void initVars();
};

#endif // CAMERA_H
