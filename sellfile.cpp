#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
#include"sellfile.h"
typedef struct sellinformation1 {
	char client[30];//顾客名字
	char  category[10][30];//要有一个对照表，数字对应酒水的详细名称,暂定最多一次选10种
	int amount[10];
	int  selltime[3];//销售日期
	double money;//交易金额
	int point;//存储买了几种
}Sellinformation1;//这个是每单的信息

Sellinformation* buildsell(void) {//这是创建链表
	Sellinformation*head, *p, *tmp;
	head = NULL;
	FILE*fp;
	Sellinformation1 q;
	fp = fopen("./SELLINFORMATION.txt", "r");
	while (!feof(fp)) {
		fread(&q, sizeof(Sellinformation1), 1, fp);
		p = (Sellinformation*)malloc(sizeof(Sellinformation));
		p->point = q.point;
		for (int i = 0; i < p->point; i++) {
			strcpy(p->category[i], q.category[i]);
			p->amount[i] = q.amount[i];

		}
		strcpy(p->client, q.client);
		p->money = q.money;
		for (int i = 0; i < 3; i++) {
			p->selltime[i] = q.selltime[i];
		}
		p->next = NULL;
		if (head == NULL) {
			head = tmp = p;
		}
		else {
			tmp->next = p;
			tmp = p;
		}
	}
	return head;
}

void writesell(Sellinformation*head) {//这个是写入文件函数
	FILE*fp;
	fp = fopen("./Sellinformation", "w");
	Sellinformation1 p;
	while (head != NULL) {
		p.point = head->point;
		for (int i = 0; i < p.point; i++) {
			strcpy(p.category[i], head->category[i]);
			p.amount[i] = head->amount[i];

		}
		strcpy(p.client, head->client);
		p.money = head->money;
		for (int i = 0; i < 3; i++) {
			p.selltime[i] = head->selltime[i];
		}
		fwrite(&p, sizeof(Sellinformation1), 1, fp);
		head = head->next;
	}
}



