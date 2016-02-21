#ifndef LIMB_H
#define LIMB_H
#include "Sprite.h"

class Limb
{
    public:
        Limb(int limb_type, SDL_Renderer* renderer);
        void calcOnScreenLocation(const float camera_angle, const float enemy_angle_to_camera, const float camera_z,
    const float enemy_z, const int equation_used, const int camera_width, const int camera_height);
        void calcScale(const float enemy_distance);
        void setSprite();
        void calcGo(const float target_x, const float target_y, const float target_growth, const float target_rotation,
		const float target_alpha, const float time, const bool time_based);
		bool checkisAtTarget(const float target_x,const float target_y, const float target_growth, const float target_rotation,
		const bool time_based);
		void go();
		void modify(const int instruction_temp, const float x_temp, const float y_temp, const float growth_temp, const float rotation_temp,
		const float alpha_temp, const float timeTemp, const bool is_time_based);
		void loopLimb(const int instruction_start, const int instruction_end);
		bool isInitialized();
		void setIsBeingPunched(bool yes);
        virtual ~Limb();
    protected:
    private:

    Sprite * sprite;
    float health,
    x,
	y,
	velocity,
	scale,
	distance,
	target_growth,
	target_rotation,
	target_alpha,
	target_x,
	target_y,
	time,
	target_time;
    bool
	scales,

	is_being_punched,
	has_health,
	is_initialized;
    int
        local_z_Index,
        width,
        height,
        x_on_screen,
        y_on_screen,
        z_index,
        instruction,
        limb_type;
    std::string path;
};

#endif // LIMB_H
