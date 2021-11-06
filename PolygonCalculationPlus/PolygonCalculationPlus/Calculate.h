#pragma once
#include "Square.h"
#include "Rectangle.h"
#include "Circular.h"
#include "Triangle.h"
#include "Polygon.h"
#include "vector"
using namespace std;
class CCalculate
{
public:
	CCalculate();
	~CCalculate();
	void start();
private:
	vector<CPolygon *> m_polygon;
	CPolygon *pm_Polygon;
	int questionNum;
	int score;
	vector<int> classType;
	int length_1[100];
	int length_2[100];
	int length_3[100];
	float area[100];
	float perimeter[100];
	void readHistory();
	void createQuestion();
	void calculateScore();
	void save();
};

