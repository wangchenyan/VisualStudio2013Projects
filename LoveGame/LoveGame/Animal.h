#pragma once
#include "string"
using namespace std;
class CAnimal
{
public:
	CAnimal();
	~CAnimal();
	//姓名
	string m_Name;
	//年龄
	int m_Age;
	//出生月份
	int m_BirthMonth;
	//存款
	long m_Savings;
	//爱情指数
	float m_LoveIndex;
	//从键盘输入基本信息
	void animalInfo(CAnimal * animal);
	//默认的爱情指数
	void loveIndex(CAnimal * animal);
	//对恋人是否有意思
	void satisfied(CAnimal * animal);
	//在特殊节日是否收到礼物
	void receiveGift(CAnimal * animal);
	//计算存款
	void savings(CAnimal * animal);
protected:
	//基本生活消费
	long m_Consumption;
	//工资
	long m_Salary;
};

