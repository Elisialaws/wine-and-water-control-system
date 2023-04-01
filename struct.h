#pragma once
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
typedef struct client {
	char name[25];
	char phone[16];
	char address[50];
	char email[25];
	int level;
	struct client* next;
	//0�ǲ��ǻ�Ա��1��VIP��Ա��2��SVIP��Ա���ۿۺͻ�Ա�ۿ۲��ܵ��ӣ�������10000������ۣ�������50000����ۣ�VIP��Ա������ۣ�SVIP�����,����VIP��10000��SVIP��30000
}Client;//�ͻ���Ϣ�ṹ��

typedef struct sellinformation {
	char client[30];//�˿�����
	char  category[10][30];//Ҫ��һ�����ձ����ֶ�Ӧ��ˮ����ϸ����,�ݶ����һ��ѡ10��
	int amount[10];
	int point;//�洢���˼���
	double discount;//���˶�����
	double money;//���׽��
	struct sellinformation* next;
}Sellinformation;//�����ÿ������Ϣ

typedef struct totaldata {//���׼��һ���ṹ������ɣ�����ͳ�Ʋ�ѯ
	char name[30];//��Ʒ����
	int purchseamount;//��������۵�����
	int sellamount;
	double profit;//����
	int profitrank;//�����������������
	int amountrank;
	int cost; //�ܳɱ�
	struct totaldata* next;
}Totaldata;//��Ʒ��Ϣ

typedef struct inventory1 {//�����Ϣ
	char category[40];//����
	int amount;
	int years;//���
	char origin[40];//ԭ����
	int label;//�׾ƣ���ƣ�����ơ�� 1Ϊ�׾ƣ�2Ϊ��ƣ�3Ϊơ��
	int purchaseprice;//����
	int content;//�ƾ�����
	int sellprice;//�ۼ�
	int capacity;//����
	struct inventory1* next;
}Inventory1;//����ǾƵ�

typedef struct inventory2 {
	char category[40];
	int amount;
	int date[3];//�����գ���������,�����������
	int storage;//�����ڣ����·���
	int purchaseprice;//����
	int sellprice;//�ۼ�
	int capacity;//����
	struct inventory2* next;
}Inventory2;
#endif // STRUCT_H_INCLUDED
