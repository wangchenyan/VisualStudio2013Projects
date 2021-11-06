#pragma once
#include "ReadData.h"
#include "vector"
class CLearn
{
public:
	CLearn();
	~CLearn();
	//��ʼѧϰ
	void start(int config[], string userName);
private:
	//��ȡ����
	void getData();
	vector<int> num;
	vector<string> titlePin;
	vector<string> authorPin;
	vector<vector<string>> contentPin;
	vector<string> titleHan;
	vector<string> authorHan;
	vector<vector<string>> contentHan;
	//�ҵ��ղ�
	vector<int> favorite;
	//˳��ѧϰ
	void orderLearn(int config[]);
	//���ѧϰ
	void randomLearn(int config[]);
	//���ղ���ѧϰ
	void learnFavorite(int config[], string userName);
	//��ȡ�ղؼ�
	void getFavorite(string userName);
	//�����ղ�
	void addToFavorite(int num);
};

