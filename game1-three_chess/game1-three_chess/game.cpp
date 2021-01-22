#define _CRT_SECURE_NO_WARNINGS 1
//��Ϸģ��
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include"game.h"

void InitBoard(char board[ROW][COL],int row,int col)//��ά���鲻���Ǵ���������Ϊ��������������ʡ���еĴ�С
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;

	for (i = 0; i < row; i++)
	{
		//1.��ӡһ�е�����
		int j = 0;
		for (j = 0; j < col; j++) 
		{
			if(j!=col-1)
			{
				printf(" %c |", board[i][j]);
			}
			else
			{
				printf(" %c \n", board[i][j]);
			}
		}
		//2.��ӡ�ָ���
		if (i < row - 1)
		{
			int k = 0;
			for (k = 0; k < row; k++)
			{
				if (k != row - 1)
				{
					printf("---|");
				}
				else
				{
					printf("---\n");
				}
			}
		}	
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);
		//�ж�x,y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= row)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}	
			else
				printf("�����걻ռ��!\n");
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	while (1)
	{
		x = rand() % row;//����x��ֵ��ֻ����0��1��2���ڷ�Χ��
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�к��е��ж�
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�����Խ��ߵ��ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//ƽ�ֵ��ж�
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//û��
			}
		}
	}
	return 1;//����
}