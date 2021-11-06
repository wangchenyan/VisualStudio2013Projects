#pragma once
#include "Animal.h"
class CDog :
	public CAnimal
{
public:
	CDog();
	~CDog();
	//房价
	long m_HousePrice;
	//是否有房
	bool m_HaveHouse;
	//买房
	void buyHouse();
};

