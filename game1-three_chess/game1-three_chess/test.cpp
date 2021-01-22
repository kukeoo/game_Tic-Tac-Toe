#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"game.h"
//测试三子棋游戏

using namespace std;

void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};//最开始初始化最好是字符空格。
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		//玩家下完棋后展示新棋盘
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		//电脑下完棋后展示新棋盘
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜你，你赢了！\n");
	}
	else if (ret == '#')
	{
		printf("很遗憾，电脑赢了。\n");
	}
	else
	{
		printf("你和电脑打成了平局。\n");
	}
}


void menu()
{
	cout << "1.开始 0.退出\n";
}

void test()
{
	int input;
	srand((unsigned int)time(NULL));
	printf("游戏名：三子棋\n");
	printf("游戏规则：在九宫格的九个交点处落子，由玩家和电脑交替下棋，某一方的三个棋子走成了一条线，则该方胜利。\n");
	printf("输入格式：假如你想在第二行第一列放入你的棋子，则输入：2 1，其中2和1用空格隔开。输入完成后回车即可。\n");
	printf("代号说明：玩家端的棋子为：*；电脑端棋子为：#\n");
	do
	{
		menu();
		printf("请选择: > ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			cout << "三子棋"<<endl;
			printf("游戏开始：\n");
			game();
			break;
		case 0:
			printf("退出成功。\n");
			break;
		default:
			printf("选择有误!请重新输入0或1。\n");
			break;

		}
	} while (input);//选择非0，1是继续游戏，其他的数是重新选择，都满足真的条件。
}


int main()
{
	test();
	return 0;
}