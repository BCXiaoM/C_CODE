#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���Ͼ���
//��Ŀ����:
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��:ʱ�临�Ӷ�С��o (N) ;
//1 2 3
//2 3 4
//3 4 5
// 
// û�з�����������
//int Find(int arr[][3], int r, int c, int k)
//{
//	int x = 0;
//	int y = c - 1;
//	while (x < r && y >= 0)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
//	int k = 7;
//	int ret = Find(arr, 3, 3, k);
//	if (ret == 1)
//	{
//		printf("�ҵ��ˣ�");
//	}
//	else
//	{
//		printf("�Ҳ�����");
//	}
//	return 0;
//}

////������������
//int Find(int arr[][3], int* px, int* py, int k)
//{
//	int x = 0;
//	int y = *py - 1;
//	while (x < *px && y >= 0)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	int x = 3;
//	int y = 3;
//	int ret = Find(arr, &x, &y, k);
//	if (ret == 1)
//	{
//		printf("�ҵ��ˣ�\n");
//		printf("�����ǣ�%d %d\n", x, y);
//	}
//	else
//	{
//		printf("�Ҳ�����\n");
//	}
//	return 0;
//}
//

//�����ַ�����ʵ��
//�� ��ABCDEF->CDEFAB

////������
// #include<string.h>
//void string_left_spin(char* str,int k)
//{
//	int n = strlen(str);
//	int j = 0;
//	for (j = 0;j < k;j++)
//	{
//		char tmp = *str;
//		int i = 0;
//		for (i = 0;i < n;i++)
//		{
//			*(str + i) = *(str + i + 1);
//		}
//		*(str + n - 1) = tmp;
//	}
//}
//
//int main()
//{
//	char arr[] = "ABCDEF";
//	int k = 2;
//	string_left_spin(arr,k);
//	printf("%s", arr);
//	return 0;
//}

////������ת��
//#include<string.h>
//void Reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void string_left_spin(char* str, int k)  
//{
//	int n = strlen(str);
//	Reverse(str,str + k - 1);
//	Reverse(str + k,str + n - 1);
//	Reverse(str, str + n - 1);
//}
//
//int main()
//{
//	char arr[] = "ABCDEF";
//	int k = 3;
//	string_left_spin(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}

//дһ���������жϸ��ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//�������s1 = AABCD��s2 = BCDAA, ����1����s1 = abcd��s2 = ACBD, ����0.
// 
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC 

////��һ��
//#include<stdio.h>
//int is_spin(char* str1, char* str2)
//{
//	int n = strlen(str1);
//	int j = 0;
//	for (j = 0;j < n;j++)
//	{
//		char tmp = *str1;
//		int i = 0;
//		for (i = 0;i < n;i++)
//		{
//			*(str1 + i) = *(str1 + i + 1);
//		}
//		*(str1 + n - 1) = tmp;
//		if (strcmp(str1, str2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = "AABCD";
//	char arr2[] = "BCDAA";
//	if (is_spin(arr1, arr2) == 1)
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}

//�ڶ���
#include<string.h>
int is_spin(char* str1, char* str2)
{
	//�ж����������Ƿ���ͬ
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	size_t len = strlen(str1);
	//��arr1׷��һ��arr1
	//��AABCDAABCD
	strncat(str1, str1, len);
	//����str2�Ƿ�Ϊstr1���Ӵ�
	char* ret = strstr(str1, str2);
	return ret != NULL;
}

int main()
{
	char arr1[20] = "AABCD";
	char arr2[] = "BCDAA";
	if (is_spin(arr1, arr2) == 1)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}