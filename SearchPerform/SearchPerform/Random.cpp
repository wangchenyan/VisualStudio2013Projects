#include "stdafx.h"
#include "Random.h"
#include "time.h"

CRandom::CRandom()
{
}


CRandom::~CRandom()
{
}


vector<int> CRandom::CreateRandowNum()
{
	srand((int)time(0));
	vector<int> vet;
	for (int i = 0; i < 11; i++)
	{
		vet.push_back(rand() % 10);
	}
	return vet;
}