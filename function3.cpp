#pragma once
#include"pch.h"
#include<stdio.h>
#include"function3.h"
#include"struct.h"
void WriteInventory1(Inventory1 *Inventory1head) {
	FILE *test;
	test = fopen("../INVENTORY1.txt", "w");
	Inventory1 *head = Inventory1head, *p;
	while (head) {
		fprintf(test, "%d ", head->amount);
		head = head->next;
	}fclose(test);
}
void WriteInventory2(Inventory2 *Inventory2head) {
	FILE *test;
	test = fopen("../INVENTORY2.txt", "w");
	Inventory2 *head = Inventory2head, *p;
	while (head) {
		fprintf(test, "%d %d %d %d", head->amount, head->date[0], head->date[1], head->date[2]);
		head = head->next;
	}fclose(test);
}
void WriteClient(Client *Clienthead) {
	FILE *test;
	test = fopen("../CLIENT.txt", "w");
	Client *head = Clienthead, *p;
	while (head) {
		fprintf(test, "%s %s %s %s %d\n", head->name, head->phone, head->address, head->email, head->level);
		head = head->next;
	}fclose(test);
}
void WriteSellinformation(Sellinformation *Sellhead) {

}
void WriteTotaldata(Totaldata *Totalhead) {
	FILE *test;
	test = fopen("../TOTALDATA.txt", "w");
	Totaldata *head = Totalhead, *p;
	while (head) {
		fprintf(test, "%s %d %d %lf %d %d %d\n", head->name, head->purchaseamount, head->sellamount, head->profit, head->profitrank, head->amountrank, head->cost);
		head = head->next;
	}fclose(test);
}
int  FindClient(Client* head, char* names, char* phones) {
	Client* p = head, *tmp;
	int flag = 0;

	while (p) {
		if (strcmp(p->name, names) == 0) {
			flag = 1;
			break;
		}p = p->next;
	}
	int le = 0;
	while (1) {
		if (flag == 1) {
			if (strcmp(p->phone, phones) == 0) {
				printf("登陆成功\n");
				char lv;
				if (p->level == 0) {
					printf("请问您需要升级为尊贵的VIP会员吗?\n");
					printf("1:升级为VIP会员\n2:升级为SVIP会员\n3:跳过\n");
					scanf_s("%c", &lv);
					fflush(stdin);
					if (lv == '1') {
						Fund += 10000;
						p->level = 1;
					}
					else if (lv == '2') {
						Fund += 30000;
						p->level = 2;
					}le = p->level;
				}
				else if (p->level == 1) {
					printf("请问您需要升级为至尊SVIP会员吗?\n");
					printf("1:升级为SVIP会员\n2:跳过\n");
					scanf_s("%c", &lv);
					fflush(stdin);
					if (lv == '1') {
						Fund += 20000;
						p->level = 2;
					}
				}le = p->level;
				system("cls");
				break;
			}
			else {
				printf("电话号输入错误，请重新输入\n");
				scanf_s("%s", phones);
			}
		}
	}
	if (flag == 0) {
		tmp = (Client*)malloc(sizeof(Client));
		strcpy(tmp->name, names);
		strcpy(tmp->phone, phones);
		printf("欢迎新客户使用本系统\n");
		printf("请输入您的邮箱，地址\n");
		scanf_s("%s %s", tmp->email, tmp->address);
		FILE* test;
		test = fopen("..\CLIENT.txt", "a");
		fprintf(test, "%s %s", tmp->email, tmp->address);
		printf("请问您需要升级为尊贵的VIP用户吗?\n1:充值10000rmb升级为VIP会员，尊享八五折优惠\n2:充值30000rmb升级为SVIP会员，尊享八折优惠\n3:跳过\n");
		char lv;
		scanf_s("%c", &lv);
		fflush(stdin);
		if (lv == '1') {
			Fund += 10000;
			p->level = 1;
		}
		else if (lv == '2') {
			Fund += 30000;
			p->level = 2;
		}
		else { p->level = 0; }
		le = p->level;
		p->next = tmp;
		p = tmp;
		p->next = NULL;

		system("cls");
	}return le;
}
Inventory1* CreateInventory1() {
	Inventory1* head1;
	head1 = (Inventory1*)malloc(sizeof(Inventory1));
	Inventory1* tmp, *p;
	FILE* test;
	test = fopen("../INVENTORY1.txt", "r");
	p = head1;
	int sum = 1;
	char names[12][30] = { "niulanshan","erguotou","jiangxiaobai","maotai","qingdao","xuehua","baiwei","haerbin","lafei","boerduo","buduoge","bogendi" };
	int labels[12] = { 1,1,1,1,2,2,2,2,3,3,3,3 };
	char origins[12][30] = { "guizhou","changbaishan","xihu","guilin","qingdao","xizang","eluosi","weihai","haerbin","faguo","deguo","helan" };
	int yearss[12] = { 5,10,15,6,2,1,3,1,30,20,25,35 };
	int contents[12] = { 40,45,50,37,5,8,10,3,20,18,16,15 };
	int capacitys[12] = { 500,600,750,400,500,550,600,700,500,600,800,400 };
	int price1[12] = { 800,1000,300,8000,40,30,50,60,30000,10000,20000,24000 };
	int price2[12] = { 2000,2700,800,30000,60,50,90,120,100000,30000,60000,50000 };
	strcpy(head1->category, names[0]);
	fscanf(test, "%d", &head1->amount);
	head1->years = yearss[0];
	strcpy(head1->origin, origins[0]);
	head1->label = labels[0];
	head1->purchaseprice = price1[0];
	head1->sellprice = price2[0];
	head1->content = contents[0];
	head1->capacity = capacitys[0];
	while (sum <= 12) {
		tmp = (Inventory1*)malloc(sizeof(Inventory1));
		strcpy(tmp->category, names[sum]);
		fscanf(test, "%d", &tmp->amount);
		tmp->years = yearss[sum];
		strcpy(tmp->origin, origins[sum]);
		tmp->label = labels[sum];
		tmp->purchaseprice = price1[sum];
		tmp->sellprice = price2[sum];
		tmp->content = contents[sum];
		tmp->capacity = capacitys[sum];
		p->next = tmp;
		p = tmp;
		p->next = NULL;
		sum++;
	}head1 = head1->next;
	fclose(test);
	return head1;
}
Inventory2* CreateInventory2() {
	Inventory2* head2;
	head2 = (Inventory2*)malloc(sizeof(Inventory2));
	Inventory2* tmp, *p;
	FILE* test;
	test = fopen("..\INVENTORY2.txt", "r");
	p = head2;
	int sum = 1;
	char names[8][30] = { "baishikele","quechaocafei","kekoukele","binghongcha","nongfushanquan","wahaha","baisuishan","binglu" };
	int storages[8] = { 12,12,12,12,24,24,24,24 };
	int capacitys[8] = { 600,300,600,600,600,1000,800,1000 };
	int purchaseprices[8] = { 40,100,40,50,30,60,40,100 };
	int sellprices[8] = { 100,280,100,130,80,120,100,300 };
	strcpy(tmp->category, names[0]);
	fscanf(test, "%d", &head2->amount);
	head2->purchaseprice = purchaseprices[0];
	head2->sellprice = sellprices[0];
	head2->capacity = capacitys[0];
	fscanf(test, "%d%d%d", &head2->date[0], &head2->date[1], &head2->date[2]);
	head2->storage = storages[0];
	while (sum <= 8) {
		tmp = (Inventory2*)malloc(sizeof(Inventory2));
		strcpy(tmp->category, names[sum]);
		fscanf(test, "%d", &tmp->amount);
		tmp->purchaseprice = purchaseprices[sum];
		tmp->sellprice = sellprices[sum];
		tmp->capacity = capacitys[sum];
		tmp->storage = storages[sum];
		fscanf(test, "%d%d%d", &tmp->date[0], &tmp->date[1], &tmp->date[2]);
		p->next = tmp;
		p = tmp;
		p->next = NULL;
		sum++;
	}head2 = head2->next;
	fclose(test);
	return head2;
}
Client* CreateClent() {
	FILE* test;
	test = fopen("../CLIENT.txt", "r");
	Client* head3, *p, *tmp;
	head3 = (Client*)malloc(sizeof(Client));
	int sum;
	fscanf(test, "%s %s %s %s", head3->name, head3->phone, head3->address, head3->email, head3->level);
	head3->next = NULL;
	p = head3;
	while (test != NULL) {
		tmp = (Client*)malloc(sizeof(Client));
		fscanf(test, "%s%s%s%s", tmp->name, tmp->phone, tmp->address, tmp->email, tmp->level);
		p->next = tmp;
		p = tmp;
		p->next = NULL;

	}fclose(test);
	return head3;
}
Sellinformation* CreateSellInformation() {
	Sellinformation* head4 = NULL;
	head4 = (Sellinformation*)malloc(sizeof(Sellinformation));
	return head4;
}
Totaldata *CreateTotalHead() {
	FILE *test;
	test = fopen("../TOTALDATA.txt", "r");
	Totaldata *head, *p, *tmp;
	head = (Totaldata *)malloc(sizeof(Totaldata));
	p = head;
	fscanf(test, "%s%d%d%lf%d%d%d", head->name, &head->purchseamount, &head->sellamount, &head->profit, &head->profitrank, &head->amountrank, &head->cost);
	head->next = NULL;
	while (test != NULL) {
		tmp = (Totaldata *)malloc(sizeof(Totaldata));
		fscanf(test, "%s%d%d%lf%d%d%d", tmp->name, &tmp->purchseamount, &tmp->sellamount, &tmp->profit, &tmp->profitrank, &tmp->amountrank, &tmp->cost);
		p->next = tmp;
		p = tmp;
		p->next = NULL;
	}fclose(test);
	return head;
}