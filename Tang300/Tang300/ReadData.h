#pragma once
using namespace std;
#include "vector"
#include "string"
class CReadData
{
public:
	CReadData();
	~CReadData();
	//获取唐诗数量
	virtual vector<int> getNum() = 0;
	//获取标题（汉语）
	virtual vector<string> getTitle() = 0;
	virtual vector<string> getAuthor() = 0;
	virtual vector<vector<string>> getContent() = 0;
	//读取数据
	virtual void readData() = 0;
};

