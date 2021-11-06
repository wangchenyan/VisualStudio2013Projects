#pragma once
#include "Polygon.h"
//Õý·½ÐÎ
class CSquare :
	public CPolygon
{
public:
	CSquare();
	~CSquare();
	void printQuestion(int length_1, int length_2, int length_3);
	float calculateArea(int length, int length_2, int length_3);
	float calculatePerimeter(int length, int length_2, int length_3);
};

