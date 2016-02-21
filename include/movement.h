/****************************************
 * Christian Baum                       *
 * movement.c                           *
 *                                      *
 * This file just contains some global  *
 * functions and variables for movement *
 * based on angles                      *
 ****************************************/

#ifndef MOVEMENT_H
#define MOVEMENT_H

//because we need cos and sin
#include <cmath>

double goX( double angle, double velocity );
double goX( double angle );
double goY( double angle, double velocity );
double goY( double angle );

#endif // MOVEMENT_H_INCLUDED
