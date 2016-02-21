/***************************************************
 * Christian Baum                                  *
 * Interval.h                                      *
 *                                                 *
 * Interval.h is a class file that has a beginning *
 * variable and a destination variable. It brings  *
 * it to its destination in the time its given.    *
 ***************************************************/

#ifndef INTERVAL_H
#define INTERVAL_H

class Interval
{
    public:
        Interval();//ctor, one for each initializer
        Interval( double var, double target, double timer );
        Interval( double var, double target, double timer, bool relative );
        Interval( double var, double target, double timer, bool relative, bool at_target );
        //checks if it's there
        bool isAtTarget();
        //do it up!
        void go( double time_since_last_frame );
        //initializes for going.
        void init( double var, double target, double timer );
        void init( double var, double target, double timer, bool relative );
        void init( double var, double target, double timer, bool relative, bool at_target ); //for overriding is_at_target
        virtual ~Interval();//detour :)
        //lonely getter
        double getVar();

    private:
        double velocity, // per second
              timer, //in seconds
              distance, //in whatever
              target, //in whatever the var is
              var; //in whatever the var is
        bool at_target,
            relative;
        void init();//used by ctor and dtor
        //the real initializer. it's a helper method for the public methods
        void initBack( double var, double target, double time );
};

#endif // INTERVAL_H
