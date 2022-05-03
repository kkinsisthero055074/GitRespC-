/*
	1. ��ά����
	2. ���ӻ����
		2.1 ��̬����
	3. �и��
		3.1 ʵ��ͼƬ���Զ��и�
	4. ������
		4.1 ����Ϸ������
	//�����¼
	//C����������ǹ��̣�C++������Ķ��󣬳�����ײ��Ӳ���⣬C++���Ժ�Cһ��ʵ��
*/

#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
//ȫ�ֱ���
IMAGE img, blank;
int array2D[4][4] = { 0 };
int array1D[16] = { 0 };


// 1. ���ƿ�ʼ�˵�
void drawMenu()
{
	initgraph(640, 450);
	setbkcolor(WHITE);//���ô�����ɫΪ��ɫ
	cleardevice();//ˢ����ʾ
	setfillcolor(LIGHTBLUE);//���������ɫΪ����ɫ
	settextstyle(30, 0, "�������з�");
	setbkmode(TRANSPARENT);//͸����ʽȥ�����ֵı���

	//������
	fillrectangle(240, 100, 380, 150);
	fillrectangle(240, 100 + 60, 380, 150 + 60);
	 
	//�������
	settextcolor(RED);
	outtextxy(240 + 20, 100 + 13, "��ʼ��Ϸ");
	outtextxy(240 + 20, 100 + 13 + 60, "�˳���Ϸ");
	outtextxy(240 + 20, 100 + 13 + 160, "����������");

	//�ֱ����
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		//�����λ�ھ���������
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
// 2. ������Դ
void loadResource()
{
	int i, j;
	srand((unsigned int)time(NULL));
	int length = 15 ;
	int pos = 0;

	//1. ��ʼ��һά����
	for (int i = 0; i < 16; i++)
	{
		array1D[i] = i;
	}

	//2.1 �������һά�����±�ֵ������ά����
	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			//�����������һ��λ��
			if (i==3&&j==3)
			{
				array2D[3][3] = 15;
				break;
			}

			pos = rand() % length;
			array2D[i][j] = array1D[pos];

			//���Ѿ���ֵ��ֵ��һά������ȥ��
			for (int k = pos; k < length; k++)
			{
				array1D[k] = array1D[k + 1];
			}
			length--;
		}
	}
	loadimage(&img, "1.jpg", 800, 800);
	loadimage(&blank, "blank.jpg", 200, 200);

}//��ʼ����Դ
//3. ��ͼ����
void drawMap()
{
	//���ݴ���˳��Ķ�ά�����ֵ����Ƭ��Ӧ��λ��
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
//4. ��Ϸ����
void playGame()
{
}





int main()
{
	drawMenu();
	//�˵�

	loadResource();
	//������Դ

	initgraph(800,800);
	drawMap();
	getchar();
	getchar();
	closegraph();

	
	return 0;
}
