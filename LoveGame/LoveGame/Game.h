#pragma once
#include "Cat.h"
#include "Dog.h"
class CGame
{
public:
	CGame();
	~CGame();
	//׼����ʼ��Ϸ
	void prepare();
	//��Ϸ��ʼ
	void startGame();
private:
	CCat * pm_Cat;
	CDog * pm_Dog;
};

