#include "stdafx.h"
#include "Dog.h"
#include "iostream"
using namespace std;


CDog::CDog()
{
}


CDog::~CDog()
{
}

//��
void CDog::buyHouse()
{
	if (m_HaveHouse == false)
	{
		if (m_Savings >= m_HousePrice)
		{
			m_HaveHouse = true;
			m_Savings -= m_HousePrice;
			cout << "\t" << m_Name << "���˷�����ʣ" << m_Savings << endl;
		}
		else
		{
			cout << "\t" << m_Name << "Ŀǰ����" << endl;
		}
	}
}