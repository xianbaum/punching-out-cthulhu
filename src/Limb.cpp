#include "Limb.h"
#include "math.h"

Limb::Limb(int limb_type, SDL_Renderer* renderer)
{

    if(limb_type!=0)
    {
//        this->sprite = new Sprite(path, x,y,renderer);
        is_initialized=true;
    }
}

Limb::~Limb()
{
    //dtor
}


/*void Actor::setSprite()
{
	this->sprite->X(this->x_on_screen-(this->sprite->Width()/2));
	this->sprite->Y(this->y_on_screen-(this->sprite->Height()/2));
	this->sprite->Scale(this->scale+(this->growth*this->scale));
	this->sprite->Angle(this->rotation);
	this->sprite->Alpha(this->alpha);
}
*/



//Punched stuff
