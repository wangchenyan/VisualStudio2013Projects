#pragma once
class CPolygon
{
public:
	CPolygon();
	~CPolygon();
	//计算面积
	virtual float calculateArea(int a, int b, int c) = 0;
	//计算周长
	virtual float calculatePerimeter(int a, int b, int c) = 0;
	//打印题目
	virtual void printQuestion(int length_1, int length_2, int length_3) = 0;
};

