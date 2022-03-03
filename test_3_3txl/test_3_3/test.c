#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//通讯录
//1.通讯录中能够存放1000个人的信息
//每个人的信息:
//名字+年龄+性别+电话+地址
//2.增加人的信息
//3.删除指定人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.排序通讯录的信息

//打印菜单
void mune()
{
	printf("****************************\n");
	printf("****** 1.Add   2.del  ******\n");
	printf("****** 3.mod   4.sch  ******\n");
	printf("****** 5.sor   6.prt  ******\n");
	printf("******     0.exit     ******\n");
	printf("****************************\n");

}

enum option
{
	EXIT,
	ADD,
	DEL,
	MOD,
	SCH,
	SOR,
	PRT,
};

//初始化通讯录


int main()
{
	//定义通讯录
	mail_list bcxm;
	//初始化通讯录
	init_maillis(&bcxm);
	int input = 0;
	do
	{
		mune();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
			case ADD:
				increase(&bcxm);
				break;
			case DEL:
				delete(&bcxm);
				break;
			case MOD:
				modify(&bcxm);
				break;
			case SCH:
				lookup(&bcxm);
				break;
			case SOR:
				//sort(&bcxm);
				break;
			case PRT:
				Print(&bcxm);
				break;
			case EXIT:
				printf("退出通讯录！\n");
				break;
			default:
				printf("输入错误，重新输入！\n");
				break;
		}
	} while (input);
	return 0;
}