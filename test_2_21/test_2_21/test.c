#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////��ӡ����
//int main()
//{
//	//�ϰ벿��
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0;i < line;i++)
//	{
//		int j = 0;
//		//��ӡ�ո�
//		for (j = 0;j<line-1-i;j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0;j < 2 * i + 1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//�°벿��
//	for (i = 0;i < line;i++)
//	{
//		int j = 0;
//		//��ӡ�ո�
//		for (j = 0;j <= i;j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0;j < 2 * (line - 1 - i) - 1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ(���ʵ��)��
//��д��
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
//����д��
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

//����-���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿��

//��д��
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

//����д�ľ���NB
void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//��ǰ��ż��
		while ((left < right) && arr[left] % 2 == 1)
		{
			left++;
		}
		//�Ӻ�������
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