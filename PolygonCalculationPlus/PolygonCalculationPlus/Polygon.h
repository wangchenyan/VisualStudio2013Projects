#pragma once
class CPolygon
{
public:
	CPolygon();
	~CPolygon();
	//�������
	virtual float calculateArea(int length_1, int length_2, int length_3) = 0;
	//�����ܳ�
	virtual float calculatePerimeter(int length_1, int length_2, int length_3) = 0;
	//��ӡ��Ŀ
	virtual void printQuestion(int length_1, int length_2, int length_3) = 0;
};

