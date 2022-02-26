#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//杨氏矩阵
//题目内容:
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求:时间复杂度小于o (N) ;
//1 2 3
//2 3 4
//3 4 5
// 
// 没有返回坐标的情况
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
//		printf("找到了！");
//	}
//	else
//	{
//		printf("找不到！");
//	}
//	return 0;
//}

////返回坐标的情况
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
//		printf("找到了！\n");
//		printf("坐标是：%d %d\n", x, y);
//	}
//	else
//	{
//		printf("找不到！\n");
//	}
//	return 0;
//}
//

//左旋字符串的实现
//列 ：ABCDEF->CDEFAB

////暴力法
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

////三步反转法
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

//写一个函数，判断个字符串是否为另外一个字符串旋转之后的字符串。
//例如给定s1 = AABCD和s2 = BCDAA, 返回1给定s1 = abcd和s2 = ACBD, 返回0.
// 
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC 

////第一种
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

//第二种
#include<string.h>
int is_spin(char* str1, char* str2)
{
	//判断两个长度是否相同
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	size_t len = strlen(str1);
	//将arr1追加一个arr1
	//像；AABCDAABCD
	strncat(str1, str1, len);
	//判算str2是否为str1的子串
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