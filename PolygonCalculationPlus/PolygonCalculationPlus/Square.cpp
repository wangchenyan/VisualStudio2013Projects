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
	cout << "\t��֪�����εı߳�Ϊ" << length_1 << "��������������ܳ���" << endl;
}

float CSquare::calculateArea(int length, int length_2, int length_3)
{
	return length*length;
}

float CSquare::calculatePerimeter(int length, int length_2, int length_3)
{
	return length * 4;
}