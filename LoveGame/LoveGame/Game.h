#pragma once
#include "Cat.h"
#include "Dog.h"
class CGame
{
public:
	CGame();
	~CGame();
	//准备开始游戏
	void prepare();
	//游戏开始
	void startGame();
private:
	CCat * pm_Cat;
	CDog * pm_Dog;
};

