#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <iostream>
#include <SDL_image.h>
#include <stdio.h>
#include "Line.h"
#include "Interval.h"

//TODO clean, comment
class Sprite
{
public:
    Sprite(std::string, int x, int y, SDL_Renderer* renderer);
    Sprite(std::string path, int x, int y, int width, int height, SDL_Renderer* renderer);
    void load();
    void rotate(double rotation); //in degrees
    void move(int x, int y);//in pixels
    void resize(double scale);
    void draw();

    //alpha and colors
    void fade(Uint8 alpha);
    void changeColor(Uint8 red, Uint8 blue, Uint8 green);

    //flip stuff
    void flipHorizontal();
    void flipHorizontal(bool is_flipped);
    void flipVertical();
    void flipVertical(bool is_flipped);
    void animate(double timeSinceLastFrame);

    //animate stuff
    bool checkisAtTarget(const double target_x,const double target_y, const double target_growth, const double target_rotation);
    void initRelativeAnimation(const double target_x, const double target_y,
    const double target_growth, const double target_rotation,
	const double target_alpha, const double time);
    void initAnimation(const double target_x, const double target_y,
    const double target_growth, const double target_rotation,
	const double target_alpha, const double time);

    //Getters and setters
    void Alpha(Uint8 alpha);
    void Angle(double angle); //in degrees
    void Scale(double scale); //1 = normal .5 = half 2 = double 3 = triple
    void X(int x);
    void Y(int y);
    void RGB(Uint8 red, Uint8 blue, Uint8 green);
    int Width();
    int Height();
    virtual ~Sprite();
protected:
private:

    void init(std::string path, int x, int y, int width, int height, SDL_Renderer* renderer);

    std::string path;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    SDL_Rect rect;
    SDL_Rect srcrect;
    SDL_RendererFlip flip;
    SDL_Point center;
    bool display;

    //image properties
    int width;
    int height;
    Point pos;

    //scaled
    void calcScale();
    void calcAlpha();
    double scale; //1 = normal
    int s_width;
    int s_height;

    //Colors & alpha
    Uint8 alpha;
    Uint8 red;
    Uint8 green;
    Uint8 blue;

    double rotation;//in degrees
    double angle;

    //animate stuff
    int instruction_number;
        Interval growth_int;
        Interval rotation_int;
        Interval alpha_int;
        Interval x_int;
        Interval y_int;
        Interval scale_int;
        Interval red_int;
        Interval blue_int;
        Interval green_int;
        Line * line;
    void initAnimationBack(const double target_x, const double target_y,
    const double target_growth, const double target_rotation,
	const double target_alpha, const double time);

};

#endif // IMAGE_H
