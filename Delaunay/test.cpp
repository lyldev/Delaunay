#include "Delaunay.h"
#include <fstream>
#include <string>
//#include <string.h>


using namespace std;

void main()
{

	// 生成样本点，对程序进行测试
	vector<Pnt> vlist;
	Pnt p1(10,20),p2(20,10),p3(30,30),p4(40,50),p5(50,30),p6(40,20);
	vlist.push_back(p1);vlist.push_back(p2);vlist.push_back(p3);
	vlist.push_back(p4);vlist.push_back(p5);vlist.push_back(p6);

	Delaunay dln;
	vector<Triangle> t = dln.IncremInsert(vlist);
	cout<<t.size()<<endl;
	for(int i=0; i<t.size(); i++)
	{
		cout<<"("<<t[i].p1.getX()<<","<<t[i].p1.getY()<<")";
		cout<<"("<<t[i].p2.getX()<<","<<t[i].p2.getY()<<")";
		cout<<"("<<t[i].p3.getX()<<","<<t[i].p3.getY()<<")"<<endl;
	}

	/*Pnt p1(0,0), p2(1,1), p3(2,0);
	Triangle tri(p1,p2,p3);
	Pnt center; double radius;
	tri.CalCircumcircle(center, radius);
	cout<<center.getX()<<","<<center.getY()<<endl;*/

	/*Pnt p1(0,0), p2(1,2), p3(2,0);
	Triangle tri(p1,p2,p3);

	Pnt op, ap1, ap2; Edge e;
	if(tri.IsObtuseTriangle(op, ap1, ap2, e))
	{
		cout<<"..."<<endl;	
	}*/
}