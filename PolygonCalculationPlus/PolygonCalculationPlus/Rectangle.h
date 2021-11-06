#pragma once
#include "Polygon.h"
//³¤·½ÐÎ
class CRectangle :
	public CPolygon
{
public:
	CRectangle();
	~CRectangle();
	void printQuestion(int length_1, int length_2, int length_3);
	float calculateArea(int length, int width, int length_3);
	float calculatePerimeter(int length, int width, int length_3);
};

