/*
	1. 二维数组
	2. 可视化编程
		2.1 动态制作
	3. 切割技术
		3.1 实现图片的自动切割
	4. 鼠标操作
		4.1 玩游戏的内容
	//问题记录
	//C语言面向的是过程，C++是面向的对象，除了最底层和硬件外，C++可以和C一样实现
*/

#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
//全局变量
IMAGE img, blank;
int array2D[4][4] = { 0 };
int array1D[16] = { 0 };


// 1. 绘制开始菜单
void drawMenu()
{
	initgraph(640, 450);
	setbkcolor(WHITE);//设置窗口颜色为白色
	cleardevice();//刷新显示
	setfillcolor(LIGHTBLUE);//设置填充颜色为淡蓝色
	settextstyle(30, 0, "汉仪王行繁");
	setbkmode(TRANSPARENT);//透明方式去掉文字的背景

	//画矩形
	fillrectangle(240, 100, 380, 150);
	fillrectangle(240, 100 + 60, 380, 150 + 60);
	 
	//文字输出
	settextcolor(RED);
	outtextxy(240 + 20, 100 + 13, "开始游戏");
	outtextxy(240 + 20, 100 + 13 + 60, "退出游戏");
	outtextxy(240 + 20, 100 + 13 + 160, "康红旗制作");

	//手表操作
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		//当鼠标位于矩形区域内
		if (m.x>=240 && m.x<380 &&m.y>=100 && m.y<=150)
		{
			setlinecolor(RED);
			rectangle(240 - 5, 100 - 5, 380 + 5, 150 + 5);
			if (m.uMsg==WM_LBUTTONDOWN)
			{
				break;
			}
		}
		else if (m.x >= 240 && m.x < 380 && m.y >= 160 && m.y <= 210)
		{
			setlinecolor(RED);
			rectangle(240 - 5, 160 - 5, 380 + 5, 210 + 5);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(240 - 5, 100 - 5, 380 + 5, 150 + 5);
			rectangle(240 - 5, 160 - 5, 380 + 5, 210 + 5);

		}

	}


	getchar();
	closegraph();

}
// 2. 加载资源
void loadResource()
{
	int i, j;
	srand((unsigned int)time(NULL));
	int length = 15 ;
	int pos = 0;

	//1. 初始化一维数组
	for (int i = 0; i < 16; i++)
	{
		array1D[i] = i;
	}

	//2.1 将随机的一维数组下标值赋给二维数组
	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			//单独处理最后一个位置
			if (i==3&&j==3)
			{
				array2D[3][3] = 15;
				break;
			}

			pos = rand() % length;
			array2D[i][j] = array1D[pos];

			//将已经赋值的值从一维数组中去掉
			for (int k = pos; k < length; k++)
			{
				array1D[k] = array1D[k + 1];
			}
			length--;
		}
	}
	loadimage(&img, "1.jpg", 800, 800);
	loadimage(&blank, "blank.jpg", 200, 200);

}//初始化资源
//3. 绘图过程
void drawMap()
{
	//根据打乱顺序的二维数组的值拿照片相应的位置
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			int x = j * 200;
			int y = i * 200;
			switch (array2D[i][j])
			{
			case 0:
			case 1:
			case 2:
			case 3:
				putimage(x, y, 200, 200, &img, array2D[i][j] * 200, 0);
				break;
			case 4:
			case 5:
			case 6:
			case 7:
				putimage(x, y, 200, 200, &img, (array2D[i][j]-4) * 200, 200);
				break;
			case 8:
			case 9:
			case 10:
			case 11:
				putimage(x, y, 200, 200, &img, (array2D[i][j] - 8) * 200, 400);
				break;
			case 12:
			case 13:
			case 14:
				break;
			case 15:
				putimage(x, y, 200, 200, &img, (array2D[i][j] - 12) * 200, 600);				
				break;
			}
		}
	}

}
//4. 游戏过程
void playGame()
{
}





int main()
{
	drawMenu();
	//菜单

	loadResource();
	//加载资源

	initgraph(800,800);
	drawMap();
	getchar();
	getchar();
	closegraph();

	
	return 0;
}
