/*
	1. һά���顾16����ʼ��0-15
	2. �����һά������±꣬�����һά������±�ֵ������ά����
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

	//1. ��ʼ��һά����
	for (int i=0;i<16;i++)
	{
		array1D[i] = i;
	}

	//2.1 �������һά�����±�ֵ������ά����
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			pos = rand() % length;
			array2D[i][j] = array1D[pos];

			//���Ѿ���ֵ��ֵ��һά������ȥ��
			for (int k=pos;k<length;k++)
			{
				array1D[k] = array1D[k + 1];
			}
			length--;
		}
	}

	//��ʾ���ս��
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
