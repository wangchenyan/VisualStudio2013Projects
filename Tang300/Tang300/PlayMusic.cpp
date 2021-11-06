#include "stdafx.h"
#include "PlayMusic.h"
#include "iostream"
using namespace std;
#include "windows.h"
#pragma comment(lib,"Winmm.lib")


CPlayMusic::CPlayMusic()
{
}


CPlayMusic::~CPlayMusic()
{
}

//≤•∑≈±≥æ∞“Ù¿÷
void CPlayMusic::playMusic()
{
	string music = "mhsn.mp3";
	mciSendString("open mhsn.mp3", NULL, 0, NULL);
	mciSendString("play mhsn.mp3 repeat", NULL, 0, NULL);
}
