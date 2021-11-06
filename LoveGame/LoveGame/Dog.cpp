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

//买房
void CDog::buyHouse()
{
	if (m_HaveHouse == false)
	{
		if (m_Savings >= m_HousePrice)
		{
			m_HaveHouse = true;
			m_Savings -= m_HousePrice;
			cout << "\t" << m_Name << "买了房，存款还剩" << m_Savings << endl;
		}
		else
		{
			cout << "\t" << m_Name << "目前买不起房" << endl;
		}
	}
}