#include "World.h"

World::World(int world_type,int camera_width, int camera_height, SDL_Renderer* renderer)
{
	switch (world_type) {
	case 1:
	{
		this -> room = new Room ( 2 , camera_width, camera_height, renderer );
	}
	break;
	}
}

void World::setFlag(int flag_no)
{
	this->flag[flag_no]=!this->flag[flag_no];
}

void World::pause()
{
	this->is_paused=true;
}

void World::enterRoom(int room_type,int  camera_width,int camera_height)
{
	delete this -> room;
	this -> room = new Room(room_type, camera_width, camera_height, this->renderer);
}

void World::unpause()
{
	this->is_paused=false;
}

void World::updateWorld( int fov,
                   const int SCREEN_WIDTH, const int SCREEN_HEIGHT,
                   double x_rel, double y_rel,
                   double i_x, double i_y,
                   double x_movement, double y_movement )
{
	//room stuff
	room -> updateRoom( fov,
                        SCREEN_WIDTH, SCREEN_HEIGHT,
                        x_rel, y_rel,
                        x_movement, y_movement );
}

World::~World()
{
    //dtor
}
