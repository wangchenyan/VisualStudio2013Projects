#include "stdafx.h"
#include "Game.h"
#include "Cat.h"
#include "Dog.h"
#include "Animal.h"
#include "string"
#include "iostream"
#include "windows.h"
#include "time.h"
using namespace std;


CGame::CGame()
{
	pm_Cat = new CCat();
	pm_Dog = new CDog();
}


CGame::~CGame()
{
	delete pm_Cat;
	delete pm_Dog;
}

//准备开始游戏
void CGame::prepare()
{
	cout << "请输入小猫的基本信息" << endl;
	pm_Cat->animalInfo(pm_Cat);
	cout << endl;
	cout << "请输入小狗的基本信息" << endl;
	pm_Dog->animalInfo(pm_Dog);
	cout << endl;
	srand((int)time(0));
	if (rand() % 2 == 0)
	{
		pm_Dog->m_HaveHouse = true;
		cout << "\t" << pm_Dog->m_Name << "是个富二代，有一套别墅" << endl;
	}
	else
	{
		pm_Dog->m_HaveHouse = false;
		cout << "\t" << pm_Dog->m_Name << "是个穷光蛋，目前没有房子" << endl;
	}
	if (pm_Dog->m_HaveHouse == false){
		cout << "\t请输入房价：";
		cin >> pm_Dog->m_HousePrice;
	}
	cout << endl;
	pm_Cat->satisfied(pm_Cat);
	pm_Cat->loveIndex(pm_Cat);
	pm_Dog->loveIndex(pm_Dog);
	cout << endl;
}

//游戏开始
void CGame::startGame()
{
	prepare();
	int month;
	for (int i = 1; i <= 18; i++)
	{
		Sleep(1000);
		if (i % 12 == 0)
		{
			month = 12;
		}
		else
		{
			month = i % 12;
		}
		cout << month << "月" << endl;
		pm_Dog->savings(pm_Dog);
		if (month == pm_Cat->m_BirthMonth)
		{
			cout << "\t" << pm_Cat->m_Name << "过生日了" << endl;
			pm_Cat->m_LoveIndex += 1;
		}
		if (month == pm_Dog->m_BirthMonth)
		{
			cout << "\t" << pm_Dog->m_Name << "过生日了" << endl;
			pm_Dog->m_LoveIndex += 1;
		}
		switch (month)
		{
		case 1:
			cout << "\t元旦到了" << endl;
			pm_Cat->receiveGift(pm_Cat);
			pm_Dog->receiveGift(pm_Dog);
			break;
		case 2:
			cout << "\t情人节到了" << endl;
			pm_Cat->receiveGift(pm_Cat);
			pm_Dog->receiveGift(pm_Dog);
			break;
		case 7:
			cout << "\t七夕节到了" << endl;
			pm_Cat->receiveGift(pm_Cat);
			pm_Dog->receiveGift(pm_Dog);
			break;
		case 12:
			cout << "\t春节到了" << endl;
			pm_Cat->receiveGift(pm_Cat);
			pm_Dog->receiveGift(pm_Dog);
			break;
		default:
			break;
		}
		if (rand() % 4 == 0)
		{
			pm_Cat->m_LoveIndex -= 0.5;
			pm_Dog->m_LoveIndex -= 0.5;
			cout << "\t" << pm_Cat->m_Name << "和" << pm_Dog->m_Name << "吵架了" << endl;
		}
		pm_Dog->buyHouse();
		cout << "\t" << pm_Cat->m_Name << "对恋人的爱情指数为" << pm_Cat->m_LoveIndex << endl;
		cout << "\t" << pm_Dog->m_Name << "对恋人的爱情指数为" << pm_Dog->m_LoveIndex << endl;
		cout << endl;
		if (pm_Cat->m_LoveIndex >= 9 && pm_Dog->m_LoveIndex >= 9 && pm_Dog->m_HaveHouse == true)
		{
			break;
		}
	}
	if (pm_Cat->m_LoveIndex >= 9 && pm_Dog->m_LoveIndex >= 9 && pm_Dog->m_HaveHouse == true)
	{
		cout << pm_Cat->m_Name << "和" << pm_Dog->m_Name << "结婚了！" << endl;
	}
	else
	{
		cout << pm_Cat->m_Name << "和" << pm_Dog->m_Name << "分手了……" << endl;
	}
	cout << endl;
}