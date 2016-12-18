#include<iostream>
#include<fstream>
#include"page.h"
#include"player.hpp"
using namespace std;

extern int turn ;
extern bool quit;

void save()
{
	ofstream fout;
	fout.open("save.txt");
	fout<<turn<<endl;
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
			fout<<board[i][j]<<' ';
		fout<<endl;
	}
	fout<<sum1<<" "<<sum2<<" "<<MODE<<endl;
	fout.close();

}
void load()//复盘
{
	ifstream fin;
	fin.open("save.txt");
	fin>>turn;//第一个下棋的玩家
	fin.get();//吃掉换行符
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
			fin>>board[i][j];
	}
	fin>>sum1>>sum2>>MODE;
	fin.close();
}
void restore()//游戏结束后恢复棋盘
{
	chip[36][0]='0';
	chip[36][1]='2';
	chip[37][0]='0';
	chip[37][1]='2';
	quit=0;
	turn=1;
	for(int x=1;x<=7;x++)
	{
		for(int y=1;y<=7;y++)
		{
			board[2*y][2*x]=14;
		}
		board[2][2]=3;
		board[14][14]=3;
		board[14][2]=4;
		board[2][14]=4;
	}
	sum1=2;
	sum2=2;
}
