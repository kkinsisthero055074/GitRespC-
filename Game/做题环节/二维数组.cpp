/*
	1. 一维数组【16】初始化0-15
	2. 随机化一维数组的下标，将随机一维数组的下标值赋给二维数组
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int array1D[16] = { 0 };
	int array2D[4][4] = { 0 };
	int length = 16;
	int pos = 0;

	//1. 初始化一维数组
	for (int i=0;i<16;i++)
	{
		array1D[i] = i;
	}

	//2.1 将随机的一维数组下标值赋给二维数组
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			pos = rand() % length;
			array2D[i][j] = array1D[pos];

			//将已经赋值的值从一维数组中去掉
			for (int k=pos;k<length;k++)
			{
				array1D[k] = array1D[k + 1];
			}
			length--;
		}
	}

	//显示最终结果
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			printf("%d\t", array2D[i][j]);
		}
		printf("\n");
	}



	system("pause");
	return 0;
}
