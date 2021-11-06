#include "stdafx.h"
#include "Square.h"
#include "iostream"
using namespace std;


CSquare::CSquare()
{
}


CSquare::~CSquare()
{
}

void CSquare::printQuestion(int length_1, int length_2, int length_3)
{
	cout << "\t已知正方形的边长为" << length_1 << "，计算其面积和周长。" << endl;
}

float CSquare::calculateArea(int length, int length_2, int length_3)
{
	return length*length;
}

float CSquare::calculatePerimeter(int length, int length_2, int length_3)
{
	return length * 4;
}