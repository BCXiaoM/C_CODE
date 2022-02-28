#define _CRT_SECURE_NO_WARNINGS 1
//三子棋
#include "game.h"
void game()
{
	//储存数据-二维数组
	char board[ROW][COL];
	//初始化棋盘-空格
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢了\n");
	else if (ret == '#')
		printf("电脑赢了\n");
	else
		printf("平局\n");
}

void menu()
{
	printf("**********************************\n");
	printf("********     1.play      *********\n");
	printf("********     0.exit      *********\n");
	printf("**********************************\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择");
			break;
		}
	} while (input);
	return 0;
}