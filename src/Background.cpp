#include "Background.h"

Background::Background(int camera_width, int camera_height, int bg_type, SDL_Renderer* renderer)
{
    this -> pos . x = 0;
    this -> pos . y = 0;
    this -> x_go_offset = 0;
    int w; //TODO: Scaling and scrolling for rooms... oh and put bgs in front, too. and I guess program cool effects as the need comes
    int h;
    room = false;
	switch ( bg_type )
	{
	case 1:
		path = "sky.png";
		w = camera_width;
		h = camera_height;
		ground = false;
		parallax = false;
		room = false;
        break;
	case 2:
		ground = true;
		parallax = true;
		room = false;
		path = "ground.png";
		w = camera_width;
		h = camera_height/2;
        break;
	}
	this -> sprite = new Sprite( path, w, h / 2, w, h, renderer );
}

Background::~Background()
{
    this -> sprite = NULL;
    delete sprite;
}

void Background::update( int x, int y, int angle, double x_go , int fov )
{
    //ints
    double scroll_pos=0;

    //setting vars
    this -> x_go_offset += x_go;
    this -> pos . x = x + this -> sprite -> Width()  / 2;
    this -> pos . y = y + this -> sprite -> Height() / 2;

    //If it's on the ground, display on the lower half of the screen
    if( this -> ground )
    {
        this -> pos . x = x + ( this -> sprite -> Width  () / 2 );
        this -> pos . y = y + ( this -> sprite -> Height () * 1.5 );
    }

    //TODO see if this is needed when doing room
    //impliment this in camera class?
//    this->y=(int)(this->-this->sprite->Width()+5+(camera_z*(fov/2)));

    //scale stuff is broken, commented out
//	this.sprite->Scale((double) getScale(player_x,player_y,camera_angle,radius));

    //Not sure if there's a better name for this variable

    if( this -> parallax )
    {   //This line doesn't 100% translate well, so using *1.02 helps because it's off just a little when going from 360 to 0 degrees. * 0.1 because movement speed?? otherwise without *fov, it goes slower on higher resolutions
        scroll_pos = ( ( angle * ( this->sprite->Width() / fov * 1.02 ) ) - ( x_go_offset * 0.1 * ( this->sprite->Width() / fov ) ) );

        while( scroll_pos > this -> sprite -> Width() )
            scroll_pos -= this -> sprite -> Width();

        while( scroll_pos < 0)
            scroll_pos += this -> sprite -> Width();

        //2nd sprite stuff
        this -> sprite -> X ( this -> pos . x + round( scroll_pos ) - this -> sprite -> Width () );
        this -> sprite -> Y ( this -> pos . y );
        if( ! room )
            this -> sprite -> draw ();
    }
    //sprite stuff
    this -> sprite -> X ( this -> pos . x + round( scroll_pos ) );
    this -> sprite -> Y ( this -> pos . y );
    this -> sprite -> draw ();
}
