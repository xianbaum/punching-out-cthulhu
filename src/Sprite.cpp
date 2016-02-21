#include "Sprite.h"

Sprite::Sprite(std::string path, int x, int y, int width, int height, SDL_Renderer* renderer)
{
    this->init(path,x,y,width,height,renderer);
}

Sprite::Sprite(std::string path, int x, int y, SDL_Renderer* renderer)
{
    this->init( path, x, y, 0, 0, renderer );
    this
}

void Sprite::init(std::string path, int x, int y, int width, int height, SDL_Renderer* renderer)
{
    this->path = path;
    this -> pos . x = x;
    this -> pos . y = y;
    this->renderer = renderer;
    this->alpha = 0xFF;
    this->red = 0xFF;
    this->blue = 0xFF;
    this->green = 0xFF;
    this->scale=1;
    this->width=width;
    this->height=height;
    line = new Line();
}

Sprite::~Sprite()
{
	SDL_DestroyTexture( this->texture );
	this->texture = NULL;
	SDL_DestroyRenderer( this->renderer );
	this->renderer = NULL;
}

void Sprite::load()
{
	//The final texture
	SDL_Texture* texture = NULL;

	SDL_Surface* surface = IMG_Load( this->path.c_str() );
	if( surface == NULL )
	{
		printf( "Couldn't load image %s. SDL_image Error: %s\n", this->path.c_str(), IMG_GetError() );
	}
	else
	{
        texture = SDL_CreateTextureFromSurface( this->renderer, surface );
		if( texture == NULL )
		{
			printf( "Couldn't create texture %s. SDL Error: %s\n", this->path.c_str(), SDL_GetError() );
		}
		else
        {
            SDL_SetColorKey( surface, SDL_TRUE, SDL_MapRGB( surface->format, 0, 0xFF, 0xFF ) );
            SDL_SetTextureBlendMode( texture, SDL_BLENDMODE_BLEND );
            if( this -> width == 0 || this -> height == 0 )
            {
                this->width = surface->w;
                this->height = surface->h;
            }
            this->s_width = this->width;
            this->s_height = this->height;
        }
		SDL_FreeSurface( surface );
	}
	this->srcrect = { 0, 0, this->width, this->height };
//	this->texture=texture;
    this->texture = texture;
}

void Sprite::draw()
{
	//scale stuff
    this-> s_width  = this -> width  * this -> scale;
    this-> s_height = this -> height * this -> scale;

	//Set rendering space and render to screen
	this -> rect =
	{ this -> pos . x - ( this -> s_width  / 2 ),
	  this -> pos . y - ( this -> s_height / 2 ),
	  this -> s_width, this -> s_height };

    const SDL_Rect * srcrect2 = & srcrect;
	const SDL_Rect * rect2 = & rect;

	//rotation center stuff
	center = { this -> s_width  / 2,
               this -> s_height / 2};
	SDL_Point * center2 = & center;

	//texture stuff
	SDL_SetTextureColorMod( texture, this -> red, this -> green, this -> blue );
    SDL_SetTextureAlphaMod( this -> texture, this -> alpha );
	//draw
	SDL_RenderCopyEx( renderer, texture, srcrect2, rect2, angle, center2, flip );
}

/*void Sprite::draw(int x, int y, int width, int height)
{

}*/

void Sprite::flipHorizontal()
{
    if(this->flip != SDL_FLIP_HORIZONTAL)
        this->flip = SDL_FLIP_HORIZONTAL;
    else
        this->flip = SDL_FLIP_NONE;
}

void Sprite::flipVertical()
{
    if(this->flip != SDL_FLIP_VERTICAL)
        this->flip = SDL_FLIP_VERTICAL;
    else
        this->flip = SDL_FLIP_NONE;
}

void Sprite::flipHorizontal(bool is_flipped)
{
    if(is_flipped)
        this->flip = SDL_FLIP_HORIZONTAL;
    else
        this->flip = SDL_FLIP_NONE;
}

void Sprite::flipVertical(bool is_flipped)
{
    if(is_flipped)
        this->flip = SDL_FLIP_VERTICAL;
    else
        this->flip = SDL_FLIP_NONE;
}

void Sprite::rotate(double rotation)
{
    this->angle+=rotation;
}

void Sprite::fade(Uint8 alpha)
{
    this->alpha+=alpha;
}

void Sprite::changeColor(Uint8 red, Uint8 blue, Uint8 green)
{
    this->red += red;
    this->blue += blue;
    this->green += green;
}

void Sprite::move(int x, int y)
{
    this -> pos . x+=x;
    this -> pos . y+=y;
}

void Sprite::resize(double scale)
{
    this->scale += scale;
}

//Getters and setters

int Sprite::Width()
{
    return this->width;
}

int Sprite::Height()
{
    return this->height;
}

void Sprite::Alpha( Uint8 alpha )
{
    this->alpha=alpha;
}

void Sprite::Angle(double angle)
{
    this->angle=angle;
}

void Sprite::Scale(double scale)
{
    this->scale=scale;
}

void Sprite::X(int x)
{
    this -> pos . x = x;
}

void Sprite::Y(int y)
{
    this -> pos . y = y;
}

void Sprite::RGB( Uint8 red, Uint8 blue, Uint8 green )
{
    this->red = red;
    this->blue = blue;
    this->green = green;
}



//=LIMB LIMB LIMB

/*void Limb::modify(const int instruction_temp, const double x_temp, const double y_temp, const double growth_temp, const double rotation_temp,
		const double alpha_temp, const double timeTemp, const bool is_time_based)
{
	if(this->instruction==instruction_temp)
	{
		if(this->is_at_target)
		{
			calcGo(x_temp, y_temp, growth_temp, rotation_temp, alpha_temp, timeTemp, is_time_based); //false = relative velocity true = rel time
			is_at_target=false;
		}
		if(checkisAtTarget(x_temp,y_temp,growth_temp,rotation_temp,is_time_based))
			this->instruction++;
		else
			animate();
	}
}

void Sprite::loopInstruction(const int instruction_start, const int instruction_end)
{
	if(this->instruction==instruction_start)
		this->instruction=instruction_end;
/*/
