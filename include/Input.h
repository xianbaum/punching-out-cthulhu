#ifndef INPUT_H
#define INPUT_H
#include "SDL.h"
#include <stdio.h>
class Input
{
    public:
        Input();
        void setUpMouse();
        void updateMouse();
        virtual ~Input();
        void getMouseXRel();
        void updateControls();
        float getXRel();
    bool quit;
    protected:
    private:
        bool kb_and_mouse;
        SDL_Event event;
        float mouse_x,mouse_y,mouse_x_rel,mouse_y_rel,x_rel,y_rel;
};

#endif // INPUT_H
