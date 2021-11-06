#include "stdafx.h"
#include "Learn.h"
#include "SaveData.h"
#include "PlayMusic.h"
#include "iostream"
using namespace std;
#include "time.h"
#include "windows.h"
#include "fstream"
#include "ReadHanyu.h"
#include "ReadPinyin.h"


CLearn::CLearn()
{
	getData();
}


CLearn::~CLearn()
{
}

//��ȡ����
void CLearn::getData()
{
	CReadData * p_ReadData;
	p_ReadData = new CReadPinyin();
	num = p_ReadData->getNum();
	titlePin = p_ReadData->getTitle();
	authorPin = p_ReadData->getAuthor();
	contentPin = p_ReadData->getContent();
	p_ReadData = new CReadHanyu();
	titleHan = p_ReadData->getTitle();
	authorHan = p_ReadData->getAuthor();
	contentHan = p_ReadData->getContent();
}

//��ʼѧϰ
void CLearn::start(int config[], string userName)
{
	int form, showPinyin, playMusic;
	form = config[0];
	showPinyin = config[1];
	playMusic = config[2];
	if (playMusic)
	{
		CPlayMusic * p_PlayMusic = new CPlayMusic();
		p_PlayMusic->playMusic();
	}
	cout << endl << "<----------��ʼѧϰ---------->" << endl;
	Sleep(1000);
	if (form == 1)
		orderLearn(config);
	else if (form == 2)
		randomLearn(config);
	else
	{
		learnFavorite(config, userName);
	}

	//�������ú��ղ�
	CSaveData * p_SaveData = new CSaveData();
	p_SaveData->save(config, userName, favorite);
}

//˳��ѧϰ
void CLearn::orderLearn(int config[])
{
	int form, showPinyin;
	form = config[0];
	showPinyin = config[1];
	int start = 0, i = 0, k;
	while (true)
	{
		cout << endl << i + 1 << endl;
		k = num[i] - 1;
		if (showPinyin == 1)
			cout << titlePin[k] << endl;
		cout << titleHan[k] << endl;
		if (showPinyin == 1)
			cout << authorPin[k] << endl;
		cout << authorHan[k] << endl;
		for (int j = 0; j < (contentHan[k]).size(); j++)
		{
			if (showPinyin == 1)
				cout << contentPin[k][j] << endl;
			cout << contentHan[k][j] << endl;
		}
		Sleep(1000);
		cout << endl;
		if (form != 3)
		{
			addToFavorite(num[i]);
		}
		i++;
		if (i == num.size())
		{
			cout << endl << "     ����ѧϰ���ȫ����ʫ��" << endl;
			break;
		}
		cout << "------>�Ƿ����ѧϰ��(Y/N)" << " ";
		char yesOrNo;
		cin >> yesOrNo;
		if (yesOrNo == 'y' || yesOrNo == 'Y')
		{
			start += 5;
			continue;
		}
		else
		{
			cout << "       ѧϰ������" << endl;
			break;
		}
	}
}

//���ѧϰ
void CLearn::randomLearn(int config[])
{
	int  showPinyin = config[1];
	int i = 1, index;
	srand((int)time(0));
	while (true)
	{
		index = rand() % num.size();
		cout << endl << i << endl;
		if (showPinyin == 1)
			cout << titlePin[index] << endl;
		cout << titleHan[index] << endl;
		if (showPinyin == 1)
			cout << authorPin[index] << endl;
		cout << authorHan[index] << endl;
		for (int j = 0; j < (contentHan[index]).size(); j++)
		{
			if (showPinyin == 1)
				cout << contentPin[index][j] << endl;
			cout << contentHan[index][j] << endl;
		}
		Sleep(1000);
		cout << endl;
		addToFavorite(num[index]);
		i++;
		cout << "------>�Ƿ����ѧϰ��(Y/N)" << " ";
		char yesOrNo;
		cin >> yesOrNo;
		if (yesOrNo == 'y' || yesOrNo == 'Y')
		{
			continue;
		}
		else
		{
			cout << "       ѧϰ������" << endl;
			break;
		}
	}
}

//���ղ���ѧϰ
void CLearn::learnFavorite(int config[], string userName)
{
	getFavorite(userName);
	orderLearn(config);
}

//��ȡ�ղؼ�
void CLearn::getFavorite(string userName)
{
	vector<int> num;
	ifstream ifile(userName + ".txt");
	int tmp, count;
	ifile >> tmp >> tmp >> tmp >> count;
	for (int i = 0; i < count; i++)
	{
		ifile >> tmp;
		num.push_back(tmp);
	}
	CLearn::num = num;
}

//�����ղ�
void CLearn::addToFavorite(int num)
{
	cout << "------>�Ƿ�����ղأ�(Y/N)" << " ";
	char yesOrNo;
	cin >> yesOrNo;
	if (yesOrNo == 'y' || yesOrNo == 'Y')
	{
		favorite.push_back(num);
	}
}
