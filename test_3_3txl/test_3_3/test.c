#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//ͨѶ¼
//1.ͨѶ¼���ܹ����1000���˵���Ϣ
//ÿ���˵���Ϣ:
//����+����+�Ա�+�绰+��ַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.�޸�ָ���˵���Ϣ
//5.����ָ���˵���Ϣ
//6.����ͨѶ¼����Ϣ

//��ӡ�˵�
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

//��ʼ��ͨѶ¼


int main()
{
	//����ͨѶ¼
	mail_list bcxm;
	//��ʼ��ͨѶ¼
	init_maillis(&bcxm);
	int input = 0;
	do
	{
		mune();
		printf("��ѡ��:>");
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
				printf("�˳�ͨѶ¼��\n");
				break;
			default:
				printf("��������������룡\n");
				break;
		}
	} while (input);
	return 0;
}