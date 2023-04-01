#pragma once
#include"pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include"function2.h"
void goumai(Sellinformation* dd, Totaldata* shangpin, Inventory1* jiu, Inventory2* shui, char* ming, Client* kehu, int level) {
	printf("请输入序号选择您要购买的商品及数量（最多十种）\n");
	printf("白酒：1:牛栏山 2:二锅头 3:江小白 4:茅台\n");
	printf("啤酒：5:青岛 6::雪花 7:百威 8;哈尔滨\n");
	printf("红酒：9:拉菲 10:波尔多 11:布多格 12:勃艮第\n");
	printf("饮料：13:百事可乐 14:雀巢科菲 15:可口可乐 16:冰红茶\n");
	printf("水：  17:农夫山泉 18:娃哈哈 19:百岁山 20:冰露\n");
	printf("输入0结束购买\n");
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
	int flag = 0;//b本单是否为空
	int q = 0;//本单钱数
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
	int l = i;//储存购买种类
	Totaldata* jxx = shangpin;
	for (int j = 0, o = 0; j < i; o++, j++) {//开始操作
		if (sp[j] <= 12) {//买的是酒
			Inventory1* zj = jiu;
			for (; strcmp(zj->category, Commoditynames[sp[j]]) != 0; zj = zj->next) {}//库存检索
			if (zj->amount < sl[j]) {//酒不够
				int k = 2;
				printf("您所购买的序号为%d的酒仅剩%d瓶，我们将立刻进货并售卖给您，请见谅\n", s[j], zj->amount);
				printf("0：同意暂缓收货  1：取消购买此商品\n");
				scanf("%d", &k);
				if (k == 1) {
					l--;
					o--;
					continue;
				}
				if (k == 0) {//继续买，整理酒的信息，订单信息，库存信息
					flag = 1;//本单不为空
					jinhuo(s[j], 3 * (sl[j] - (zj->amount)), shangpin, jiu, shui);//进货
					zj->amount -= sl[j];//库存减去购买量
					q += (zj->sellprice)*sl[j];//钱加上单价乘数量
					jxx = shangpin;
					for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//商品信息检索
					jxx->sellamount += sl[j];//销售量增加
					stcpy(dan.client, ming);//添加姓名
					strcpy(dan.category[o], Commoditynames[sp[j]]);//添加商品名称
					dan.amount[o] = sl[j];//数量
				}
			}
			if (zj->amount >= sl[j]) {//酒够
				flag = 1;//本单不为空
				zj->amount -= sl[j];//库存减去购买量
				q += (zj->sellprice)*sl[j];//钱加上单价乘数量
				jxx = shangpin;
				for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//商品信息检索
				jxx->sellamount += sl[j];//销售量增加
				stcpy(dan.client, ming);//添加姓名
				strcpy(dan.category[o], Commoditynames[sp[j]]);//添加商品名称
				dan.amount[o] = sl[j];//数量
			}
		}
		if (sp[j] > 12) {//买的是水
			Inventory2* zs = shui;
			for (; strcmp(zs->category, Commoditynames[sp[j]]) != 0; zs = zs->next) {}//库存检索
			if (zs->amount < sl[j]) {//水不够
				int k = 2;
				printf("您所购买的序号为%d的水仅剩%d瓶，我们将立刻进货并售卖给您，请见谅\n", s[j], zs->amount);
				printf("0：同意暂缓收货  1：取消购买此商品\n")；
					scanf("%d", &k);
				if (k == 1) {
					l--;
					o--;
					continue;
				}
				if (k == 0) {//继续买，整理水的信息，订单信息，库存信息
					flag = 1;//本单不为空
					jinhuo(s[j], 3 * (sl[j] - (zs->amount)), shangpin, jiu, shui);//进货
					zs->amount -= sl[j];//库存减去购买量
					q += (zs->sellprice)*sl[j];//钱加上单价乘数量
					jxx = shangpin;
					for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//商品信息检索
					jxx->sellamount += sl[j];//销售量增加
					stcpy(dan.client, ming);//添加姓名
					strcpy(dan.category[o], Commoditynames[sp[j]]);//添加商品名称
					dan.amount[o] = sl[j];//数量
				}
			}
			if (zs->amount >= sl[j]) {//水够
				flag = 1;//本单不为空
				zs->amount -= sl[j];//库存减去购买量
				q += (zs->sellprice)*sl[j];//钱加上单价乘数量
				jxx = shangpin;
				for (; strcmp(jxx->name, Commoditynames[sp[j]]) != 0; jxx = jxx->next) {}//商品信息检索
				jxx->sellamount += sl[j];//销售量增加
				stcpy(dan.client, ming);//添加姓名
				strcpy(dan.category[o], Commoditynames[sp[j]]);//添加商品名称
				dan.amount[o] = sl[j];//数量
			}
		}
	}
	dan.point = l;//本单买酒的种类
	Client* kh = kehu;
	for (; strcmp(ming, kh->name) != 0, kh = kh->next) {}//定位客户信息
	if (kh->level == 0) {//非会员
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
	sp->purchseamoount += x;//商品销售量增加
	if (m <= 12) {//进酒
		Inventory1* zj = jiu;
		for (; strcmp(zj->name, Commoditynames[m]) != 0; zj = zj->next) {}
		zj->amount += x;//库存增加
		sp->cost += x * (zj->purchaseprice);//总成本增加
		Fund -= x * (zj->purchaseprice);//总资金减少

		if (m > 12) {//进水
			Inventory2* zs = jiu;
			for (; strcmp(zs->name, Commoditynames[m]) != 0; zs = zs->next) {}
			zs->amount += x;//库存增加
			sp->cost += x * (zs->purchaseprice);//总成本增加
			Fund -= x * (zs->purchaseprice);//总资金减少
		}
	}
}
