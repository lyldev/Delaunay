#include "Delaunay.h"


Delaunay::Delaunay(void)
{
}


Delaunay::~Delaunay(void)
{
}

vector<Triangle> Delaunay::IncremInsert(vector<Pnt> vertexList)
{
	// 获取x,y的min和max值
	vector<Pnt>::iterator iter;
	double Xmin=-1, Ymin=-1, Xmax=0, Ymax=0;
	for(iter=vertexList.begin(); iter!=vertexList.end(); iter++)
	{
		//Xmin=-1, Ymin=-1;
		if(Xmin=-1||iter->getX()<Xmin)
			Xmin=iter->getX();
		if(Ymin=-1||iter->getY()<Ymin)
			Ymin=iter->getY();

		//Xmax=0, Ymax=0;
		if(iter->getX()>Xmax)
			Xmax=iter->getX();
		if(iter->getY()>Ymax)
			Ymax=iter->getY();
	}

	// 生成SuperTriangle
	double half = (Xmax-Xmin)/2; // 最大x 和 最小x 间距的一半
	double Xmid = Xmin + half, Ymid = Ymin; // 底边中点坐标

	double Xrd = Xmid + 2*half + 10, Yrd = Ymin-10;
	double Xld = Xmid - 2*half - 10, Yld = Ymin-10;
	double Xup = Xmid, Yup = Ymax+(Ymax-Ymin);

	Pnt prd(Xrd,Yrd), pld(Xld,Yld), pup(Xup,Yup);
	vertexList.push_back(prd);
	vertexList.push_back(pld);
	vertexList.push_back(pup);
	
	Triangle superTri(prd, pld, pup);
	vector<Triangle> triangleList;
	triangleList.push_back(superTri);

	vector<Pnt>::iterator i_p;
	for(i_p=vertexList.begin(); i_p!=vertexList.end(); i_p++)
	{
		//initialize the edge buffer
		vector<Edge> edgeBuffer;

		vector<Triangle>::iterator i_t;
		for(i_t=triangleList.begin(); i_t!=triangleList.end(); ) //error??
		{
			// 计算三角形外接圆圆心和半径
			Pnt center; double radius;
			i_t->CalCircumcircle(center, radius);
			// 如果点在外接圆内，把三角形的三条边加到edgeBuffer中，将当前三角形从trangleList中删除
			if(i_p->getDist(center)<radius)
			{
				edgeBuffer.push_back(i_t->e1);
				edgeBuffer.push_back(i_t->e2);
				edgeBuffer.push_back(i_t->e2);
				triangleList.erase(i_t);
			}
			else
				i_t++;

		}

		// 对edgeBuffer中的边进行去重
		vector<Edge>::iterator i_e, j_e;
		for(i_e=edgeBuffer.begin(); i_e!=edgeBuffer.end(); i_e++)
		{
			for(j_e=edgeBuffer.begin(); j_e!=edgeBuffer.end(); )
			{
				if(i_e==j_e)
					edgeBuffer.erase(j_e);
				else
					j_e++;
			}
		}

		// 将edgeBuffer中的边与当前的点组合成若干三角形并添加到trangleList
		vector<Edge>::iterator i_e2;
		for(i_e2=edgeBuffer.begin(); i_e2!=edgeBuffer.end(); i_e2++)
		{
			Triangle t(*i_p, i_e2->p1, i_e2->p2);
			triangleList.push_back(t);
		}
	}

	// 删除triangleList中使用 超级三角形顶点 的三角形
	vector<Triangle>::iterator i_t;
	for(i_t=triangleList.begin(); i_t!=triangleList.end(); )
	{
		if((i_t->p1.getX()==prd.getX()&&i_t->p1.getY()==prd.getY()) ||
		     (i_t->p2.getX()==prd.getX()&&i_t->p2.getY()==prd.getY()) ||
		     (i_t->p3.getX()==prd.getX()&&i_t->p3.getY()==prd.getY()))
			triangleList.erase(i_t);
		if((i_t->p1.getX()==pld.getX()&&i_t->p1.getY()==pld.getY()) ||
			 (i_t->p2.getX()==pld.getX()&&i_t->p2.getY()==pld.getY()) ||
			 (i_t->p3.getX()==pld.getX()&&i_t->p3.getY()==pld.getY()))
			triangleList.erase(i_t);
		if((i_t->p1.getX()==pup.getX()&&i_t->p1.getY()==pup.getY()) ||
		     (i_t->p2.getX()==pup.getX()&&i_t->p2.getY()==pup.getY()) ||
		     (i_t->p3.getX()==pup.getX()&&i_t->p3.getY()==pup.getY()))
			triangleList.erase(i_t);
		else
			i_t++;
	}

	// 从vertextList中删除超级三角形的顶点
	vector<Pnt>::iterator i_v;
	for(i_v=vertexList.begin(); i_v!=vertexList.end(); )
	{
		if((i_v->getX()==prd.getX()&&i_v->getY()==prd.getY())||
			(i_v->getX()==pld.getX()&&i_v->getY()==pld.getY())||
			(i_v->getX()==pup.getX()&&i_v->getY()==pup.getY()))
			vertexList.erase(i_v);
		else
			i_v++;
	}

	return triangleList;
}
