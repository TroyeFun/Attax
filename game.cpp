#include"cursor.h"
#include<iostream>
#include"page.h"
#include"player.hpp"
#include"conio.h"
#include"functions.h"
#include"ai.h"
using namespace std;
int turn=1;//下棋顺序
bool quit=0;
int main()
{
	system("title 方鸿宇的简易同化棋 ");//设置标题
	system("color E0");//设置颜色
	while(1)
	{
		showmenu();
		weizhix=11;weizhiy=2;
		gotoxy(weizhix,weizhiy);
		int menu=0;
		bool cont=0;//continue,记录是否是复盘
		for(;;){
			char press;
			press=getch();
			if(press=='w'||press=='s'){
				move_on_menu(press);
				gotoxy(weizhix,weizhiy);
			}
			else if(press==' '){
				switch(weizhiy)
				{
				case 2:menu=1;break;
				case 3:menu=2;break;
				case 4:menu=3;break;
				case 5:menu=4;break;
				}
				break;
			}
			else if(press=='1'){
				menu=1;
				break;
			}
			else if(press=='2'){
				menu=2;
				break;
			}
			else if(press=='3'){
				menu=3;
				break;
			}
			else if(press=='4'){
				menu=4;
				break;
			}
		}
		if(menu==4)break;
		else if(menu==2){
			showrule();
			getch();
		}
		else if(menu==3){
			load();
			menu=1;
			cont=1;
		}
		if(menu==1)
		{
			system("mode con cols=63 lines=24");//设置窗口大小
			if(cont==0)mode();//选择模式
		   if(MODE==3)//mode3为人对人
		    {
				weizhix=4;
				weizhiy=2;//光标在棋盘上的的初始位置
				showboard();
				gotoxy(weizhix,weizhiy);       
				for( ; ; )
			    {
					if(turn ==1)
					{
					    player1();
						if(quit==1){restore();break;}
						if(end(2)==1)//如果2P无子可下，对局结束。剩下旗子归1P。
						{
							if(49-sum2>sum2)cout<<"            Winner: 1P."<<endl;
							else cout<<"            Winner: 2P."<<endl;
							restore();
							cout<<endl<<"按 g 键退出"<<endl;
							char t;
							bool tiaochu=0;
							for(;;)
							{
								if((t=getch())=='g')
								{
									tiaochu=1;
									break;
								}
							}
							if(tiaochu==1)break;
						}
						
					}
					else
					{
					    player2();
						if(quit==1){restore();break;}
						if(end(1)==1)//如果1P无子可下，对局结束
						{
							if(sum1>49-sum1)cout<<"            Winner: 1P."<<endl;
							else cout<<"            Winner: 2P."<<endl;
							restore();
							cout<<endl<<"按 g 键退出"<<endl;
							char t;
							bool tiaochu=0;
							for(;;)
							{
								if((t=getch())=='g')
								{
									tiaochu=1;
									break;
								}
							}
							if(tiaochu==1)break;
						}
						
				    }
					
				 }
			}
		   else if(MODE==1)//计算机对人
		   {
			   weizhix=4;
				weizhiy=2;//光标在棋盘上的的初始位置
				showboard();
				gotoxy(weizhix,weizhiy);
				for(;;)
				{
					if(turn==1)
					{
						ai(1);
						if(end(2)==1)//如果2P无子可下，对局结束.剩余旗子归1P。
						{
							
							if(49-sum2>sum2)cout<<"         Winner: Computer."<<endl;
							else cout<<"          Winner: Human."<<endl;
							restore();
							cout<<endl<<"按 g 键退出"<<endl;
							char t;
							bool tiaochu=0;
							for(;;)
							{
								if((t=getch())=='g')
								{
									tiaochu=1;
									break;
								}
							}
							if(tiaochu==1)break;
						}
						
						
					}
					else
					{
					    player2();
						if(quit==1){restore();break;}
						if(end(1)==1)//如果ai无子可下，对局结束
						{
							
							if(sum1>49-sum1)cout<<"         Winner: Computer."<<endl;
							else cout<<"          Winner: Human."<<endl;
							restore();
							cout<<endl<<"按 g 键退出"<<endl;
							char t;
							bool tiaochu=0;
							for(;;)
							{
								if((t=getch())=='g')
								{
									tiaochu=1;
									break;
								}
							}
							if(tiaochu==1)break;
						}
						
						
				    }
				}

		   }
		   else if(MODE==2)//人对计算机
		   {
			   weizhix=4;
				weizhiy=2;//光标在棋盘上的的初始位置
				showboard();
				gotoxy(weizhix,weizhiy);
				for(;;)
				{
					if(turn==2)
					{
						ai(2);
						if(end(1)==1)//如果1P无子可下，对局结束
						{
							
							if(sum1>49-sum1)cout<<"          Winner: Human."<<endl;
							else cout<<"         Winner: Computer."<<endl;
							restore();
							cout<<endl<<"按 g 键退出"<<endl;
							char t;
							bool tiaochu=0;
							for(;;)
							{
								if((t=getch())=='g')
								{
									tiaochu=1;
									break;
								}
							}
							if(tiaochu==1)break;
						}
						
						
					}
					else
					{
					    player1();
						if(quit==1){restore();break;}
						if(end(2)==1)//如果ai无子可下，对局结束.所有空归1P所有
						{
							
							if(49-sum2>sum2)cout<<"          Winner: Human."<<endl;
							else cout<<"         Winner: Computer."<<endl;
							restore();
							cout<<endl<<"按 g 键退出"<<endl;
							char t;
							bool tiaochu=0;
							for(;;)
							{
								if((t=getch())=='g')
								{
									tiaochu=1;
									break;
								}
							}
							if(tiaochu==1)break;
							
						}
						
				    }
				}
				

		   }
		}
	}
	system("cls");
	system("mode con cols=38 lines=20");
	cout<<"            谢谢您的使用!"<<endl;
	cout<<"                再见!"<<endl;
	for(int i=0;i<1000000;i++)
		for(int j=0;j<1000;j++);//进行延迟
    
}
