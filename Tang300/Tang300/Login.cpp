#include "stdafx.h"
#include "Login.h"
#include "string"
#include "fstream"
#include "Setting.h"
#include "Learn.h"
#include "windows.h"


CLogin::CLogin()
{
}


CLogin::~CLogin()
{
}

//用户登录
void CLogin::login()
{
	int form, showPinyin, playMusic;
	string userName;
	cout << "<---------唐诗三百首--------->" << endl;
	cout << endl;
	cout << "------>请输入您的用户名" << " ";
	cin >> userName;
	cout << endl;
	cout << "          登录中..." << endl;
	Sleep(2000);
	ifstream ifile(userName + ".txt");
	if (ifile)
	{
		cout << "          登录成功！" << endl;
		cout << endl << "       你好" << userName << "，欢迎回来！" << endl;
		Sleep(1000);
		cout << endl << "------>是否使用上次的设置？(Y/N)" << " ";
		char yesOrNo;
		cin >> yesOrNo;
		if (yesOrNo == 'y' || yesOrNo == 'Y')
		{
			ifile >> form >> showPinyin >> playMusic;
			int config[3] = { form, showPinyin, playMusic };
			CLearn * p_Learn = new CLearn();
			p_Learn->start(config, userName);
		}
		else
		{
			CSetting * p_Setting = new CSetting();
			p_Setting->setting(userName);
		}
	}
	else
	{
		cout << "          登录失败！" << endl;
		cout << endl;
		cout << "         用户不存在！" << endl;
		Sleep(1000);
		cout << endl;
		cout << "------>请执行第一次设置" << endl;
		Sleep(1000);
		CSetting * p_Setting = new CSetting();
		p_Setting->setting(userName);
	}
	ifile.close();
}
