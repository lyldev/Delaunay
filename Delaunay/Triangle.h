#pragma once
#include <math.h>

// 定义点类
class Pnt
{
public:
	Pnt(){};
	Pnt(double xx, double yy):x(xx), y(yy){};
	//~Pnt(void);
	double getX(){return x;}
	double getY(){return y;}
	double getDist(Pnt other){return sqrt(pow(x-other.getX(),2)+pow(y-other.getY(),2));}  // 计算点和另一个点的距离

private:
	double x, y;
};

// 定义边结构体
struct Edge
{
	Pnt p1;
	Pnt p2;

	// 重载运算符
	bool operator == (Edge &e)
	{
		if(p1.getX()==e.p1.getX()&&p1.getY()==e.p1.getY()&&p2.getX()==e.p2.getX()&&p2.getY()==e.p2.getY())
			return true;
		else if(p1.getX()==e.p2.getX()&&p1.getY()==e.p2.getY()&&p2.getX()==e.p2.getX()&&p2.getY()==e.p2.getY())
			return true;
		return false;
	}
};

// 三角形类
class Triangle
{
public:
	Triangle(Pnt pp1, Pnt pp2, Pnt pp3):p1(pp1), p2(pp2), p3(pp3)
	{
		e1.p1 = p1; e1.p2 = p2;
		e2.p1 = p1; e2.p2 = p3;
		e3.p1 = p2; e3.p2 = p3;
	};
	~Triangle(void);
	void CalCircumcircle(Pnt &center, double &radius);  //计算三角形外接圆的半径及圆心
	//bool IsObtuseTriangle(Pnt &obtusePnt, Pnt &acutePnt1, Pnt &acutePnt2, Edge &longEdge); //判断是否是钝角三角形

	Pnt p1, p2, p3;
	Edge e1, e2, e3;
};

