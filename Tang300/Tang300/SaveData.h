#pragma once
#include "iostream"
#include "vector"
using namespace std;
class CSaveData
{
public:
	CSaveData();
	~CSaveData();
	//�������ú��ղ�
	void save(int config[], string userName, vector<int> favorite);
};

