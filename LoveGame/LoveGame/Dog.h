#pragma once
#include "Animal.h"
class CDog :
	public CAnimal
{
public:
	CDog();
	~CDog();
	//����
	long m_HousePrice;
	//�Ƿ��з�
	bool m_HaveHouse;
	//��
	void buyHouse();
};

