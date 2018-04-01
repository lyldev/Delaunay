#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
//#include "Pnt.h"
#include "Triangle.h"

using namespace std;

class Delaunay
{
public:
	Delaunay(void);
	~Delaunay(void);

	vector<Triangle> IncremInsert(vector<Pnt> vertexList);
};

