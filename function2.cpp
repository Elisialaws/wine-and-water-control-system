#pragma once
#include"pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include"function2.h"
void goumai(Sellinformation* dd, Totaldata* shangpin, Inventory1* jiu, Inventory2* shui, char* ming, Client* kehu, int level) {
	printf("���������ѡ����Ҫ�������Ʒ�����������ʮ�֣�\n");
	printf("�׾ƣ�1:ţ��ɽ 2:����ͷ 3:��С�� 4:ę́\n");
	printf("ơ�ƣ�5:�ൺ 6::ѩ�� 7:���� 8;������\n");
	printf("��ƣ�9:���� 10:������ 11:����� 12:���޵�\n");
	printf("���ϣ�13:���¿��� 14:ȸ���Ʒ� 15:�ɿڿ��� 16:�����\n");
	printf("ˮ��  17:ũ��ɽȪ 18:�޹��� 19:����ɽ 20:��¶\n");
	printf("����0��������\n");
	Sellinformation* p;
	if (dd == NULL) {
		Sellinformation dan;
		dan.next = NULL;
		dd = &dan;
		p = dd;
	}
	if (dd != NULL) {
		p = dd;
		while (p->next != NULL)p = p->next;
		Sellinformation dan;//=(Sellinformation)malloc(sizeof(Sellinformation));
		dan.next = NULL;
		p->next = dan;
	}
	int flag = 0;//b�����Ƿ�Ϊ��
	int q = 0;//����Ǯ��
	int sp[10] = { 1 };
	int sl[10] = { 0 };
	int i = 0;
	do {
		scanf("%d", &sp[i]);
		if (sp[i] != 0) {
			scanf("%d", &sl[i]);
		}
		i++;
	} while (sp[i - 1] != 0);
	int l = i;//���湺������
	Totaldata* jxx = shangpin;
	for (int j = 0, o = 0; j < i; o++, j++) {//��ʼ����
		if (sp[j] <= 12) {//����Ǿ�
			Inventory1* zj = jiu;
			for (; strcmp(zj->category, Commoditynames[sp[j]]) != 0; zj = zj->next) {}//������
			if (zj->amount < sl[j]) {//�Ʋ���
				int k = 2;
				printf("������������Ϊ%d�ľƽ�ʣ%dƿ�����ǽ����̽��������������������\n", s[j], zj->amount);
				printf("0��ͬ���ݻ��ջ�  1��ȡ���������Ʒ\n");
				scanf("%d", &k);
				if (k == 1) {
					l--;
					o--;
					continue;
				}
				if (k == 0) {//����������Ƶ���Ϣ��������Ϣ�������Ϣ
					flag = 1;//������Ϊ��
					jinhuo(s[j], 3 * (sl[j] - (zj->amount)), shangpin, jiu, shui);//����
					zj->amount -= sl[j];//����ȥ������
					q += (zj->sellprice)*sl[j];//Ǯ���ϵ��۳�����
					jxx = shangpin;
					for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//��Ʒ��Ϣ����
					jxx->sellamount += sl[j];//����������
					stcpy(dan.client, ming);//�������
					strcpy(dan.category[o], Commoditynames[sp[j]]);//�����Ʒ����
					dan.amount[o] = sl[j];//����
				}
			}
			if (zj->amount >= sl[j]) {//�ƹ�
				flag = 1;//������Ϊ��
				zj->amount -= sl[j];//����ȥ������
				q += (zj->sellprice)*sl[j];//Ǯ���ϵ��۳�����
				jxx = shangpin;
				for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//��Ʒ��Ϣ����
				jxx->sellamount += sl[j];//����������
				stcpy(dan.client, ming);//�������
				strcpy(dan.category[o], Commoditynames[sp[j]]);//�����Ʒ����
				dan.amount[o] = sl[j];//����
			}
		}
		if (sp[j] > 12) {//�����ˮ
			Inventory2* zs = shui;
			for (; strcmp(zs->category, Commoditynames[sp[j]]) != 0; zs = zs->next) {}//������
			if (zs->amount < sl[j]) {//ˮ����
				int k = 2;
				printf("������������Ϊ%d��ˮ��ʣ%dƿ�����ǽ����̽��������������������\n", s[j], zs->amount);
				printf("0��ͬ���ݻ��ջ�  1��ȡ���������Ʒ\n")��
					scanf("%d", &k);
				if (k == 1) {
					l--;
					o--;
					continue;
				}
				if (k == 0) {//����������ˮ����Ϣ��������Ϣ�������Ϣ
					flag = 1;//������Ϊ��
					jinhuo(s[j], 3 * (sl[j] - (zs->amount)), shangpin, jiu, shui);//����
					zs->amount -= sl[j];//����ȥ������
					q += (zs->sellprice)*sl[j];//Ǯ���ϵ��۳�����
					jxx = shangpin;
					for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//��Ʒ��Ϣ����
					jxx->sellamount += sl[j];//����������
					stcpy(dan.client, ming);//�������
					strcpy(dan.category[o], Commoditynames[sp[j]]);//�����Ʒ����
					dan.amount[o] = sl[j];//����
				}
			}
			if (zs->amount >= sl[j]) {//ˮ��
				flag = 1;//������Ϊ��
				zs->amount -= sl[j];//����ȥ������
				q += (zs->sellprice)*sl[j];//Ǯ���ϵ��۳�����
				jxx = shangpin;
				for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//��Ʒ��Ϣ����
				jxx->sellamount += sl[j];//����������
				stcpy(dan.client, ming);//�������
				strcpy(dan.category[o], Commoditynames[sp[j]]);//�����Ʒ����
				dan.amount[o] = sl[j];//����
			}
		}
	}
	dan.point = l;//������Ƶ�����
	Client* kh = kehu;
	for (; strcmp(ming, kh->name) != 0, kh = kh->next) {}//��λ�ͻ���Ϣ
	if (kh->level == 0) {//�ǻ�Ա
		dan.discount = 1;
		dan.money = q;
		Fund += dan.money;
	}
	if (kh->level == 1) {//VIP
		dan.discount = 0.85;
		dan.monry = q * 0.85;
		Fund += dan.money;
	}
	if (kh->level == 2) {//SVIP
		dan, discount = 0.8;
		dan.money = q * 0.8;
		Fund += dan.money;
	}



	return;
}

void jinhuo(int m, int x, Totaldata* shangpin, Inventory1* jiu, Inventory2* shui) {
	Totaldata* sp = shangpin;
	for (; strcmp(sp->name, m) != 0; sp = sp->next) {}
	sp->purchseamoount += x;//��Ʒ����������
	if (m <= 12) {//����
		Inventory1* zj = jiu;
		for (; strcmp(zj->name, Commoditynames[m]) != 0; zj = zj->next) {}
		zj->amount += x;//�������
		sp->cost += x * (zj->purchaseprice);//�ܳɱ�����
		Fund -= x * (zj->purchaseprice);//���ʽ����

		if (m > 12) {//��ˮ
			Inventory2* zs = jiu;
			for (; strcmp(zs->name, Commoditynames[m]) != 0; zs = zs->next) {}
			zs->amount += x;//�������
			sp->cost += x * (zs->purchaseprice);//�ܳɱ�����
			Fund -= x * (zs->purchaseprice);//���ʽ����
		}
	}
}
