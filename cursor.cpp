#include<iostream>
#include<Windows.h>
#include"conio.h"
using namespace std;
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c); //修改当前光标的位置
}
int weizhix,weizhiy;//表示在整个窗口中的坐标
void move_on_board(char c)//w、s、a、d分别为上下左右
{
	switch(c)
	{
	case 'w':if(weizhiy==2)weizhiy=14;else weizhiy-=2;break;//棋盘上两行之间的间隔为2个单位
	case 'a':if(weizhix==4)weizhix=28;else weizhix-=4;break;//棋盘上两列之间的间隔为4个单位
	case 's':if(weizhiy==14)weizhiy=2;else weizhiy+=2;break;
	case 'd':if(weizhix==28)weizhix=4;else weizhix+=4;break;
	}
}
void move_on_menu(char c)
{
	switch(c)
	{
	case 'w':if(weizhiy==2)weizhiy=5;else weizhiy-=1;break;
	case 's':if(weizhiy==5)weizhiy=2;else weizhiy+=1;break;
	}
}
void move_on_mode(char c)
{
	switch(c)
	{
	case 'w':if(weizhiy==1)weizhiy=3;else weizhiy-=1;break;
	case 's':if(weizhiy==3)weizhiy=1;else weizhiy+=1;break;
	}
}
