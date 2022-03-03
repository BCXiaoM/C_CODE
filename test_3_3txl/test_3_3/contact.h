#pragma once
#include<stdio.h>
#include<memory.h>
#include<string.h>

#define MAX 1000
#define MAX_NAME 10
#define MAX_SEX	10
#define MAX_TELE 12
#define MAX_ADDR 10





typedef struct contacts
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}contacts;

typedef struct mail_list
{
	contacts date[MAX];
	int sz;
}mail_list;


//初始化通讯录
void init_maillis(mail_list* pc);
//增加人的信息
void increase(mail_list* pc);
//显示信息
void Print(mail_list* pc);
//删除指定人的信息
void delete(mail_list* pc);
//5.查找指定人的信息
void lookup(mail_list* pc);
//修改指定人的信息
void modify(mail_list* pc);

