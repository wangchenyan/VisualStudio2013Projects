#pragma once
#include "string"
using namespace std;
class CAnimal
{
public:
	CAnimal();
	~CAnimal();
	//����
	string m_Name;
	//����
	int m_Age;
	//�����·�
	int m_BirthMonth;
	//���
	long m_Savings;
	//����ָ��
	float m_LoveIndex;
	//�Ӽ������������Ϣ
	void animalInfo(CAnimal * animal);
	//Ĭ�ϵİ���ָ��
	void loveIndex(CAnimal * animal);
	//�������Ƿ�����˼
	void satisfied(CAnimal * animal);
	//����������Ƿ��յ�����
	void receiveGift(CAnimal * animal);
	//������
	void savings(CAnimal * animal);
protected:
	//������������
	long m_Consumption;
	//����
	long m_Salary;
};

