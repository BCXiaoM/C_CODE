#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//ʵ��I love China.->China. love I

//��������ʵ��
void Pud(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *right;
		*right = *left;
		*left = tmp;
		left++;
		right--;
	}
}

//�ҵ�������
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	//������ת��
//	int len = strlen(arr);
//	Pud(arr, arr + len - 1);//arr->.anihC evol I
//	int i = 0;
//	int n = 0;
//	for (i = 0;;i++)
//	{
//		if (arr[i] == ' '||arr[i]=='\0')
//		{
//			Pud(arr+n, arr + i - 1);
//			n = i + 1;
//			if (arr[i] == '\0')
//				break;
//		}
//	}
//	printf("%s\n", arr);
//
//}

//�����������
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	//������ת��
	int len = strlen(arr);
	Pud(arr, arr + len - 1);//arr->.anihC evol I
	char* start = arr;
	while (*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		Pud(start,end - 1);
		if (*end == ' ')
			start = end + 1;
		else
			start = end;
	}
	printf("%s\n", arr);

	return 0;
}