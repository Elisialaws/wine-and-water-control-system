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
	//0是不是会员，1是VIP会员，2是SVIP会员，折扣和会员折扣不能叠加，消费满10000打九五折，消费满50000打九折，VIP会员打八五折，SVIP打八折,升级VIP花10000，SVIP花30000
}Client;//客户信息结构体

typedef struct sellinformation {
	char client[30];//顾客名字
	char  category[10][30];//要有一个对照表，数字对应酒水的详细名称,暂定最多一次选10种
	int amount[10];
	int point;//存储买了几种
	double discount;//打了多少折
	double money;//交易金额
	struct sellinformation* next;
}Sellinformation;//这个是每单的信息

typedef struct totaldata {//这个准备一个结构体数组吧，用作统计查询
	char name[30];//商品名字
	int purchseamount;//购买和销售的数量
	int sellamount;
	double profit;//利润
	int profitrank;//利润和销售量的排名
	int amountrank;
	int cost; //总成本
	struct totaldata* next;
}Totaldata;//商品信息

typedef struct inventory1 {//库存信息
	char category[40];//名称
	int amount;
	int years;//年份
	char origin[40];//原产地
	int label;//白酒，红酒，或者啤酒 1为白酒，2为红酒，3为啤酒
	int purchaseprice;//进价
	int content;//酒精度数
	int sellprice;//售价
	int capacity;//容量
	struct inventory1* next;
}Inventory1;//这个是酒的

typedef struct inventory2 {
	char category[40];
	int amount;
	int date[3];//年月日，生产日期,最多三个批次
	int storage;//保质期，按月份算
	int purchaseprice;//进价
	int sellprice;//售价
	int capacity;//容量
	struct inventory2* next;
}Inventory2;
#endif // STRUCT_H_INCLUDED
