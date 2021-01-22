#pragma once
//游戏模块头文件
#define ROW 3
#define COL 3

//声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
//告诉我们四种游戏状态：
//1、玩家赢 - '*'
//2、电脑赢 - '#'
//3、平局   - 'Q'
//4、继续   - 'C'

int IsFull(char board[ROW][COL], int row, int col);
//返回1：表示棋盘满了
//返回0：表示棋盘没满