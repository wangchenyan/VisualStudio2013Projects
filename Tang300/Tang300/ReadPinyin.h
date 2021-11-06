#pragma once
#include "ReadData.h"
class CReadPinyin :
	public CReadData
{
public:
	CReadPinyin();
	~CReadPinyin();
	vector<int> getNum();
	vector<string> getTitle();
	vector<string> getAuthor();
	vector<vector<string>> getContent();
private:
	//¶ÁÈ¡Êý¾Ý
	void readData();
	vector<int> num;
	vector<string> title;
	vector<string> author;
	vector<vector<string>> content;
};

