/****************************************
 * Christian Baum                       *
 * movement.c                           *
 *                                      *
 * This file just contains some global  *
 * functions and variables for movement *
 * based on angles                      *
 ****************************************/

#include "movement.h"

//Two global constants for angles. I'm using degrees over radians, but math functions like radians
const double DEGREES_TO_RADIANS = 57.2957795;
const double RADIANS_TO_DEGREES = 0.0174532925;

//Miiiight have to rename this to goY. not sure honestly.
double goX( double angle, double velocity )
{
    return sin( angle * RADIANS_TO_DEGREES ) * velocity;
}

//overloaded if we don't need velocity so we don't have to pass 1
double goX( double angle )
{
    return sin( angle * RADIANS_TO_DEGREES );
}

//again might have to rename this to goX.
double goY( double angle, double velocity )
{
    return cos( angle * RADIANS_TO_DEGREES ) * velocity;
}

//overloaded if we don't need velocity so we don't have to pass 1
double goY( double angle )
{
    return cos( angle * RADIANS_TO_DEGREES );
}
