#pragma once
class CPolygon
{
public:
	CPolygon();
	~CPolygon();
	//�������
	virtual float calculateArea(int a, int b, int c) = 0;
	//�����ܳ�
	virtual float calculatePerimeter(int a, int b, int c) = 0;
	//��ӡ��Ŀ
	virtual void printQuestion(int length_1, int length_2, int length_3) = 0;
};

