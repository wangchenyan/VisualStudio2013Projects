#pragma once
#include "ReadData.h"
#include "vector"
class CLearn
{
public:
	CLearn();
	~CLearn();
	//开始学习
	void start(int config[], string userName);
private:
	//获取数据
	void getData();
	vector<int> num;
	vector<string> titlePin;
	vector<string> authorPin;
	vector<vector<string>> contentPin;
	vector<string> titleHan;
	vector<string> authorHan;
	vector<vector<string>> contentHan;
	//我的收藏
	vector<int> favorite;
	//顺序学习
	void orderLearn(int config[]);
	//随机学习
	void randomLearn(int config[]);
	//在收藏中学习
	void learnFavorite(int config[], string userName);
	//获取收藏夹
	void getFavorite(string userName);
	//加入收藏
	void addToFavorite(int num);
};

