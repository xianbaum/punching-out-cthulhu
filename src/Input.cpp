#include "Input.h"
#include "SDL.h"
Input::Input()
{
    this->setUpMouse();
    this->mouse_x=0;
    this->mouse_y=0;
    this->x_rel=0;
    this->mouse_x_rel=0;
    this->kb_and_mouse=true;
}

void Input::setUpMouse()
{
    SDL_GetMouseFocus();
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void setUpKeyboard()
{

}

void Input::updateControls()
{
 /*   while(SDL_PollEvent( &event )!=0)
    {
        this->mouse_x_rel=0;
        this->mouse_y_rel=0;
        if(event.type = SDL_MOUSEMOTION)
        {
            printf("%i",this->mouse_x_rel);
            this-> mouse_x_rel = event.motion.xrel;
            this-> mouse_y_rel = event.motion.yrel;
            this-> mouse_x = event.motion.x;
            this-> mouse_y = event.motion.y;
        }
    }*/
    		while( SDL_PollEvent( &event ) != 0 )
		{
			if( event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
//			int mouse_x_rel=0;
  //          int mouse_y_rel=0;
    //        int mouse_x=0;
      //      int mouse_y=0;
            if(event.type = SDL_MOUSEMOTION)
            {
                mouse_x_rel = event.motion.xrel;
                mouse_y_rel = event.motion.yrel;
                mouse_x = event.motion.x;
                mouse_y = event.motion.y;
                printf("%i",mouse_x_rel);

            }
		}

    if(this->kb_and_mouse)
    {
        this-> x_rel = this->mouse_x_rel;
        this-> y_rel = this->mouse_y_rel;
    }
}

float Input::getXRel()
{
    return x_rel;
}

void updateKeyboard()
{

}
Input::~Input()
{
    //dtor
}
