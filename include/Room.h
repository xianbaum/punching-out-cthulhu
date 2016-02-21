#ifndef ROOM_H
#define ROOM_H
#include "Actor.h"
#include "Background.h"
#include "SDL_image.h"
#include "Camera.h"

class Room
{
    public:
        Room(int room_type, int camera_width, int camera_height, SDL_Renderer *renderer);
        void scaleRoom();
        void updateRoom(int fov, int camera_width, int camera_height,
		double  x_rel, double y_rel, double x_movement, double y_movement);
        Actor* actor;
        virtual ~Room();
    protected:
    private:
    Background* bg[];
    double length,//*
	width,//*
	height,//*
	radius,//*
	//Modified after initialized
    scale;//
    bool
        circular;//*
    Camera* camera;
    SDL_Renderer* renderer;

};

#endif // ROOM_H
