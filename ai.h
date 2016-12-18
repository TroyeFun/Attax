#include<iostream>
using namespace std;

extern int tempboard[8][16][16];
extern int chess[3];
extern int ax1,ay1,ax2,ay2;
int value(int x1,int y1,int x2,int y2,int depth,int val,int player);
void xuanzi(int player);
void ai(int player);
