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

//�Ӽ������������Ϣ
void CAnimal::animalInfo(CAnimal * animal)
{
	cout << "\t��    ����"; cin >> animal->m_Name;
	cout << "\t��    �䣺"; cin >> animal->m_Age;
	cout << "\t�����·ݣ�"; cin >> animal->m_BirthMonth;
	cout << "\t��    �ʣ�"; cin >> animal->m_Salary;
	cout << "\t��    �ѣ�"; cin >> animal->m_Consumption;
	cout << "\t��    �"; cin >> animal->m_Savings;
}

//Ĭ�ϵİ���ָ��
void CAnimal::loveIndex(CAnimal * animal)
{
	animal->m_LoveIndex = (float)(rand() % 100) / 10;
	cout << "\t" << animal->m_Name << "�����˵İ���ָ��Ϊ" << animal->m_LoveIndex << endl;
}

//�ԶԷ��Ƿ�����˼
void CAnimal::satisfied(CAnimal * animal)
{
	if (rand() % 2 == 0)
	{
		cout << "\t" << animal->m_Name << "����������˼" << endl;
		animal->m_LoveIndex += 1;
	}
	else
	{
		cout << "\t" << animal->m_Name << "������û��˼" << endl;
	}
}

//����������Ƿ��յ�����
void CAnimal::receiveGift(CAnimal * animal)
{
	if (rand() % 3 == 0){
		cout << "\t" << animal->m_Name << "δ�յ����˵�����" << endl;
	}
	else
	{
		cout << "\t" << animal->m_Name << "�յ����˵�һ������" << endl;
		animal->m_LoveIndex += 2;
	}
}

//������
void CAnimal::savings(CAnimal * animal)
{
	animal->m_Savings += animal->m_Salary - animal->m_Consumption;
	cout << "\t" << animal->m_Name << "Ŀǰ�Ĵ��Ϊ" << animal->m_Savings << endl;
}
