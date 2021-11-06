#include "stdafx.h"
#include "SaveData.h"
#include "fstream"
#include "algorithm"
using namespace std;

CSaveData::CSaveData()
{
}

CSaveData::~CSaveData()
{
}

//�������ú��ղ�
void CSaveData::save(int config[], string userName, vector<int> favorite)
{
	int form, showPinyin, playMusic;
	form = config[0];
	showPinyin = config[1];
	playMusic = config[2];
	int tmp, count;
	ifstream ifile(userName + ".txt");
	ifile >> tmp >> tmp >> tmp;
	ifile >> count;
	if (count == EOF || count == 0)
	{
		ifile.close();
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			int tmp;
			ifile >> tmp;
			favorite.push_back(tmp);
		}
		ifile.close();
	}
	//���ղؼн�������ȥ��
	sort(favorite.begin(), favorite.end());
	vector<int>::iterator pos;
	pos = unique(favorite.begin(), favorite.end());
	favorite.erase(pos, favorite.end());
	//���ղؼд����ļ�
	ofstream ofile(userName + ".txt");
	ofile << form << " " << showPinyin << " " << playMusic << endl;
	ofile << favorite.size();
	for (int i = 0; i < favorite.size(); i++)
	{
		ofile << " " << favorite[i];
	}
	ofile.close();
}
