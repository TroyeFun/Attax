#include "player.hpp"
#include"conio.h"
#include "page.h"
#include<iostream>
#include"cursor.h"
#include<fstream>
#include"functions.h"
using namespace std;
extern int turn ;
extern bool quit;
void delay()//用于延迟
{
    for(int i=0;i<1000*1000;i++)
		for(int j=0;j<700;j++);
}

int MODE=0;
void mode()//选择模式
{
	system("cls");
	cout<<"Please input '1' , '2', '3' or move the cursor to choose mode:"<<endl;
    cout<<"1: 1P--Computer    2P--Human."<<endl;
    cout<<"2: 1P--Human       2P--Computer."<<endl;
    cout<<"3: 1P--Human       2P--Human."<<endl;
	weizhix=0;weizhiy=1;
	gotoxy(weizhix,weizhiy);
	for(;;)
	{
		char p;
		p=getch();
		if(p=='w'||p=='s')
		{
			move_on_mode(p);
			gotoxy(weizhix,weizhiy);
		}
		else if(p==' ')
		{
			MODE=weizhiy;
			break;
		}
		else if(p=='1'||p=='2'||p=='3'){MODE=p-'0';break;} 
	}
}

int sum1=2,sum2=2;//双方棋子初始数量均为2
void player1()//1P落子
{
	
	gotoxy(weizhix,weizhiy);//打印棋盘、输出提示语后，把光标移动到原来的位置
    int x1,y1,x2,y2;//分别为选择的棋子和空位在棋盘上的坐标
	char c;
    for(;;)
	{
		c=getch();
		if(c=='w'||c=='s'||c=='a'||c=='d')//如果输入为方向，则移动光标
		{
			move_on_board(c);
			gotoxy(weizhix,weizhiy);
		}
		else if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7')//如果输入为坐标，确定x1和y1的值
		{
			x1=c-'0';
			y1=getch()-'0';
			break;
		}
		else if(c==' ')//空格为选子或落子
		{
			x1=(weizhix+2)/4;
			y1=(weizhiy+1)/2;//棋盘上坐标与窗口上的坐标的换算关系
			break;
		}
		else if(c=='r')//r为存盘
		{
			save();
		}
		else if(c=='t')//t为退出
		{
			quit=1;
			return ;
		}
		
	}
        if(board[2*y1][2*x1]==3)
        {
            board[2*y1][2*x1]=2;//显示选择的棋子
            
            showboard();
            gotoxy(weizhix,weizhiy);
            board[2*y1][2*x1]=3;//把棋子恢复为原来大小
			char c;
    for(;;)
	{
		c=getch();
		if(c=='w'||c=='s'||c=='a'||c=='d')
		{
			move_on_board(c);
			gotoxy(weizhix,weizhiy);
		}
		else if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7')
		{
			x2=c-'0';
			y2=getch()-'0';
			break;
		}
		else if(c==' ')
		{
			x2=(weizhix+2)/4;
			y2=(weizhiy+1)/2;
			break;
		}
		else if(c=='t')
		{
			quit=1;
			return ;
		}
	}
            if(board[2*y2][2*x2]==14&&(abs(x2-x1)<=2&&abs(y2-y1)<=2)&&(x2-x1!=0||y2-y1!=0))
            {
                
                board[2*y2][2*x2]=3;//落子
                sum1++;
                if(abs(x2-x1)==2||abs(y2-y1)==2)//如果落子位置离选择的棋子距离为2格，抹掉原来的棋子
                {
                    board[2*y1][2*x1]=14;
                    sum1--;
                }
                for(int i=y2-1;i<=y2+1;i++)//同化
                {
                    for(int j=x2-1;j<=x2+1;j++)
                    {
                        if(board[2*i][2*j]==4)
                        {
                            board[2*i][2*j]=3;
                            sum1++;
                            sum2--;
                        }
                    }
                }
				turn=3-turn;
                showboard();
            }
            else
            {
                showboard();
                player1();
            }

        }
        else
        {
			showboard();
            player1();
        }
            
    
}
void player2()
{
	
	gotoxy(weizhix,weizhiy);
    int x1,y1,x2,y2;
	char c;
	for(;;)
	{
	    c=getch();
		if(c=='w'||c=='s'||c=='a'||c=='d')
		{
			move_on_board(c);
			gotoxy(weizhix,weizhiy);
		}
		else if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7')
		{
			x1=c-'0';
			y1=getch()-'0';
			break;
		}
		else if(c==' ')
		{
			x1=(weizhix+2)/4;
			y1=(weizhiy+1)/2;
			break;
		}
		else if(c=='r')
		{
			save();
		}
		else if(c=='t')
		{
			quit=1;
			return ;
		}
	}
	if(board[2*y1][2*x1]==4)
    {
		board[2*y1][2*x1]=1;
        showboard();
		gotoxy(weizhix,weizhiy);
        board[2*y1][2*x1]=4;

		for(;;)
		{
			c=getch();
			if(c=='w'||c=='s'||c=='a'||c=='d')
			{
				move_on_board(c);
				gotoxy(weizhix,weizhiy);
			}
			else if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7')
			{
				x2=c-'0';
				y2=getch()-'0';
				break;
			}
			else if(c==' ')
			{
				x2=(weizhix+2)/4;
				y2=(weizhiy+1)/2;
				break;
			}
			else if(c=='t')
			{
				quit=1;
				return;
			}
		}

            if(board[2*y2][2*x2]==14&&(abs(x2-x1)<=2&&abs(y2-y1)<=2)&&(x2-x1!=0||y2-y1!=0))
            {
                
                board[2*y2][2*x2]=4;
                sum2++;
                if(abs(x2-x1)==2||abs(y2-y1)==2)
                {
                    board[2*y1][2*x1]=14;
                    sum2--;
                }
                for(int i=y2-1;i<=y2+1;i++)
                {
                    for(int j=x2-1;j<=x2+1;j++)
                    {
                        if(board[2*i][2*j]==3)
                        {
                            board[2*i][2*j]=4;
                            sum2++;
                            sum1--;
                        }
                    }
                }
				turn=3-turn;
                showboard();
            }
            else
            {
                showboard();
                player2();
            }
            
        }
        else
        {
			showboard();
            player2();
        }
	
	
    
}
bool end(int player)//判断是否游戏是否结束,player为下一个落子的人
{
	if(player==1)
	{
		for(int i=1;i<=7;i++)
		{
			for(int j=1;j<=7;j++)
			{
				if(board[2*i][2*j]==3)
				{
					for(int i1=i-2;i1<=i+2;i1++)
					{
						for(int j1=j-2;j1<=j+2;j1++)
						{
							if(i1<=7&&i1>=1&&j1<=7&&j1>=0&&(i1!=i||j1!=j))
							{
								if(board[2*i1][2*j1]==14) return 0;//如果1P有子可下，返回0
							}
						}
					}
				}
			}
		}
		return 1;//如果无子可下，返回1，对局结束
	}
	if(player==2)
	{
		for(int i=1;i<=7;i++)
		{
			for(int j=1;j<=7;j++)
			{
				if(board[2*i][2*j]==4)
				{
					for(int i1=i-2;i1<=i+2;i1++)
					{
						for(int j1=j-2;j1<=j+2;j1++)
						{
							if(i1<=7&&i1>=1&&j1<=7&&j1>=0&&(i1!=i||j1!=j))
							{
								if(board[2*i1][2*j1]==14) return 0;
							}
						}
					}
				}
			}
		}
		return 1;
	}
}

