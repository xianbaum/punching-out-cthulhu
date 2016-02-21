#ifndef ACTOR_H
#define ACTOR_H
#include "Line.h"
#include "Sprite.h"
#include "SDL_Image.h"
#include "Angle.h"

class Actor
{
    public:
        Actor(int type, SDL_Renderer* renderer);
        void calcDistance(double camera_x, double camera_y);
void calcOnScreen(Angle * camera_angle, const double SCREEN_WIDTH, const double SCREEN_HEIGHT, int fov);
        void actorUpdater(double camera_x, double camera_y, double camera_z, Angle * camera_angle, bool is_punching, double touch_x, double touch_y,
	int camera_width, int camera_height, int fov);
        void checkAngle();
        void calcGo(double target_x, double target_y, double target_z, double time, bool time_based); //false = relative velocity true = rel time
        bool check(double target_x, double target_y, double target_z, bool time_based);
        void go();
        void go(int offset);
        void modifyLimb(int No, int instructionTemp, double XTemp, double YTemp, double growthTemp, double rotationTemp, double alphaTemp, double timeTemp, bool is_time_based);
        void enemyAI(int instruction, double X, double Y, double Z, double time, bool is_time_based);
        void loopLimb(int limb, int instructionStart, int instructionEnd);
        void loopEnemy(int instructionStart, int instructionEnd);
        void moveLimb(int no, int inst, double x, double y,double time);
        void limbAlpha(int no, int inst, double alpha, double time);
        void limbRotate(int no, int inst, double rotate, double time);
        void limbGrow(int no, int inst, double grow, double time);
        void setSprite();
        virtual ~Actor();
        void init();
    protected:
    private:
int health,
	move_instruction,
	instruction,
	x_on_screen,
	y_on_screen;
double
	x,
	y,
	z,
	target_x,
	target_y,
	target_z,
	z_velocity,
	distance,
	distance_to_camera,
	velocity,
	time,
	target_time,
	timer,
    punch_timer,
    scale,
    growth;
    bool is_at_target,
        is_punching,
        is_player,
        is_initialized,
        on_screen,
        scales;
    int enemy_type;
    Sprite * sprite;
    Line * line_go;
    Line * line_camera;
    Angle * angle_to_camera,
        * angle;
};

#endif // ACTOR_H
