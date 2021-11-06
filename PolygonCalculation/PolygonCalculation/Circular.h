#pragma once
#include "Polygon.h"
//т╡пн
class CCircular :
	public CPolygon
{
public:
	CCircular();
	~CCircular();
	float calculateArea(int radius, int length_2, int length_3);
	float calculatePerimeter(int radius, int length_2, int length_3);
	void printQuestion(int length_1, int length_2, int length_3);
};

