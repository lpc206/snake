#include <iostream>
#include <easyx.h>
#include <stdio.h>
#include <conio.h>
#include "location.h"
#define SQUARE 40

char g_dir;
using namespace std;

void pageInit()
{
	initgraph(800, 600,1);
	setbkcolor(HSVtoRGB(164, 154, 255));
	cleardevice();
	setlinecolor(0xffffff);

	//绘制网络格子
	for (int i = 0; i < 21; i++)
	{
		line(i * SQUARE, 0, i * SQUARE, 800);
	}
	for (int i = 0; i < 16; i++)
	{
		line(0,i * SQUARE,800,  i * SQUARE);
	}
	//初始化贪吃蛇的位置(以正方形左上角的坐标代替矩形位置)

}
void drawSnake(Location* array[])	//注意：数组要加[]
{
	setlinecolor(0xffffff);
	for (int i = 0; i < Location::len; i++)
	{
		solidrectangle(array[i]->m_x, array[i]->m_y, 40 + array[i]->m_x, 40 + array[i]->m_y);
	}
}

char getDirection()
{
	char c = 'd';
	if (_kbhit != 0)
	{
		c = _getch();
	}
	return c;
}

void snakeMove(Location* array[], int len, char lastDir)
{
	setlinecolor(0xffffff);
	char dir = lastDir;
	char temp = getDirection();
	cout << temp << "+++++ ";

	//输入有效再给dir赋值，否则保留原值
	if (temp == 'p'|| temp == 'w' || temp == 's'|| 
		temp == 'a' || temp == 'd')
	{	
		dir = temp;

		//暂停与回复
		if (dir == 'p')
		{
			while (true)
			{
				dir = getDirection();
				if (dir == 'y')
				{
					dir = lastDir;		//恢复运动后给予dir原值
					break;
				}
			}
		}

		//检测是否要移动，如果冲突保留原值
		//dir = getDirection();
	}
	cout << dir << endl;
	delete array[len - 1];
	for (int i = len - 1; i > 0; i--)
	{
		array[i] = array[i - 1];
	}
	switch (dir)
	{
	case 'w':array[0] = new Location (array[0]->m_x,(array[0]->m_y)++); Sleep(100); break;
	case 's':array[0] = new Location(array[0]->m_x, (array[0]->m_y)--); Sleep(100); break;
	case 'a':array[0] = new Location((array[0]->m_x)--, array[0]->m_y); Sleep(100); break;
	case 'd':array[0] = new Location((array[0]->m_x)++, array[0]->m_y); Sleep(100); break;
	default: break;
	}
	g_dir = dir;
}

int main()
{
	pageInit();
	while (1)
	{
		//cout << "dfs" << endl;
		snakeMove(Location::array, Location::len, g_dir);
		//cout << "dd" << endl;
		drawSnake(Location::array);

	}
	return 0;
}