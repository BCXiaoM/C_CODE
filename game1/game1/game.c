#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
//构建棋盘格式
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");

	}
}
//玩家玩
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走>\n");
	while (1)
	{
		printf("输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("非法坐标，重新输入\n");
			}
		}
		else
		{
			printf("非法坐标，重新输入\n");
		}
	}
}
//电脑玩
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		} 
	}

}
//判断状态局势
int IsWin(char board[ROW][COL], int row, int col)
{
	//判断三行是否相等

	int i = 0;
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}

	//判断三列是否相等

	for (i = 0;i < col;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}

	//判断对角线

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	//判断平局

	int rat = IsFull(board, row, col);
	if (rat == 1)
	{
		return 'Q';
	}
	return 'C';
}
//实现判断
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}