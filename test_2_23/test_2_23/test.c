#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//ʵ��һ���Ӽ��˳��ĳ���
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
//		printf("��ѡ��>:");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			printf("\n������������>:");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("\n������������>:");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("\n������������>:");
//			scanf("%d %d", &x, &y);
//			ret = Che(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("\n������������>:");
//			scanf("%d %d", &x, &y);
//			ret = Chu(x, y);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//�ú���ָ������ʵ��
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
//		printf("��ѡ��>:");
//		scanf("%d", &input);
//		if (input > 0 && input < 5)
//		{
//			printf("������������>:");
//			scanf("%d %d", &x, &y);
//			int (*parr[5])(int, int) = { 0,Add,Sub,Che,Chu };
//			ret = (parr[input])(x, y);
//			printf("%d\n", ret);
//		}
//		else if (input >= 5)
//		{
//			printf("��������������룡\n");
//		}
//		else if(input == 0)
//		{
//			printf("�˳���Ϸ��\n");
//		}
//	} while (input);
//	return 0;
//}

//�ûص�����ʵ��6666666666
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

//�ص�����NB��������������
int Num(int(*p)(int, int))
{
	int ret = 0;
	int x = 0;
	int y = 0;
	printf("������������>:");
	scanf("%d %d", &x, &y);
	ret = p(x, y);
	printf("%d\n", ret);								//				  ->������ָ�� int (* )(int,int)����
}

int main()
{
	int input = 0;
	do
	{
		mune();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)//printf("\n������������>:");
		{			  //scanf("%d %d", &x, &y);			//�������ݣ�������->дһ����������
		case 1:		  //printf("%d\n", ret);							  ->��һ��������ʵ�ֶ�������Ĺ���
			Num(Add);								    //				  ->��Ҫ�õĺ����õ�ַ�����ϸ�����
			break;										//				  ->������ָ�� int (* )(int,int)����
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}