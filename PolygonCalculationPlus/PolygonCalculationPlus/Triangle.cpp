#include "stdafx.h"
#include "Triangle.h"
#include "iostream"
#include "math.h"
using namespace std;


CTriangle::CTriangle()
{
}


CTriangle::~CTriangle()
{
}

void CTriangle::printQuestion(int length_1, int length_2, int length_3)
{
	cout << "\t已知三角形的三边长为" << length_1 << "，" << length_2 << "，" << length_3 << "，计算其面积和周长。（结果保留两位小数）" << endl;
}

float CTriangle::calculateArea(int bottom, int leftSideLength, int rightSideLength)
{
	float p = (bottom + leftSideLength + rightSideLength) / 2;
	return (float)sqrt(p*(p - bottom)*(p - leftSideLength)*(p - rightSideLength));
}

float CTriangle::calculatePerimeter(int bottom, int leftSideLength, int rightSideLength)
{
	return bottom + leftSideLength + rightSideLength;
}