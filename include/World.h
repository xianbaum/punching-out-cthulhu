#ifndef WORLD_H
#define WORLD_H
#include "Room.h"
#include "Camera.h"
#include "SDL_image.h"

class World
{
    public:
        World(int world_type,int camera_width, int camera_height, SDL_Renderer* renderer);
        void setFlag(int flag_no);
        void pause();
        void unpause();
        void enterRoom(int room_type,int  camera_width,int camera_height);
        void updateWorld(int degree, int camera_width, int camera_height, double x_rel, double y_rel, double i_x, double i_y, double x_movement,double y_movement);
        virtual ~World();
    protected:
    private:
    bool flag[],
        is_paused;
        Room* room;
        Camera* camera;
        double time;
        SDL_Renderer* renderer;
};

#endif // WORLD_H
