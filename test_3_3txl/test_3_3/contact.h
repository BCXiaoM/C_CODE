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


//��ʼ��ͨѶ¼
void init_maillis(mail_list* pc);
//�����˵���Ϣ
void increase(mail_list* pc);
//��ʾ��Ϣ
void Print(mail_list* pc);
//ɾ��ָ���˵���Ϣ
void delete(mail_list* pc);
//5.����ָ���˵���Ϣ
void lookup(mail_list* pc);
//�޸�ָ���˵���Ϣ
void modify(mail_list* pc);

