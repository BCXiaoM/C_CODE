#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////打印菱形
//int main()
//{
//	//上半部分
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0;i < line;i++)
//	{
//		int j = 0;
//		//打印空格
//		for (j = 0;j<line-1-i;j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0;j < 2 * i + 1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//下半部分
//	for (i = 0;i < line;i++)
//	{
//		int j = 0;
//		//打印空格
//		for (j = 0;j <= i;j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0;j < 2 * (line - 1 - i) - 1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水(编程实现)。
//我写的
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = n;
//	int m = 0;
//	int N = 0;
//	while (n)
//	{
//		N = n + m;
//		n = (n + m) / 2;
//		m = 0;
//		sum += n;
//		m = N % 2;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//鹏哥写的
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int total = money;
//	int empty = money;
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}

//输入-个整数数组，实现一不函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分

//我写的
//void fun(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			int j = 0;
//			for (j = i;j < sz;j++)
//			{
//				if (arr[j] % 2 == 1)
//				{
//					int tmp = arr[j];
//					arr[j] = arr[i];
//					arr[i] = tmp;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 3,7,9,6,2,3,1,6,8,7,9,5,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	fun(arr,sz);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//鹏哥写的就是NB
void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//从前找偶数
		while ((left < right) && arr[left] % 2 == 1)
		{
			left++;
		}
		//从后找奇数
		while ((left < right) && arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,4,3,2,5,7,6,9,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	print(arr, sz);
	return 0;
}