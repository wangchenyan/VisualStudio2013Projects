#include "stdafx.h"
#include "Circular.h"
#include "iostream"
using namespace std;
#define PI 3.14


CCircular::CCircular()
{
}


CCircular::~CCircular()
{
}

void CCircular::printQuestion(int length_1, int length_2, int length_3)
{
	cout << "\t已知圆形的半径为" << length_1 << "，计算其面积和周长。（PI取3.14，结果保留两位小数）" << endl;
}

float CCircular::calculateArea(int radius, int length_2, int length_3)
{
	return PI*radius*radius;
}

float CCircular::calculatePerimeter(int radius, int length_2, int length_3)
{
	return 2 * PI*radius;
}
