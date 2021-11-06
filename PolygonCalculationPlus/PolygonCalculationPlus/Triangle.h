#pragma once
#include "Polygon.h"
//Èý½ÇÐÎ
class CTriangle :
	public CPolygon
{
public:
	CTriangle();
	~CTriangle();
	void printQuestion(int length_1, int length_2, int length_3);
	float calculateArea(int bottom, int leftSideLength, int rightSideLength);
	float calculatePerimeter(int bottom, int leftSideLength, int rightSideLength);
};

