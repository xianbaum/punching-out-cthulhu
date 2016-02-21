/***************************************************
 * Christian Baum                                  *
 * Interval.c                                      *
 *                                                 *
 * Interval.c is a class file that has a beginning *
 * variable and a destination variable. It brings  *
 * it to its destination in the time its given.    *
 ***************************************************/

#include "Interval.h"

Interval::Interval()
{
    init();
}

Interval::Interval( double var, double target, double timer )
{
    init();
    init( var, target, timer );
}

Interval::Interval( double var, double target, double timer, bool relative )
{
    init();
    init( var, target, timer, relative );
}

Interval::~Interval()
{
    init();
}

//Actually, this one's useless. But whatevs
Interval::Interval( double var, double target, double timer, bool relative, bool at_target )
{
    init( var, target, timer, relative, at_target );
}

void Interval::init()
{
    this -> velocity = 0;
    this -> timer    = 0;
    this -> distance = 0;
    this -> var      = 0;
    this -> target   = 0;
    this -> at_target = true;
    this -> relative = false;
}

bool Interval::isAtTarget()
{
    //if time has expired, put them exactly at their targets (they may be a little off) and return true
	if( this -> timer <= 0 )
    {
        this -> var = this -> target;
        return this -> at_target = true;
    }
    //otherwise, it's not at its target. false.
	return this -> at_target = false;
}

//this is the "helper" which basically does everything
void Interval::initBack( double var, double target, double timer )
{
    //setting variables
	this -> var = var;
    //Is it relaiive to the variable?
	if( this -> relative )
        this -> target = var + target;
    else
        this -> target = target;
    this -> timer      = timer;
    this -> distance   = target - var;
   	this -> velocity   = this -> distance / timer;
    this -> at_target = false;
}

//for starting a new one even if the old one isn't finished
void Interval::init( double var, double target, double timer, bool relative, bool at_target )
{
    this -> at_target = at_target;
    if( this -> at_target )
    {
        this -> relative = relative;
        initBack( var, target, timer );
    }
}

//target is relative to var?
void Interval::init( double var, double target, double timer, bool relative)
{
    if( this -> at_target )
    {
        this -> relative = relative;
        initBack( var, target, timer );
    }
}

void Interval::init( double var, double target, double timer )
{
    if( this -> at_target )
    {
        this -> relative = false;
        initBack( var, target, timer );
    }
}

void Interval::go( double time_since_last_frame )
{
    if( ! this -> at_target )
    {
        this -> var  += this -> velocity * time_since_last_frame;
        this -> timer -= time_since_last_frame;
    }
}

double Interval::getVar()
{
    return this -> var;
}
