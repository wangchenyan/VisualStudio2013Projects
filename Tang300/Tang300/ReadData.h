#pragma once
using namespace std;
#include "vector"
#include "string"
class CReadData
{
public:
	CReadData();
	~CReadData();
	//��ȡ��ʫ����
	virtual vector<int> getNum() = 0;
	//��ȡ���⣨���
	virtual vector<string> getTitle() = 0;
	virtual vector<string> getAuthor() = 0;
	virtual vector<vector<string>> getContent() = 0;
	//��ȡ����
	virtual void readData() = 0;
};

