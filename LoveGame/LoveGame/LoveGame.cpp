// LoveGame.cpp : �������̨Ӧ�ó������ڵ㡣
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

//��ӡ����
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
