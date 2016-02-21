#ifndef ANGLE_H
#define ANGLE_H


class Angle
{
    public:
        Angle();
        Angle( double angle );
        void set( double angle );
        void set( Angle angle );
        void add( double angle );
        double get();
        double getOffset( double angle );
        virtual ~Angle();
    protected:
    private:
        void checkAngle();
        double angle;
};

#endif // ANGLE_H
