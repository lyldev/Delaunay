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

//bool Triangle::IsObtuseTriangle(Pnt &obtusePnt, Pnt &acutePnt1, Pnt &acutePnt2, Edge &longEdge)
//{
//	double  x1,x2,x3,y1,y2,y3;
//	x1  =  p1.getX(); y1  =  p1.getY();
//    x2  =  p2.getX(); y2  =  p2.getY();
//    x3  =  p3.getX(); y3  =  p3.getY();
//
//	// p1->p2 . p1->p3
//	double a1 = x2-x1; double a2 = y2-y1;
//	double b1 = x3-x1; double b2 = y3-y1;
//	if((a1*b1 + a2*b2) < 0)
//	{
//		obtusePnt = p1;
//		acutePnt1 = p2;
//		acutePnt2 = p3;
//		longEdge = e3;
//		return true;
//	}
//	// p2->p1 . p2->p3
//	a1 = x1-x2; a2 = y1-y2;
//	b1 = x3-x2; b2 = y3-y2;
//	if((a1*b1 + a2*b2) < 0)
//	{
//		obtusePnt = p2;
//		acutePnt1 = p1;
//		acutePnt2 = p3;
//		longEdge = e2;
//		return true;
//	}
//	// p3->p1 . p3->p2
//	a1 = x1-x3; a2 = y1-y3;
//	b1 = x2-x3; b2 = y2-y3;
//	if((a1*b1 + a2*b2) < 0)
//	{
//		obtusePnt = p3;
//		acutePnt1 = p1;
//		acutePnt2 = p2;
//		longEdge = e1;
//		return true;
//	}
//
//	return false;
//}