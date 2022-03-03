#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��ʼ��ͨѶ¼
void init_maillis(mail_list* pc)
{
	pc->sz = 0;
	//�ڴ����ú���memset
	memset(pc->date, 0, sizeof(pc->date));
}

//�����˵���Ϣ
void increase(mail_list* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->date[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->date[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->date[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ���\n");
}

//��ʾ��Ϣ
void Print(const mail_list* pc)
{
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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

//��λ��Ϣ
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

//ɾ��ָ���˵���Ϣ
void delete(mail_list* pc)
{
	char Name[20] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", Name);
	int pos = search(pc, Name);
	//����
	if (pos == -1)
	{
		printf("�Ҳ���ɾ���˵���Ϣ��\n");
		return;
	}
	//ɾ��
	int i = 0;
	for (i = pos;i < pc->sz - 1;i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");

}

//����ָ���˵���Ϣ
void lookup(mail_list* pc)
{
	char Name[20] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", Name);
	int pos = search(pc, Name);
	if (pos == -1)
	{
		printf("�Ҳ��������˵���Ϣ��\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[pos].name,
													pc->date[pos].age,
													pc->date[pos].sex,
													pc->date[pos].tele,
													pc->date[pos].addr);
	}
}

//�޸�ָ���˵���Ϣ
void modify(mail_list* pc)
{
	char Name[20] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", Name);
	int pos = search(pc, Name);
	if (pos == -1)
	{
		printf("�Ҳ���Ҫ�޸��˵���Ϣ��\n");
		return;
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->date[pos].name);
		printf("����������:>");
		scanf("%d", &(pc->date[pos].age));
		printf("�������Ա�:>");
		scanf("%s", pc->date[pos].sex);
		printf("������绰:>");
		scanf("%s", pc->date[pos].tele);
		printf("�������ַ:>");
		scanf("%s", pc->date[pos].addr);

		printf("��ӳɹ���\n");
	}
}





