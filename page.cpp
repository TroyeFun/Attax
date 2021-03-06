#include<iostream>
extern int turn;
using namespace std;
extern int sum1,sum2;
char chip[40][8]={"\0","◎","⊕","●","○","┠","┨","┷","┯","┃","│","━","─","┼","　","┓","┗","┛","┏","\0","\0","x ","y ","1 ","2 ","3 ","4 ","5 ","6 ","7 "};
//				   0	1	 2	  3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18    19    20   21   22   23   24   25   26   27   28   29   
/*
  x 1　 2　 3　 4　 5   6   7
y ┏━┯━┯━┯━┯━┯━┯━┓
1 ┃●│　│　│　│　│　│○┃　　　　　 (6space)　┏━━━━━━┓
　┠─┼─┼─┼─┼─┼─┼─┨                     ┃　 chess    ┃
2 ┃　│　│　│　│　│　│　┃                     ┃            ┃　　　　　　
　┠─┼─┼─┼─┼─┼─┼─┨                     ┃ ◆1P--●   ┃
3 ┃　│　│　│　│　│　│　┃                     ┃   2P--○   ┃
　┠─┼─┼─┼─┼─┼─┼─┨                     ┗━━━━━━┛
4 ┃　│　│　│　│　│　│　┃                     ┏━━━━━━┓
　┠─┼─┼─┼─┼─┼─┼─┨                     ┃   score    ┃
5 ┃　│　│　│　│　│　│　┃                     ┃            ┃
　┠─┼─┼─┼─┼─┼─┼─┨                     ┃   1P: 02   ┃
6 ┃　│　│　│　│　│　│　┃                     ┃   2P: 02   ┃
　┠─┼─┼─┼─┼─┼─┼─┨                     ┗━━━━━━┛
7 ┃○│　│　│　│　│　│●┃
  ┗━┷━┷━┷━┷━┷━┷━┛


*/
char fangkuai[3][6]={"\0","   "," ◆"};
int board[16][16]=
{{14,21,23,14,24,14,25,14,26,14,27,14,28,14,29},
{22,18,11,8,11,8,11,8,11,8,11,8,11,8,11,15},
{23,9,3,10,14,10,14,10,14,10,14,10,14,10,4,9},
{14,5,12,13,12,13,12,13,12,13,12,13,12,13,12,6,},
{24,9,14,10,14,10,14,10,14,10,14,10,14,10,14,9},
{14,5,12,13,12,13,12,13,12,13,12,13,12,13,12,6},
{25,9,14,10,14,10,14,10,14,10,14,10,14,10,14,9},
{14,5,12,13,12,13,12,13,12,13,12,13,12,13,12,6},
{26,9,14,10,14,10,14,10,14,10,14,10,14,10,14,9},
{14,5,12,13,12,13,12,13,12,13,12,13,12,13,12,6},
{27,9,14,10,14,10,14,10,14,10,14,10,14,10,14,9},
{14,5,12,13,12,13,12,13,12,13,12,13,12,13,12,6},
{28,9,14,10,14,10,14,10,14,10,14,10,14,10,14,9},
{14,5,12,13,12,13,12,13,12,13,12,13,12,13,12,6},
{29,9,4,10,14,10,14,10,14,10,14,10,14,10,3,9},
{14,16,11,7,11,7,11,7,11,7,11,7,11,7,11,17}};
void showboard()//打印棋盘
{
	system("cls");
	cout<<"  x 1　 2　 3　 4　 5   6   7"<<endl<<"y ┏━┯━┯━┯━┯━┯━┯━┓"<<endl;
	for(int i=2;i<15;i++)
	{
        cout<<chip[board[i][0]]<<chip[board[i][1]]<<chip[board[i][2]]<<chip[board[i][3]]<<chip[board[i][4]]<<chip[board[i][5]]<<chip[board[i][6]]<<chip[board[i][7]]<<chip[board[i][8]]<<chip[board[i][9]]
		<<chip[board[i][10]]<<chip[board[i][11]]<<chip[board[i][12]]<<chip[board[i][13]]<<chip[board[i][14]]<<chip[board[i][15]];
		switch(i)
		{
		case 2:cout<<"　　　　　　┏━━━━━━┓";break;
		case 3:cout<<"　　　　　　┃　 chess    ┃";break;
		case 4:cout<<"　　　　　　┃            ┃";break;
		case 5:cout<<"　　　　　　┃"<<fangkuai[3-turn]<<"1P--●   ┃";break;
		case 6:cout<<"　　　　　　┃"<<fangkuai[turn]<<"2P--○   ┃";break;
		case 7:cout<<"　　　　　　┗━━━━━━┛";break;
		case 8:cout<<"　　　　　　┏━━━━━━┓";break;
		case 9:cout<<"　　　　　　┃   score    ┃";break;
		case 10:cout<<"　　　　　　┃            ┃";break;
		case 11:cout<<"　　　　　　┃   1P: "<<sum1/10<<sum1%10<<"   ┃";break;
		case 12:cout<<"　　　　　　┃   2P: "<<sum2/10<<sum2%10<<"   ┃";break;
		case 13:cout<<"　　　　　　┗━━━━━━┛";break;
		}
		cout<<endl;
	
	}
	cout<<"  ┗━┷━┷━┷━┷━┷━┷━┛"<<endl;
	

}
void showmenu()//打印菜单
{
	system("mode con cols=38 lines=20");//设置窗口大小
	system("cls");
	cout<<"         __________________"<<endl;
	cout<<"        |  欢迎来玩同化棋  |"<<endl;
	cout<<"        |  1.新开局        |"<<endl;
	cout<<"        |  2.游戏规则      |"<<endl;
	cout<<"        |  3.复盘          |"<<endl;
	cout<<"        |  4.退出          |"<<endl;
	cout<<"         ------------------"<<endl;
}

void showrule()
{
	system("mode con cols=63 lines=40");
	cout<<"            --------------------------------------"<<endl;
	cout<<"           |             游戏规则　　　　　　　　 |"<<endl;
	cout<<"           | 1.初始布置为双方各将两枚棋子放在最外 |"<<endl;
	cout<<"           |   的对角格。                         |"<<endl;
	cout<<"           | 2.玩家必须轮流移动一枚己子到一个空棋 |"<<endl;
	cout<<"           |   位，该棋位可以是邻近八格（包括对角 |"<<endl;
	cout<<"           |   相邻的格）之一，或相隔一格的次邻十 |"<<endl;
	cout<<"           |   二格之一。移动的新棋位，会使邻近的 |"<<endl;
	cout<<"           |   所有敌棋如黑白棋一样变成己方。如果 |"<<endl;
	cout<<"           |   棋子移到的是邻接八格，会有一颗新己 |"<<endl;
	cout<<"           |   棋出现在原先棋位。                 |"<<endl;
	cout<<"           | 3.无法行棋需弃权。当两方都无法行棋时,|"<<endl;
	cout<<"           |   游戏结束。以最多子者胜。           |"<<endl;
	cout<<"            --------------------------------------"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"            ______________________________________"<<endl;
	cout<<"           |             游戏操作                 |"<<endl;
	cout<<"           | 1.选子和落子时即可以使用光标, 也可以 |"<<endl;
	cout<<"           |   输入坐标（x，y）.使用光标时,w,s,a, |"<<endl;
	cout<<"           |　 d分别为上下左右,键入空格时选定棋子.|"<<endl;
	cout<<"           |   使用坐标时，应连续输入两个数字. 若 |"<<endl;
	cout<<"           |   输入一个数字后键入其他符号，将重新 |"<<endl; 
	cout<<"           |   进行选子.                          |"<<endl;
	cout<<"           | 2.游戏中若需要进行存盘，请在选子前输 |"<<endl;
	cout<<"           |   入r，选子后落子前输入r无效.        |"<<endl;
	cout<<"           | 3.游戏过程中，输入t可退出游戏.       |"<<endl;
	cout<<"            --------------------------------------"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"           按任意键返回";
}
  
