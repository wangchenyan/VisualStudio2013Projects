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
	cout << "\t��֪Բ�εİ뾶Ϊ" << length_1 << "��������������ܳ�����PIȡ3.14�����������λС����" << endl;
}

float CCircular::calculateArea(int radius, int length_2, int length_3)
{
	return PI*radius*radius;
}

float CCircular::calculatePerimeter(int radius, int length_2, int length_3)
{
	return 2 * PI*radius;
}
