#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化通讯录
void init_maillis(mail_list* pc)
{
	pc->sz = 0;
	//内存设置函数memset
	memset(pc->date, 0, sizeof(pc->date));
}

//增加人的信息
void increase(mail_list* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->date[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->date[pc->sz].addr);

	pc->sz++;
	printf("添加成功！\n");
}

//显示信息
void Print(const mail_list* pc)
{
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[i].name,
													pc->date[i].age,
													pc->date[i].sex,
													pc->date[i].tele,
													pc->date[i].addr);
	}
}

//定位信息
static int search(mail_list* pc, char Name[])
{
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		if (strcmp(pc->date[i].name, Name) == 0)
			return i;
	}
	return -1;

}

//删除指定人的信息
void delete(mail_list* pc)
{
	char Name[20] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除人的名字:>");
	scanf("%s", Name);
	int pos = search(pc, Name);
	//查找
	if (pos == -1)
	{
		printf("找不到删除人的信息！\n");
		return;
	}
	//删除
	int i = 0;
	for (i = pos;i < pc->sz - 1;i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");

}

//查找指定人的信息
void lookup(mail_list* pc)
{
	char Name[20] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", Name);
	int pos = search(pc, Name);
	if (pos == -1)
	{
		printf("找不到查找人的信息！\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[pos].name,
													pc->date[pos].age,
													pc->date[pos].sex,
													pc->date[pos].tele,
													pc->date[pos].addr);
	}
}

//修改指定人的信息
void modify(mail_list* pc)
{
	char Name[20] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", Name);
	int pos = search(pc, Name);
	if (pos == -1)
	{
		printf("找不到要修改人的信息！\n");
		return;
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", pc->date[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->date[pos].age));
		printf("请输入性别:>");
		scanf("%s", pc->date[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pc->date[pos].tele);
		printf("请输入地址:>");
		scanf("%s", pc->date[pos].addr);

		printf("添加成功！\n");
	}
}





