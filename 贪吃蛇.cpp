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

	//�����������
	for (int i = 0; i < 21; i++)
	{
		line(i * SQUARE, 0, i * SQUARE, 800);
	}
	for (int i = 0; i < 16; i++)
	{
		line(0,i * SQUARE,800,  i * SQUARE);
	}
	//��ʼ��̰���ߵ�λ��(�����������Ͻǵ�����������λ��)

}
void drawSnake(Location* array[])	//ע�⣺����Ҫ��[]
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

	//������Ч�ٸ�dir��ֵ��������ԭֵ
	if (temp == 'p'|| temp == 'w' || temp == 's'|| 
		temp == 'a' || temp == 'd')
	{	
		dir = temp;

		//��ͣ��ظ�
		if (dir == 'p')
		{
			while (true)
			{
				dir = getDirection();
				if (dir == 'y')
				{
					dir = lastDir;		//�ָ��˶������dirԭֵ
					break;
				}
			}
		}

		//����Ƿ�Ҫ�ƶ��������ͻ����ԭֵ
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