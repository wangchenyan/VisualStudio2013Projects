#pragma once
#include "iostream"
#include "vector"
using namespace std;
class CSaveData
{
public:
	CSaveData();
	~CSaveData();
	//保存设置和收藏
	void save(int config[], string userName, vector<int> favorite);
};

