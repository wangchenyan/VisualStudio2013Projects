#pragma once
#include "Polygon.h"
//Բ��
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

