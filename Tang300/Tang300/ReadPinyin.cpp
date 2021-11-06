#include "stdafx.h"
#include "ReadPinyin.h"
#include "fstream"
#include "iostream"
using namespace std;


CReadPinyin::CReadPinyin()
{
	readData();
}


CReadPinyin::~CReadPinyin()
{
}

//读取数据
void CReadPinyin::readData()
{
	int sum, num, lineNum;
	string strTemp;
	ifstream ifile("tangshi.txt");
	if (ifile)
	{
		ifile >> sum;
		for (int i = 0; i < sum; i++)
		{
			ifile >> num >> lineNum;
			CReadPinyin::num.push_back(num);
			getline(ifile, strTemp);
			getline(ifile, strTemp);
			title.push_back(strTemp);
			getline(ifile, strTemp);
			getline(ifile, strTemp);
			author.push_back(strTemp);
			getline(ifile, strTemp);
			vector<string> content;
			for (int j = 0; j < lineNum; j++)
			{
				getline(ifile, strTemp);
				content.push_back(strTemp);
				getline(ifile, strTemp);
			}
			CReadPinyin::content.push_back(content);
		}
	}
	else
	{
		cout << "载入数据出错！" << endl;
	}
	ifile.close();
}

vector<int> CReadPinyin::getNum()
{
	return num;
}

vector<string> CReadPinyin::getTitle()
{
	return title;
}

vector<string> CReadPinyin::getAuthor()
{
	return author;
}

vector<vector<string>> CReadPinyin::getContent()
{
	return content;
}
