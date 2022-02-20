#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//我写的
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如: 2 + 22 + 222 + 2222 + 22222

//计算像22....这样的数
//int fun(int a,int n)
//{
//	int sum = 0;
//	for (n -= 1;n >= 0;n--)
//	{
//		sum = sum + a * pow(10, n);
//	}
//	return sum;
//}
//int main()
//{
//	int a = 2;
//	int n = 5;
//	int i = 0;
//	int count = 0;
//	for (i = n ;i > 0 ;i--)
//	{
//		count += fun(a, i);
//	}
//	printf("%d\n", count);
//
//	return 0;
//}

//鹏哥写的
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int ret = 0;
//	for (i = 0;i < n;i++)
//	{
//		ret = ret * 10 + 2;
//		sum = sum + ret;
//	}
//	printf("%d\n", sum);
//	return 0*/;
//}

//求出0~ 100000之间的所有“水仙花数”并输出。
//"水仙花数”是指一一个n位数，其各位数字的n次方之和确好等于该数本身，
//如:153=1^3+5^3+3^3,则153是-一个“水仙花数”。
//我写的
int main()
{
	int i = 0;
	for (i = 0;i <= 100000;i++)
	{
		//判断i为几位数
		int m = i;
		int n = 0;
		while (m)
		{
			m /= 10;
			n++;
		}
		//判断i是否为自幂数
		int j = 0;
		int x = i;
		int sum = 0;
		//我写的
		//for (j = 0;j < n;j++)
		//{
		//	sum = sum + pow(x % 10, n);
		//	x /= 10;
		//}
		//鹏哥写的
		while (x)
		{
			sum += pow(x % 10, n);
			x /= 10;
		}

		if (i == sum)
			printf("%d ", i);

	}
	return 0;
}