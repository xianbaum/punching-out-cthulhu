/**********************************************
 * Christian Baum                             *
 * Line.h                                     *
 *                                            *
 * This class compares two points to find the *
 * angle and distance                         *
 **********************************************/

#ifndef LINE_H
#define LINE_H
#include <cmath>
#include "Point.h"
#include "Angle.h"

class Line
{
    public:
        Line();//ctors
        Line( int x, int y );
        Line( int x, int y, int x2, int y2 );
        virtual ~Line();//dtor

        int calcAngleAndDistance( double x2, double y2 );
        int calcAngleAndDistance( double x1, double y1, double x2, double y2 ); //the meat of this class

        //getters

        Angle getAngle();//getters
        Angle getAngleToPt2();
        Angle getAngleToPt1();
        double getDistance();
        Point getPt1();
        Point getPt2();
        Point getMidpoint();

    private:
        Point pt1, //Points to compare
              pt2;
        Angle angle_to_pt1, angle_to_pt2;


        double distance;

        void initVars(); //used by ctor & dtors
};

#endif // LINE_H
