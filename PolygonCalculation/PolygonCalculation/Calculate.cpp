#include "stdafx.h"
#include "Calculate.h"
#include "iostream"
#include "time.h"
#include "fstream"

CCalculate::CCalculate()
{
}


CCalculate::~CCalculate()
{
	delete pm_Polygon;
}

//���⿪ʼ
void CCalculate::start()
{
	createQuestion();
	calculateScore();
}

//������Ŀ
void CCalculate::createQuestion()
{
	cout << "������Ҫ��ϰ����Ŀ�� ";
	cin >> questionNum;
	cout << endl;
	srand((int)time(0));
	for (int i = 0; i < questionNum; i++)
	{
		int type = rand() % 4;
		switch (type){
		case 0:
			pm_Polygon = new CSquare();
			break;
		case 1:
			pm_Polygon = new CRectangle();
			break;
		case 2:
			pm_Polygon = new CCircular();
			break;
		case 3:
			pm_Polygon = new CTriangle();
			break;
		default:
			break;
		}
		m_polygon.push_back(pm_Polygon);
	}
	for (int i = 0; i < questionNum; i++)
	{
		cout << "��Ŀ" << i + 1 << endl;
		length_1[i] = rand() % 4 + 5;
		length_2[i] = rand() % 4 + 5;
		length_3[i] = rand() % 4 + 5;
		m_polygon[i]->printQuestion(length_1[i], length_2[i], length_3[i]);
		area[i] = m_polygon[i]->calculateArea(length_1[i], length_2[i], length_3[i]);
		perimeter[i] = m_polygon[i]->calculatePerimeter(length_1[i], length_2[i], length_3[i]);
		cout << endl;
	}
	cout << "������𰸣����ÿո�ֿ���" << endl;
	cout << endl;
}

//�������
void CCalculate::calculateScore()
{
	float userArea[100], userPerimeter[100];
	score = 0;
	for (int i = 0; i < questionNum; i++)
	{
		cin >> userArea[i];
		cin >> userPerimeter[i];
		if (userArea[i] == area[i] && userPerimeter[i] == perimeter[i])
		{
			score++;
		}
	}
	cout << endl;
	for (int i = 0; i < questionNum; i++)
	{
		cout << "��Ŀ" << i + 1 << endl;
		cout << "\t���Ĵ� " << userArea[i] << " " << userPerimeter[i] << endl;
		cout << "\t��ȷ�� ";
		if (area[i] - (int)area[i] != 0)
		{
			printf("%0.2f ", area[i]);
		}
		else{
			cout << area[i] << " ";
		}
		if (perimeter[i] - (int)perimeter[i] != 0)
		{
			printf("%0.2f\n", perimeter[i]);
		}
		else{
			cout << perimeter[i] << " " << endl;
		}
		cout << endl;
	}
	cout << "\t����Ϊ" << questionNum << "�֣�" << "���ĳɼ�Ϊ" << score << "�֡�" << endl;
	cout << "\t���������" << endl;
}

