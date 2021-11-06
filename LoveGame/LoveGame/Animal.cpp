#include "stdafx.h"
#include "Animal.h"
#include "iostream"
using namespace std;

CAnimal::CAnimal()
{
}


CAnimal::~CAnimal()
{
}

//从键盘输入基本信息
void CAnimal::animalInfo(CAnimal * animal)
{
	cout << "\t姓    名："; cin >> animal->m_Name;
	cout << "\t年    龄："; cin >> animal->m_Age;
	cout << "\t出生月份："; cin >> animal->m_BirthMonth;
	cout << "\t工    资："; cin >> animal->m_Salary;
	cout << "\t消    费："; cin >> animal->m_Consumption;
	cout << "\t存    款："; cin >> animal->m_Savings;
}

//默认的爱情指数
void CAnimal::loveIndex(CAnimal * animal)
{
	animal->m_LoveIndex = (float)(rand() % 100) / 10;
	cout << "\t" << animal->m_Name << "对恋人的爱情指数为" << animal->m_LoveIndex << endl;
}

//对对方是否有意思
void CAnimal::satisfied(CAnimal * animal)
{
	if (rand() % 2 == 0)
	{
		cout << "\t" << animal->m_Name << "对恋人有意思" << endl;
		animal->m_LoveIndex += 1;
	}
	else
	{
		cout << "\t" << animal->m_Name << "对恋人没意思" << endl;
	}
}

//在特殊节日是否收到礼物
void CAnimal::receiveGift(CAnimal * animal)
{
	if (rand() % 3 == 0){
		cout << "\t" << animal->m_Name << "未收到恋人的礼物" << endl;
	}
	else
	{
		cout << "\t" << animal->m_Name << "收到恋人的一份礼物" << endl;
		animal->m_LoveIndex += 2;
	}
}

//计算存款
void CAnimal::savings(CAnimal * animal)
{
	animal->m_Savings += animal->m_Salary - animal->m_Consumption;
	cout << "\t" << animal->m_Name << "目前的存款为" << animal->m_Savings << endl;
}
