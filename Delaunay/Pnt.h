#pragma once
#include <math.h>

class Pnt2
{
public:
	Pnt2(){};
	Pnt2(double xx, double yy):x(xx), y(yy){};
	~Pnt2(void);
	double getX(){return x;}
	double getY(){return y;}
	double getDist(Pnt2 other){return sqrt(pow(x-other.getX(),2)+pow(y-other.getY(),2));}

private:
	double x, y;
};

