#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
char x[10][20];
int H[20];
int Z[20];
int h, v;//分别代表横纵坐标
char ch = 'd';
int len = 3;
char f;
void getFood()//食物
{
	h = rand() % 10;
	v = rand() % 20;
	if (x[h][v] == 1)
	{
		getFood();
	}
	else
		x[h][v] = 3;//心形ASCII码为3
}
