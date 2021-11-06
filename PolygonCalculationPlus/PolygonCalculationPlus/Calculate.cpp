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

//答题开始
void CCalculate::start()
{
	readHistory();
	calculateScore();
	save();
}

//读取历史记录
void CCalculate::readHistory()
{
	char yesOrNo;
	cout << "答题开始" << endl;
	cout << "是否读取上次答题信息？（Y/N）" << endl;
	cin >> yesOrNo;
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		int type;
		ifstream ifile("history.txt");
		if (ifile){
			ifile >> questionNum >> score;
			for (int i = 0; i < questionNum; i++)
			{
				ifile >> type;
				switch (type)
				{
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
				classType.push_back(type);
			}
			for (int i = 0; i < questionNum; i++)
				ifile >> length_1[i] >> length_2[i] >> length_3[i];
			ifile.close();
			for (int i = 0; i < questionNum; i++)
			{
				cout << "题目" << i + 1 << endl;
				m_polygon[i]->printQuestion(length_1[i], length_2[i], length_3[i]);
				area[i] = m_polygon[i]->calculateArea(length_1[i], length_2[i], length_3[i]);
				perimeter[i] = m_polygon[i]->calculatePerimeter(length_1[i], length_2[i], length_3[i]);
				cout << endl;
			}
			cout << "上次答题情况为：" << "满分" << questionNum << "分，" << "您的成绩为" << score << "分。" << endl;
			cout << endl;
			cout << "请输入答案（答案用空格分开）" << endl;
			cout << endl;
		}
		else
		{
			cout << "历史文件不存在！" << endl;
			createQuestion();
		}
	}
	else
	{
		createQuestion();
	}
}

//创建题目
void CCalculate::createQuestion()
{
	cout << "请输入要练习的题目数 ";
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
		classType.push_back(type);
	}
	for (int i = 0; i < questionNum; i++)
	{
		cout << "题目" << i + 1 << endl;
		length_1[i] = rand() % 4 + 5;
		length_2[i] = rand() % 4 + 5;
		length_3[i] = rand() % 4 + 5;
		m_polygon[i]->printQuestion(length_1[i], length_2[i], length_3[i]);
		area[i] = m_polygon[i]->calculateArea(length_1[i], length_2[i], length_3[i]);
		perimeter[i] = m_polygon[i]->calculatePerimeter(length_1[i], length_2[i], length_3[i]);
		cout << endl;
	}
	cout << "请输入答案（答案用空格分开）" << endl;
	cout << endl;
}

//计算分数
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
		cout << "题目" << i + 1 << endl;
		cout << "\t您的答案 " << userArea[i] << " " << userPerimeter[i] << endl;
		cout << "\t正确答案 ";
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
	cout << "\t满分为" << questionNum << "分，" << "您的成绩为" << score << "分。" << endl;
}

//保存题目及答题情况
void CCalculate::save()
{
	char yesOrNo;
	cout << endl;
	cout << "是否保存题目及答题情况？（Y/N）" << endl;
	cin >> yesOrNo;
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		ofstream ofile("history.txt");
		ofile << questionNum << " " << score << endl;
		for (int i = 0; i < questionNum; i++)
		{
			if (i == questionNum - 1)
				ofile << classType[i] << endl;
			else
				ofile << classType[i] << " ";
		}
		for (int i = 0; i < questionNum; i++)
		{
			ofile << length_1[i] << " " << length_2[i] << " " << length_3[i] << endl;
		}
		ofile.close();
		cout << "保存成功" << endl;
	}
	cout << "答题结束。" << endl;
}
