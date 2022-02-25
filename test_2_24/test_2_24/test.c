#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//复习冒泡排序

//void fun(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz-1 ;i++)
//	{
//		int left = 0;
//		int j = 0;
//		for (j = 0;j < sz-1-i ;j++)
//		{
//			if (arr[left] > arr[left + 1])
//			{
//				int tmp = arr[left];
//				arr[left] = arr[left + 1];
//				arr[left + 1] = tmp;
//			}
//			left++;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 3,6,8,9,2,7,5,1,0,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	fun(arr, sz);  
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

#include<string.h>
//模拟实现qsort函数->快速排序
//把元素交换
void Move(char* a, char* b,int width)
{
	int i = 0;
	for (i = 0;i < width;i++)
	{
		int tmp = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = tmp;
	}
}

struct stu
{
	char name[20];
	int age;
};

void cmp_stu_name(const void* e1, const void* e2)
{
	//return (((struct stu*)e1)->age) - (((struct stu*)e2)->age);
	return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
}

void cmp_int(const void* e1, const void* e2)
{
	//e1 = (int*)e1;
	//e2 = (int*)e2;
	//return (*e1 - *e2);			//不能用*e1,*e2都没改
	return (*(int*)e1) - (*(int*)e2);
}

void my_qsort(void* base,
	int sz,
	int width,
	int (*cmp)(const void* e1, const void* e2)
)
{
	//实现趟数
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		//交换的循环
		int j = 0;
		for (j = 0;j < sz - 1 - i;j++)
		{
			//判断大小
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//进行交换
				Move((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void print_arr(int* arr, int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", *(arr + i));
	}
}

void print_stu(struct stu* s, int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%s %d\n", (s + i)->name, (s + i)->age);
	}
}

void test1()
{
	struct stu s[] = { {"zhangsan",20},{"lisi",23},{"wangwu",19} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_stu_name);
	print_stu(s, sz);
}

void test2()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print_arr(arr, sz);
}

int main()
{
	test1();
	return 0;
}