#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Sprite.h"
#include <string>
#include <SDL_image.h>

class Background
{
    public:
        Background(int camera_width, int camera_height, int bg_type, SDL_Renderer* renderer);
        void update(int x, int y,int angle,double x_go , int fov );
        virtual ~Background();

    private:
        Sprite * sprite;
        std::string path;
        int x_velocity,
            y_velocity;
        bool parallax,//does it scroll or not?
            ground, //should it be displayed on the lower half of the screen?
            in_front, //TODO should it be displayed in front of the actors?
            room;//TODO should it scroll if you move left or right? images that cover 360 deg should not.
        Point pos;//x and y

    double scale,
          x_go_offset;
};

#endif // BACKGROUND_H
