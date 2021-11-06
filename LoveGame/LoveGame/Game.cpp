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

//׼����ʼ��Ϸ
void CGame::prepare()
{
	cout << "������Сè�Ļ�����Ϣ" << endl;
	pm_Cat->animalInfo(pm_Cat);
	cout << endl;
	cout << "������С���Ļ�����Ϣ" << endl;
	pm_Dog->animalInfo(pm_Dog);
	cout << endl;
	srand((int)time(0));
	if (rand() % 2 == 0)
	{
		pm_Dog->m_HaveHouse = true;
		cout << "\t" << pm_Dog->m_Name << "�Ǹ�����������һ�ױ���" << endl;
	}
	else
	{
		pm_Dog->m_HaveHouse = false;
		cout << "\t" << pm_Dog->m_Name << "�Ǹ���⵰��Ŀǰû�з���" << endl;
	}
	if (pm_Dog->m_HaveHouse == false){
		cout << "\t�����뷿�ۣ�";
		cin >> pm_Dog->m_HousePrice;
	}
	cout << endl;
	pm_Cat->satisfied(pm_Cat);
	pm_Cat->loveIndex(pm_Cat);
	pm_Dog->loveIndex(pm_Dog);
	cout << endl;
}

//��Ϸ��ʼ
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
		cout << month << "��" << endl;
		pm_Dog->savings(pm_Dog);
		if (month == pm_Cat->m_BirthMonth)
		{
			cout << "\t" << pm_Cat->m_Name << "��������" << endl;
			pm_Cat->m_LoveIndex += 1;
		}
		if (month == pm_Dog->m_BirthMonth)
		{
			cout << "\t" << pm_Dog->m_Name << "��������" << endl;
			pm_Dog->m_LoveIndex += 1;
		}
		switch (month)
		{
		case 1:
			cout << "\tԪ������" << endl;
			pm_Cat->receiveGift(pm_Cat);
			pm_Dog->receiveGift(pm_Dog);
			break;
		case 2:
			cout << "\t���˽ڵ���" << endl;
			pm_Cat->receiveGift(pm_Cat);
			pm_Dog->receiveGift(pm_Dog);
			break;
		case 7:
			cout << "\t��Ϧ�ڵ���" << endl;
			pm_Cat->receiveGift(pm_Cat);
			pm_Dog->receiveGift(pm_Dog);
			break;
		case 12:
			cout << "\t���ڵ���" << endl;
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
			cout << "\t" << pm_Cat->m_Name << "��" << pm_Dog->m_Name << "������" << endl;
		}
		pm_Dog->buyHouse();
		cout << "\t" << pm_Cat->m_Name << "�����˵İ���ָ��Ϊ" << pm_Cat->m_LoveIndex << endl;
		cout << "\t" << pm_Dog->m_Name << "�����˵İ���ָ��Ϊ" << pm_Dog->m_LoveIndex << endl;
		cout << endl;
		if (pm_Cat->m_LoveIndex >= 9 && pm_Dog->m_LoveIndex >= 9 && pm_Dog->m_HaveHouse == true)
		{
			break;
		}
	}
	if (pm_Cat->m_LoveIndex >= 9 && pm_Dog->m_LoveIndex >= 9 && pm_Dog->m_HaveHouse == true)
	{
		cout << pm_Cat->m_Name << "��" << pm_Dog->m_Name << "����ˣ�" << endl;
	}
	else
	{
		cout << pm_Cat->m_Name << "��" << pm_Dog->m_Name << "�����ˡ���" << endl;
	}
	cout << endl;
}