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

//�û���¼
void CLogin::login()
{
	int form, showPinyin, playMusic;
	string userName;
	cout << "<---------��ʫ������--------->" << endl;
	cout << endl;
	cout << "------>�����������û���" << " ";
	cin >> userName;
	cout << endl;
	cout << "          ��¼��..." << endl;
	Sleep(2000);
	ifstream ifile(userName + ".txt");
	if (ifile)
	{
		cout << "          ��¼�ɹ���" << endl;
		cout << endl << "       ���" << userName << "����ӭ������" << endl;
		Sleep(1000);
		cout << endl << "------>�Ƿ�ʹ���ϴε����ã�(Y/N)" << " ";
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
		cout << "          ��¼ʧ�ܣ�" << endl;
		cout << endl;
		cout << "         �û������ڣ�" << endl;
		Sleep(1000);
		cout << endl;
		cout << "------>��ִ�е�һ������" << endl;
		Sleep(1000);
		CSetting * p_Setting = new CSetting();
		p_Setting->setting(userName);
	}
	ifile.close();
}
