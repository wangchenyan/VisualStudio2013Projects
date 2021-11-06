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
	cout << "\t��֪�����ε����߳�Ϊ" << length_1 << "��" << length_2 << "��" << length_3 << "��������������ܳ��������������λС����" << endl;
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