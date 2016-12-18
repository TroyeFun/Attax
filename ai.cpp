#include<iostream>
#include<cstring>
#include"page.h"
#include"player.hpp"
extern int turn;
using namespace std;

int tempboard[8][16][16]={0};
int chess[3]={0,3,4};
int ax1,ay1,ax2,ay2;
int value(int x1,int y1,int x2,int y2,int depth,int val,int player)//估值
{
	val++;
	if(abs(x2-x1)==2||abs(y2-y1)==2)
	{
		val--;
	}
	for(int i=x2-1;i<=x2+1;i++)
	{
		for(int j=y2-1;j<=y2+1;j++)
		{
			if(tempboard[depth-1][2*j][2*i]==chess[3-player])
			{
				val+=2;
			}
		}
	}	
	return val;
}
void xuanzi(int player)
{
	int max=0;
	int val=0;
	memcpy(tempboard[0],board,sizeof(board));
	for(int x1=1;x1<=7;x1++)
		for(int y1=1;y1<=7;y1++)
		{
			if(tempboard[0][2*y1][2*x1]==chess[player])
			{
				for(int x2=x1-2;x2<=x1+2;x2++)
					for(int y2=y1-2;y2<=y1+2;y2++)
					{
						if(tempboard[0][2*y2][2*x2]==14&&y2>=1&&y2<=7&&x2<=7&&x2>=1)
						{
							int temp=value(x1,y1,x2,y2,1,val,player);
							if(temp>=max)
							{
								ax1=x1;ay1=y1;ax2=x2;ay2=y2;max=temp;
							}
						}

					}

			}

		}
}
void luozi(int x1,int y1,int x2,int y2,int player)
{
	if(player==1)board[2*y1][2*x1]=2;
	else board[2*y1][2*x1]=1;
	showboard();
	if(player==1)board[2*y1][2*x1]=3;
	else board[2*y1][2*x1]=4;
	for(int i=0;i<100000;i++)
		for(int j=0;j<1000;j++);
	board[2*y2][2*x2]=chess[player];
    if(player==2)sum2++;
	else sum1++;
    if(abs(x2-x1)==2||abs(y2-y1)==2)
    {
        board[2*y1][2*x1]=14;
        if(player==2)sum2--;
		else sum1--;
    }
    for(int i=y2-1;i<=y2+1;i++)
    {
	  for(int j=x2-1;j<=x2+1;j++)
	  {
		  if(board[2*i][2*j]==chess[3-player])
         {
		    board[2*i][2*j]=chess[player];
			if(player==2){sum2++;sum1--;}
			else {sum1++;sum2--;}
		 }
	   }
    }
	turn=3-turn;
	showboard();
}
void ai(int player)
{
	xuanzi(player);
	luozi(ax1,ay1,ax2,ay2,player);
}
