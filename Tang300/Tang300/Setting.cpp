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

//设置
void CSetting::setting(string userName)
{
	int form, showPinyin, playMusic;
	char yesOrNo;
	cout << endl;
	cout << "------>选择学习形式：" << endl;
	cout << "       1.顺序学习" << endl;
	cout << "       2.随机学习" << endl;
	cout << "       3.在收藏中学习" << " ";
	cin >> form;
	if (form < 1 || form>3)
	{
		cout << "        输入错误！" << endl;
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
				cout << endl << "       您还没有收藏唐诗噢！" << endl;
				setting(userName);
				return;
			}
		}
		else
		{
			cout << endl << "       您还没有收藏唐诗噢！" << endl;
			setting(userName);
			return;
		}
	}
	cout << "------>是否显示拼音？(Y/N)" << " ";
	cin >> yesOrNo;
	if (yesOrNo == 'y' || yesOrNo == 'Y')
		showPinyin = 1;
	else
		showPinyin = 0;
	cout << "------>是否播放背景音乐？(Y/N)" << " ";
	cin >> yesOrNo;
	if (yesOrNo == 'y' || yesOrNo == 'Y')
		playMusic = 1;
	else
		playMusic = 0;
	int config[3] = { form, showPinyin, playMusic };

	CLearn * p_Learn = new CLearn();
	p_Learn->start(config, userName);
}
