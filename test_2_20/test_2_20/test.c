#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//��д��
//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//����: 2 + 22 + 222 + 2222 + 22222

//������22....��������
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

//����д��
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

//���0~ 100000֮������С�ˮ�ɻ������������
//"ˮ�ɻ�������ָһһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
//��:153=1^3+5^3+3^3,��153��-һ����ˮ�ɻ�������
//��д��
int main()
{
	int i = 0;
	for (i = 0;i <= 100000;i++)
	{
		//�ж�iΪ��λ��
		int m = i;
		int n = 0;
		while (m)
		{
			m /= 10;
			n++;
		}
		//�ж�i�Ƿ�Ϊ������
		int j = 0;
		int x = i;
		int sum = 0;
		//��д��
		//for (j = 0;j < n;j++)
		//{
		//	sum = sum + pow(x % 10, n);
		//	x /= 10;
		//}
		//����д��
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