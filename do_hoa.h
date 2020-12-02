#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
#include<iostream>
#include<vector>
using namespace std;
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(SHORT x, SHORT y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(int mau_sac) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, mau_sac);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey(){
	while (!_kbhit()) {
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}
		return key;
	}
	return -1;
}
int inputkey() {
	if (_kbhit()) {
		int key = _getch();
		if (key == 224) {
			key = _getch();
			return key + 1000;
		}
		return key;
	}
	else {
		return KEY_NONE;
	}
	return KEY_NONE;
}

//chinh kich thuoc Console
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//=============== in khoảng trắng ===============
string in_khoang_trang(int x) {
	string abc = "";
	for (int i = 0; i < x; i++) abc += " ";
	return abc;
}