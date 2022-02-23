#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//实现一个加减乘除的程序
//void mune()
//{
//	printf("*************************\n");
//	printf("*****  1.Add 2.Sub  *****\n");
//	printf("*****  3.Che 4.Chu  *****\n");
//	printf("*****     5.exit    *****\n");
//	printf("*************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Che(int x, int y)
//{
//	return x * y;
//}
//int Chu(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int ret = 0;
//	int input = 0;
//	do
//	{
//		int x = 0;
//		int y = 0;
//		mune();
//		printf("请选择>:");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			printf("\n请输入两个数>:");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("\n请输入两个数>:");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("\n请输入两个数>:");
//			scanf("%d %d", &x, &y);
//			ret = Che(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("\n请输入两个数>:");
//			scanf("%d %d", &x, &y);
//			ret = Chu(x, y);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选！\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//用函数指针数组实现
//void mune()
//{
//	printf("*************************\n");
//	printf("*****  1.Add 2.Sub  *****\n");
//	printf("*****  3.Che 4.Chu  *****\n");
//	printf("*****     5.exit    *****\n");
//	printf("*************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Che(int x, int y)
//{
//	return x * y;
//}
//int Chu(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int ret = 0;
//	int input = 0;
//	do
//	{
//		int x = 0;
//		int y = 0;
//		mune();
//		printf("请选择>:");
//		scanf("%d", &input);
//		if (input > 0 && input < 5)
//		{
//			printf("请输入两个数>:");
//			scanf("%d %d", &x, &y);
//			int (*parr[5])(int, int) = { 0,Add,Sub,Che,Chu };
//			ret = (parr[input])(x, y);
//			printf("%d\n", ret);
//		}
//		else if (input >= 5)
//		{
//			printf("输入错误，重新输入！\n");
//		}
//		else if(input == 0)
//		{
//			printf("退出游戏！\n");
//		}
//	} while (input);
//	return 0;
//}

//用回调函数实现6666666666
void mune()
{
	printf("*************************\n");
	printf("*****  1.Add 2.Sub  *****\n");
	printf("*****  3.Che 4.Chu  *****\n");
	printf("*****     5.exit    *****\n");
	printf("*************************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Che(int x, int y)
{
	return x * y;
}
int Chu(int x, int y)
{
	return x / y;
}

//回调函数NB！！！！！！！
int Num(int(*p)(int, int))
{
	int ret = 0;
	int x = 0;
	int y = 0;
	printf("请输入两个数>:");
	scanf("%d %d", &x, &y);
	ret = p(x, y);
	printf("%d\n", ret);								//				  ->靠函数指针 int (* )(int,int)接收
}

int main()
{
	int input = 0;
	do
	{
		mune();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)//printf("\n请输入两个数>:");
		{			  //scanf("%d %d", &x, &y);			//多余内容！！！！->写一个函数来存
		case 1:		  //printf("%d\n", ret);							  ->用一个函数来实现多个函数的功能
			Num(Add);								    //				  ->把要用的函数用地址传给上个函数
			break;										//				  ->靠函数指针 int (* )(int,int)接收
		case 2:
			Num(Sub);
			break;
		case 3:
			Num(Che);
			break;
		case 4:
			Num(Chu);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选！\n");
			break;
		}
	} while (input);
	return 0;
}