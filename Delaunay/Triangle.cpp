#include "Triangle.h"

Triangle::~Triangle(void)
{
}

void Triangle::CalCircumcircle(Pnt &center, double &radius)
{
	double  x1,x2,x3,y1,y2,y3;
    double  x  =  0;
    double  y  =  0;

	x1  =  p1.getX();
    x2  =  p2.getX();
    x3  =  p3.getX();
	y1  =  p1.getY();
    y2  =  p2.getY();
    y3  =  p3.getY();

    x=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2*(x3-x1)*(y2-y1)-2*((x2-x1)*(y3-y1)));  
    y=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2*(y3-y1)*(x2-x1)-2*((y2-y1)*(x3-x1)));  

	center = Pnt(x, y);
	radius = sqrt(pow(center.getX()-x1, 2) + pow(center.getY()-y1, 2));
}