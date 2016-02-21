/**********************************************
 * Christian Baum                             *
 * Line.h                                     *
 *                                            *
 * This class compares two points to find the *
 * angle and distance                         *
 **********************************************/

#include "Line.h"

//Constructors

Line::Line()
{
    initVars();
}

Line::Line( int x2, int y2 )
{ //This makes point 1 (0,0)
    initVars();
    calcAngleAndDistance( x2, y2 );
}

Line::Line( int x, int y, int x2, int y2 )
{
    initVars();
    calcAngleAndDistance( x, y, x2, y2 );
}

//Deconstructors

Line::~Line()
{
    initVars();
}

//Used by constructor and deconstructor

void Line::initVars()
{
    this -> pt1 . x = 0;
    this -> pt1 . y = 0;
    this -> pt2 . x = 0;
    this -> pt2 . y = 0;
    this -> angle_to_pt2 = 0;
    this -> angle_to_pt1 = 0;
    this -> distance = 0;
}

//Functions

int Line::calcAngleAndDistance( double x1, double y1, double x2, double y2 )
{
    this -> pt1 . x = x1;
    this -> pt1 . y = y1;
    return calcAngleAndDistance( x2, y2 );
}

/*  Reference
 quad 3 0 quadrant 0
  315   |  45
        |
270-----0------90
 quad 2 | quad 1
  225   |  135
       180         (0 degrees is up)*/
int Line::calcAngleAndDistance( double x2, double y2 )
{
    this -> pt2 . x = x2;
    this -> pt2 . y = y2;
    //We are using the pythagreon (sp?) theorom (sp?) then atan to find the nagle.
    //So, the angle is sqrt a*2 + b*2, and we divide it into quadrants to find out how to use it.
	double a=0,
		b=0,
		quadrant=0;
    //I think I cleaned this code up nicely, Logic is MUCH cleaner.
	if( this -> pt2 . x == this -> pt1 . x )
    {
        if( this -> pt2 . y >  this -> pt1 . y )
        {
            quadrant = 4;
            this -> angle_to_pt2 . set( 0 );
            this -> angle_to_pt1 . set( 180 );
            this -> distance = this -> pt2 . y - this -> pt1 . y;
        }
        else if( this -> pt2 . y <  this -> pt1 . y )
        {
            quadrant = 5;
            this -> angle_to_pt2 . set( 180 );
            this -> angle_to_pt1 . set( 0 );
            this -> distance = this -> pt1 . y - this -> pt2 . y;
        }
        else// if( this -> pt1 . y == this -> pt2 . y)
        {
            quadrant = 6;
            this -> distance = 0;
            this -> angle_to_pt2 = 0;
            this -> angle_to_pt1 = 0;
        }
    }
	else if( this -> pt2 . x <  this -> pt1 . x )
    {

        if( this -> pt2 . y == this -> pt1 . y )
        {
            quadrant = 7;
            this -> angle_to_pt2 . set( 270 );
            this -> angle_to_pt1 . set( 90 );
            this -> distance = this -> pt1 . x - this -> pt2 . x;
        }
        else if( this -> pt2 . y > this -> pt1 . y )
        {
            quadrant = 3;
            a = this -> pt1 . y - this -> pt2 . y;
            b = this -> pt2 . x - this -> pt1 . x;
        }
        else// if ( this -> pt2 . y < this -> pt1 . y)
        {
            quadrant = 2;
            a = this -> pt1 . x - this -> pt2 . x;
            b = this -> pt1 . y - this -> pt2 . y;
        }
    }
	else// if( this -> pt2 . x > this -> pt1 . x)
    {
        if( this -> pt2 . y > this -> pt1 . y )
        {
            quadrant = 0;
            a = this -> pt2 . x - this -> pt1 . x;
            b = this -> pt2 . y - this -> pt1 . y;
        }
        else if( this -> pt2 . y == this -> pt1 . y )//&&pt2 . x < x
        {
            quadrant = 7;
            this -> angle_to_pt2 . set( 90 );
            this -> angle_to_pt1 . set( 270 );
            this -> distance = this -> pt2 . x - this -> pt1 . x;
        }
        else// if( this -> pt2 . y < this -> pt1 . y)
        {
            quadrant = 1;
            a = this -> pt1 . y - this -> pt2 . y;
            b = this -> pt2 . x - this -> pt1 . x;
        }
    }
    //If one is equal, this was already taken care of
	if( this -> pt1 . x != this -> pt2 . x
    &&  this -> pt1 . y != this -> pt2 . y )
	{
		this -> distance = sqrt( ( a * a ) + ( b * b ) );
        this -> angle_to_pt2 . set( ( double ) ( 57.2957795 * ( atan ( a / b ) ) + ( quadrant * 90 ) ) );
        this -> angle_to_pt1 . set( 360 - this->angle_to_pt2 . get() );
	}
	return quadrant;
}

//Getters (no setters)

double Line::getDistance()
{
    return this -> distance;
}

Angle Line::getAngleToPt2()
{
    return this -> angle_to_pt2;
}

//angle_to_pt2 is usually the angle you want.
Angle Line::getAngle()
{
    return this -> angle_to_pt2;
}

Angle Line::getAngleToPt1()
{
    return this -> angle_to_pt1;
}
