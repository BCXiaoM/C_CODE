#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//string相关函数的实现

//*1.strlen的实现
#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}

//实现不了
//int my_strlen(const char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//
//	return 	my_strlen(str - 1 ) + 1;
//}
//int main()
//{
//	char arr[] = "wabianch";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//*2.strcmp实现

//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 || *str2 )
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			str1++;
//			str2++;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "qq";
//	char arr2[] = "qqw";
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}

//*3.strcat实现

//char* my_strcat(char* str1, char* str2)
//{
//	char* cp = str1;
//	while (*str1)
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return cp;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "bit";
//	char* p = my_strcat(arr1,arr2);
//	printf("%s\n", p);
//	return 0;
//}

//*4.strcpy的实现

//char* my_strcpy(char* str1, char* str2)
//{
//	char* p1 = str1;
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return p1;
//}
//int main()
//{
//	char arr[] = "############";
//	char* p = "hello";
//	my_strcpy(arr, p);
//	printf("%s\n", arr);
//	return 0;
//}

//*5.strsrt的实现->字符穿的子串判断函数

//char* my_strstr(char* str1, char* str2)
//{
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* cp = s1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 && *s2 && ( *s1 == *s2))
//		{
//			s1++;
//			s2++; 
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "bbcdyyu";
//	char arr2[] = "bbc";
//	char* ret = my_strstr(arr1,arr2);
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了：%s", ret);
//	}
//	return 0;
//}

//内存函数de实现

//*1.memcpy->内存拷贝
//#include<assert.h>
//void* my_memcpy(void* dest, const void* soc,size_t n)
//{
//	void* ret = dest;
//	assert(dest, soc);
//	while (n--)
//	{
//		*(char*)dest = *(char*)soc;
//		dest = (char*)dest + 1;
//		soc = (char*)soc + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1,20);
//	return 0;
//}

//*2.memmove->拷贝内存重叠的情况
void* my_memmove(void* dest, const void* soc, size_t n)
{
	void* ret = dest;
	assert(dest, soc);
	if (dest < soc)
	{
		while (n--)
		{
			*(char*)dest = *(char*)soc;
			dest = (char*)dest + 1;
			soc = (char*)soc + 1;
		}
	}
	else
	{
		while (n--)
		{
			*((char*)dest + n) = *((char*)soc + n);
		}
	}
	return ret;
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	my_memmove(arr + 2, arr, 20);
	return 0;
}