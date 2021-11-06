#include "stdafx.h"
#include "ReadHanyu.h"
#include "fstream"
#include "iostream"
using namespace std;


CReadHanyu::CReadHanyu()
{
	readData();
}


CReadHanyu::~CReadHanyu()
{
}

//读取数据
void CReadHanyu::readData()
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
			CReadHanyu::num.push_back(num);
			getline(ifile, strTemp);
			getline(ifile, strTemp);
			getline(ifile, strTemp);
			title.push_back(strTemp);
			getline(ifile, strTemp);
			getline(ifile, strTemp);
			author.push_back(strTemp);
			vector<string> content;
			for (int j = 0; j < lineNum; j++)
			{
				getline(ifile, strTemp);
				getline(ifile, strTemp);
				content.push_back(strTemp);
			}
			CReadHanyu::content.push_back(content);
		}
	}
	else
	{
		cout << "载入数据出错！" << endl;
	}
	ifile.close();
}

vector<int> CReadHanyu::getNum()
{
	return num;
}

vector<string> CReadHanyu::getTitle()
{
	return title;
}

vector<string> CReadHanyu::getAuthor()
{
	return author;
}

vector<vector<string>> CReadHanyu::getContent()
{
	return content;
}
