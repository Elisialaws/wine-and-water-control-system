#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function1.h"
#include"struct.h"
//这是统计的函数，统计销售信息
void tongji(Sellinformation*head1, Totaldata*head2) {//传入销售记录表头，信息表头
	double sellsum = 0;//销售总额
	while (head1 != NULL) {
		sellsum += head1->money;
		head1 = head1->next;
	}
	double coastsum = 0;//总成本
	double profitsum = 0;//总利润
	Totaldata*p = head2;
	while (p != NULL) {
		coastsum += head2->cost;
		profitsum += head2->profit;
		p = p->next;
	}
	printf("销售总额:%.2lf\n", sellsum);
	printf("总成本:%.2lf\n", coastsum);
	printf("总利润:%.2lf\n", profitsum);
	printf("各商品销售数量:\n");
	while (head2 != NULL) {
		printf("%s:%d\n", head2->name, head2->sellamount);
		head2 = head2->next;
	}

}

//这是用户打印函数,传入的是名字数组
void buyerpirnt(Sellinformation*head) {
	char name[30];
	printf("请输入客户姓名:");
	scanf("%s", name);
	while (head != NULL) {
		if (strcmp(name, head->client) == 0) {
			printf("购买日期:%d年%d月%d日\n", head->selltime[0], head->selltime[1], head->selltime[2]);
			printf("购买信息:\n");
			for (int i = 0; i < head->point; i++) {
				printf("%s:%d箱\n", head->category[i], head->amount[i]);
			}
			printf("购买总金额:%.2lf", head->money);
			printf("\n");
		}
		head = head->next;
	}
}

//1.打印库存信息
void kucunprint(Inventory1*head, Inventory2*head1, Totaldata*head3) {
	//这是输出酒的
	while (head != NULL) {//首先利用Inventory1输出
		printf("商品名称:%s\n", head->category);
		printf("数量:%d\n", head->amount);
		printf("年份:%d\n", head->years);
		printf("原产地:%s\n", head->origin);
		switch (head->label) {
		case 1:printf("种类:白酒\n"); break;
		case 2:printf("种类:红酒\n"); break;
		case 3:printf("种类:啤酒\n"); break;
		}
		printf("容量:%d\n", head->capacity);
		printf("酒精度数:%d\n", head->content);
		printf("售价:%d\n", head->sellprice);
		//这里开始使用TotalData输出
		printf("购买数量:%d\n", head3->purchseamount);
		printf("该商品总成本:%.2lf\n", head3->cost);
		printf("出售数量:%d\n", head3->sellamount);
		printf("出售排名:%d\n", head3->purchseamount);
		printf("该商品总利润:%.2lf\n", head3->profit);
		printf("总利润排名:%d\n", head3->profitrank);
		printf("\n");

		head = head->next; head3 = head3->next;
	}

	//这是输出饮料的
	while (head1 != NULL) {
		printf("商品名称:%s\n", head1->category);
		printf("数量:%d\n", head1->amount);
		printf("生产日期:%d年%d月%d日\n", head1->date[0], head1->date[1], head1->date[2]);
		printf("保质期:%d月\n", head1->storage);
		printf("售价:%d\n", head1->sellprice);
		printf("容量:%d\n", head1->capacity);
		//这里开始使用TotalData输出
		printf("购买数量:%d\n", head3->purchseamount);
		printf("该商品总成本:%.2lf\n", head3->cost);
		printf("出售数量:%d\n", head3->sellamount);
		printf("出售排名:%d\n", head3->purchseamount);
		printf("该商品总利润:%.2lf\n", head3->profit);
		printf("总利润排名:%d\n", head3->profitrank);
		printf("\n");

		head1 = head1->next; head3 = head3->next;
	}
}

//2，打印出售信息
void chushoupirnt(Sellinformation*head) {
	printf("顾客姓名:%s\n", head->client);
	printf("购买信息:\n");
	for (int i = 0; i < head->point; i++) {
		printf("%s:%d箱\n", head->category[i], head->amount);
	}
	printf("销售日期:%d年%d月%d日\n", head->selltime[0], head->selltime[1], head->selltime[2]);
	printf("交易金额:%.2lf\n", head->money);
}


//1，打印库存信息2，打印出售信息3，打印某个客户出售信息
void guanliprint(Inventory1*head, Inventory2*haed1, Sellinformation*head2, Totaldata*head3) {
	printf("请输入您要进行的操作:\n");
	printf("1.打印库存信息2.打印出售信息3.打印客户购买信息");
	int n;
	scanf("%d", &n);
	switch (n) {
	case 1:kucunprint(head, haed1, head3); break;
	case 2:chushoupirnt(head2); break;
	case 3:buyerpirnt(head2); break;
	}
}

void find_xiaoliang(Totaldata*head) {
	Totaldata*max = head;
	while (head != NULL) {
		if (head->sellamount > max->sellamount)
			max = head;
		head = head->next;
	}
	printf("当前销量最好的酒水是:%s\n", max->name);
	printf("销量是:%d\n", max->sellamount);
}

void find_lirun(Totaldata*head) {
	Totaldata*max = head;
	while (head != NULL) {
		if (head->profit > max->profit)
			max = head;
		head = head->next;
	}
	printf("当前利润最大的酒水是:%s\n", max->name);
	printf("利润是:%d\n", max->sellamount);
}

void find_yali(Totaldata*head) {
	int sum = 0;
	while (head != NULL) {
		sum += head->purchseamount - head->sellamount;
	}
	if (500 - sum < 80) {//库存容量暂定500
		printf("当前库存紧张\n");
		printf("库存占比是:%.2lf", sum / 500);
	}
	else {
		printf("当前库存尚未紧张\n");
		printf("库存占比是:%.2lf", sum / 500);
	}
}

void find(Totaldata*head) {//这是调查函数
	printf("请输入您要进行的操作\n");
	printf("1.查询当前销量最好的酒水\n");
	printf("2.查询当前销售利润最大的酒水\n");
	printf("3.查询库存压力\n");
	int n;
	scanf("%d", &n);
	switch (n) {
	case 1:find_xiaoliang(head); break;
	case 2:find_lirun(head); break;
	case 3:find_yali(head); break;
	}
}