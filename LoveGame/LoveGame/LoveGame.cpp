// LoveGame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Game.h"
#include "iostream"


void printTitle();

int _tmain(int argc, _TCHAR* argv[])
{
	printTitle();
	CGame m_CGame;
	m_CGame.startGame();
	return 0;
}

//打印标题
void printTitle()
{
	cout << endl;
	cout << "       ******       ******" << endl;
	cout << "     **********   **********" << endl;
	cout << "   ************* *************" << endl;
	cout << "  *****************************" << endl;
	cout << "  ********** Love Game ********" << endl;
	cout << "  *****************************" << endl;
	cout << "   ***************************" << endl;
	cout << "     ***********************" << endl;
	cout << "       *******************" << endl;
	cout << "         ***************" << endl;
	cout << "           ***********" << endl;
	cout << "             *******" << endl;
	cout << "               ***" << endl;
	cout << "                *" << endl;
	cout << endl;
}
