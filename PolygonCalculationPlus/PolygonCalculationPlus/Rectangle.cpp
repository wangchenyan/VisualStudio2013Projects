#include "stdafx.h"
#include "Rectangle.h"
#include "iostream"
using namespace std;


CRectangle::CRectangle()
{
}


CRectangle::~CRectangle()
{
}

void CRectangle::printQuestion(int length_1, int length_2, int length_3)
{
	cout << "\t已知长方形的长为" << length_1 << "，宽为" << length_2 << "，计算其面积和周长。" << endl;
}

float CRectangle::calculateArea(int length, int width, int length_3)
{
	return length*width;
}

float CRectangle::calculatePerimeter(int length, int width, int length_3)
{
	return (length + width) * 2;
}
