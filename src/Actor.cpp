#include "Actor.h"
#include <cmath>
#include <SDL_image.h>
#include <SDL.h>

Actor::Actor(int type,SDL_Renderer* renderer)
{
    this->init();
    this -> angle_to_camera = new Angle();
    this -> angle = new Angle();
    line_go = new Line();
    line_camera = new Line();
    this->sprite = new Sprite("image.png",0,0,renderer);
}

void Actor::init()
{
    this->health=100;
    this->move_instruction=0;
    this->instruction=0;
    this->x=1;
    this->y=0;
    this->target_x=0;
    this->target_y=0;
    this->target_z=0;
    this->z_velocity=0;
    this->distance=0;
    this->angle_to_camera=0;
    this->angle=0;
    this->velocity=0;
    this->time=0;
    this->target_time=0;
    this->timer=0;
    this->punch_timer=0;
    this->is_at_target=0;
    this->is_punching=0;
    this->is_player=0;
    this->is_initialized=false;
    this -> scale = 1;
    this -> scales = true;
}

//TODO rename this
void Actor::calcDistance(double camera_x, double camera_y)
{
    this->line_camera->calcAngleAndDistance(this->x, this->y, camera_x, camera_y);
    this->distance_to_camera = this->line_camera->getDistance();
    this->angle_to_camera -> set( this->line_camera -> getAngle() );
}

void Actor::calcOnScreen( Angle * camera_angle, const double SCREEN_WIDTH, const double SCREEN_HEIGHT, int fov )
//This section calculates the screen position
{
    //Y'know code that works that you're not quire sure what it does? Well this is that.
	double wrap_left = 0, wrap_right = 0;
    this -> on_screen = true;
 /*   if( this -> angle_to_camera > camera_angle - fov && angle_to_camera < camera_angle + fov )
        this -> x_on_screen = - ( this -> line_camera -> getAngle() - camera_angle ) * ( SCREEN_WIDTH / fov) + SCREEN_WIDTH / 2;
    else
        this -> on_screen = false;*/
    this -> x_on_screen = (SCREEN_WIDTH / 2) + ( this -> angle_to_camera -> getOffset( camera_angle -> get() ) * fov );
    this -> y_on_screen = (this -> z - 0) + SCREEN_HEIGHT / 2;
    if(this->scales)
	{
		double apparent_width = (double) ( 180 / M_PI ) * ( this -> sprite -> Width () / ( this -> distance_to_camera ) );
		this->scale = apparent_width/this->sprite->Width();
	}
}

void Actor::actorUpdater(double camera_x, double camera_y, double camera_z, Angle * camera_angle, bool is_punching, double touch_x, double touch_y,
	int SCREEN_WIDTH, int SCREEN_HEIGHT, int fov)
{
	calcDistance(camera_x, camera_y);
	calcOnScreen(camera_angle, SCREEN_WIDTH, SCREEN_HEIGHT, fov);
	setSprite();
}

void Actor::setSprite()
{
    if( this -> on_screen )
    {
        this->sprite->X(this->x_on_screen);
        this->sprite->Y(this->y_on_screen);
        this->sprite->Scale(this->scale);
        printf("( %i , %i ) %g\%.\n" , this->x_on_screen, this->y_on_screen, this->scale);
        this -> sprite -> draw();
    }
}


Actor::~Actor()
{
    init();
    delete(sprite);
    delete(line_camera);
    delete(line_go);
}
