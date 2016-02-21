#include "Room.h"

Room::Room(int room_type, int camera_width, int camera_height, SDL_Renderer* renderer)
{
    this->scale = 0;
	switch (room_type)
	{
	case 1:
		bg[0] = new Background(camera_width, camera_height, 3, renderer);
		circular = true;
		radius = 300;
	break;
	case 2:
		bg[0] = new Background( camera_width, camera_height, 1, renderer);

		bg[1] = new Background( camera_width, camera_height, 2, renderer);
		circular = true;
		radius = 300;
        actor = new Actor(1, renderer);

	break;
    }
    camera = new Camera();
}

Room::~Room()
{
    //dtor
}

void Room::scaleRoom()
{
	if(this->circular)
	{
		this->scale = 2*this->camera->getAngle();
	}
}


void Room::updateRoom( int fov,
                       const int SCREEN_WIDTH, const int SCREEN_HEIGHT,
                       double  x_rel, double y_rel, double x_movement, double y_movement)
{
    //camera stuff
    this -> camera -> update( x_rel, x_movement, y_movement );

    //bg stuff
	for ( int i = 0; i <= 1; i ++ )
	{
		bg[i]->update( 0, 0,
                       camera -> getAngle(),
                       camera -> getXVelocity(),
                       fov );
    }

    //actor stuff

		this->actor->actorUpdater(camera->getX(),camera->getY(),camera->getAngle(),
			false, x_rel, y_rel, SCREEN_WIDTH, SCREEN_HEIGHT, fov);

}
