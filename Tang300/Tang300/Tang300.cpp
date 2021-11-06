// Tang300.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Login.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CLogin * p_Login = new CLogin();
	p_Login->login();
	return 0;
}

