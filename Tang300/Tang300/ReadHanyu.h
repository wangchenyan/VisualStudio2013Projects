#pragma once
#include "ReadData.h"
class CReadHanyu :
	public CReadData
{
public:
	CReadHanyu();
	~CReadHanyu();
	vector<int> getNum();
	vector<string> getTitle();
	vector<string> getAuthor();
	vector<vector<string>> getContent();
private:
	//��ȡ����
	void readData();
	vector<int> num;
	vector<string> title;
	vector<string> author;
	vector<vector<string>> content;
};

