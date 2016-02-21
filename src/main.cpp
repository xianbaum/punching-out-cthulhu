#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sprite.h"
#include "Background.h"
#include "World.h"
#include "Interval.h"
//Window stuff
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
SDL_Renderer* renderer = NULL;
int fov=90; //

//Input stuff
bool quit=false;
bool kb_and_mouse = true,
mouse_focus=true,
pause=false;//TODO: implement pause
SDL_Event event;
double mouse_x_rel=0,//mouse relative
    mouse_y_rel=0,
    mouse_x=0,//mouse absolute
    mouse_y=0,
    i_x=0, //absolute cursor pos based on ctrl scheme
    i_y=0,
    x_rel=0//general relative, for look based on control scheme
    ,y_rel=0,
    sensitivity=.2,//mouse sensitivity
    x_movement=0,//x and y movement
    y_movement=0;

//star & stop functions
int start();
int stop();
void input();

int start()
{
	//init sdl
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return 1;
	}
	else
	{
		//linear filtering
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) )
		{
			printf( "Warning: Linear texture filtering not enabled. SDL Error: %s\n", SDL_GetError() );
		}

		//window stuff
		window = SDL_CreateWindow( "Punching Out Cthulhu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL );
		if( window == NULL )
		{
			printf( "window wasn't created SDL Error: %s\n", SDL_GetError() );
			return 2;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				return 3;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );

				//Initialize PNG loading
				int img_flags = IMG_INIT_PNG;
				if( !( IMG_Init( img_flags ) & img_flags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					return 4;
				}
			}
		}
	}

    //input stuff
    SDL_GetMouseFocus();
    SDL_SetRelativeMouseMode(SDL_TRUE);

	return 0;
}

int stop()
{
	//Free loaded image

	//Destroy window
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	return EXIT_SUCCESS;
}

void input()
{
    mouse_x_rel=0;
    mouse_y_rel=0;
    mouse_x=0;
    mouse_y=0;
    x_rel=0;
    y_rel=0;
   		while( SDL_PollEvent( &event ) != 0 )
		{
			if( event.type == SDL_QUIT )
			{
				quit = true;
			}
			if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    quit = true;
                //alt toggles mouse focus
                if(event.key.keysym.mod == KMOD_ALT)
                {
                    SDL_SetRelativeMouseMode(SDL_FALSE);
                }
                if(kb_and_mouse)//if kb&m is ctrl scheme
                {
                    if(event.key.keysym.sym == SDLK_w)
                        y_movement=1;
                    if(event.key.keysym.sym == SDLK_a)
                        x_movement=-1;
                    if(event.key.keysym.sym == SDLK_s)
                        y_movement=-1;
                    if(event.key.keysym.sym == SDLK_d)
                        x_movement=1;
                }
            }
            if(event.type == SDL_KEYUP)
            {
                if(kb_and_mouse)//if kb&m is ctrl scheme
                {
                    if(event.key.keysym.sym == SDLK_w)
                        y_movement=0;
                    if(event.key.keysym.sym == SDLK_a)
                        x_movement=-0;
                    if(event.key.keysym.sym == SDLK_s)
                        y_movement=0;
                    if(event.key.keysym.sym == SDLK_d)
                        x_movement=0;
                }
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                mouse_x_rel = event.motion.xrel;
                mouse_y_rel = event.motion.yrel;
                mouse_x = event.motion.x;
                mouse_y = event.motion.y;
            }
            else
            {
                mouse_x_rel=0;
                mouse_y_rel=0;
                mouse_x=0;
                mouse_y=0;
                x_rel=0;
            }
            if(kb_and_mouse)
            {
                x_rel = mouse_x_rel*sensitivity;
                y_rel = mouse_y_rel*sensitivity;
                i_x = mouse_x;
                i_y = mouse_y;
            }
		}
}

double fps()
{

}

int main( int argc, char* args[] )
{
    //=================================INIT STUFF=======================
    //init SDL
    if(start()>0)
    {
        return EXIT_FAILURE;
    }
    //=================================PRE LOOP=========================

    World * world = new World(1, SCREEN_WIDTH,SCREEN_HEIGHT, renderer);

    //================================MAIN LOOP=========================
    while(!quit)
	{
        //input stuff
        input();
        //clearing screen
        SDL_RenderClear( renderer );
        //Updating game frame
        world->updateWorld(fov,//FOV
                           SCREEN_WIDTH,SCREEN_HEIGHT, //screen width, height
                           x_rel,y_rel, //mouse relative
                           i_x,i_y,//mouse absolute (but also relative to the window)
                           x_movement, y_movement); //movement based on wasd
        //Rendering
        SDL_RenderPresent( renderer );

    }
    //===============================END LOOP============================

    //returns EXIT_SUCCESS
    return stop();//=================END PROGRAM=========================
}
