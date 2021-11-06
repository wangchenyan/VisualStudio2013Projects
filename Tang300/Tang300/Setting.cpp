#include "stdafx.h"
#include "Setting.h"
#include "iostream"
using namespace std;
#include "fstream"


CSetting::CSetting()
{
}


CSetting::~CSetting()
{
}

//����
void CSetting::setting(string userName)
{
	int form, showPinyin, playMusic;
	char yesOrNo;
	cout << endl;
	cout << "------>ѡ��ѧϰ��ʽ��" << endl;
	cout << "       1.˳��ѧϰ" << endl;
	cout << "       2.���ѧϰ" << endl;
	cout << "       3.���ղ���ѧϰ" << " ";
	cin >> form;
	if (form < 1 || form>3)
	{
		cout << "        �������" << endl;
		setting(userName);
		return;
	}
	if (form == 3)
	{
		int tmp, count;
		ifstream ifile(userName + ".txt");
		if (ifile)
		{
			ifile >> tmp >> tmp >> tmp >> count;
			if (count == EOF || count == 0)
			{
				cout << endl << "       ����û���ղ���ʫ�ޣ�" << endl;
				setting(userName);
				return;
			}
		}
		else
		{
			cout << endl << "       ����û���ղ���ʫ�ޣ�" << endl;
			setting(userName);
			return;
		}
	}
	cout << "------>�Ƿ���ʾƴ����(Y/N)" << " ";
	cin >> yesOrNo;
	if (yesOrNo == 'y' || yesOrNo == 'Y')
		showPinyin = 1;
	else
		showPinyin = 0;
	cout << "------>�Ƿ񲥷ű������֣�(Y/N)" << " ";
	cin >> yesOrNo;
	if (yesOrNo == 'y' || yesOrNo == 'Y')
		playMusic = 1;
	else
		playMusic = 0;
	int config[3] = { form, showPinyin, playMusic };

	CLearn * p_Learn = new CLearn();
	p_Learn->start(config, userName);
}
