#pragma once
//��Ϸģ��ͷ�ļ�
#define ROW 3
#define COL 3

//����
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
//��������������Ϸ״̬��
//1�����Ӯ - '*'
//2������Ӯ - '#'
//3��ƽ��   - 'Q'
//4������   - 'C'

int IsFull(char board[ROW][COL], int row, int col);
//����1����ʾ��������
//����0����ʾ����û��