#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"game.h"
//������������Ϸ

using namespace std;

void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};//�ʼ��ʼ��������ַ��ո�
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		//����������չʾ������
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		//�����������չʾ������
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("���ź�������Ӯ�ˡ�\n");
	}
	else
	{
		printf("��͵��Դ����ƽ�֡�\n");
	}
}


void menu()
{
	cout << "1.��ʼ 0.�˳�\n";
}

void test()
{
	int input;
	srand((unsigned int)time(NULL));
	printf("��Ϸ����������\n");
	printf("��Ϸ�����ھŹ���ľŸ����㴦���ӣ�����Һ͵��Խ������壬ĳһ�������������߳���һ���ߣ���÷�ʤ����\n");
	printf("�����ʽ�����������ڵڶ��е�һ�з���������ӣ������룺2 1������2��1�ÿո������������ɺ�س����ɡ�\n");
	printf("����˵������Ҷ˵�����Ϊ��*�����Զ�����Ϊ��#\n");
	do
	{
		menu();
		printf("��ѡ��: > ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			cout << "������"<<endl;
			printf("��Ϸ��ʼ��\n");
			game();
			break;
		case 0:
			printf("�˳��ɹ���\n");
			break;
		default:
			printf("ѡ������!����������0��1��\n");
			break;

		}
	} while (input);//ѡ���0��1�Ǽ�����Ϸ����������������ѡ�񣬶��������������
}


int main()
{
	test();
	return 0;
}