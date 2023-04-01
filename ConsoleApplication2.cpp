#define _CRT_SECURE_NO_WARNINGS
#include"pch.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<Windows.h>
#include"struct.h"
#include"function1.h"
#include"function2.h"
#include"function3.h"
#include"sellfile.h"
double Fund;//资金
const char Code[] = "3042";
const char Commoditynames[22][30] = { "bu cun zai","niulanshan","erguotou","jiangxiaobai","maotai","qingdao","xuehua","baiwei","haerbin","lafei","boerduo","buduoge","bogendi","baishikele","quechaocafei","kekoukele","binghongcha","nongfushanquan","wahaha","baisuishan","binglu" };
/*int PurchaseCommodity(char* commodityname, Inventory1 *Inventory1head) {
	Inventory1* head, *tmp;
	head = Inventory1head;
	int number, price, i;
	tmp = (Inventory1*)malloc(sizeof(Inventory1));
	printf("请依次输入以下内容\n");
	printf("购买商品的数量   ");
	scanf_s("%d", &number);
	printf("\n商品的进价");
	scanf_s("%d", &price);
	printf("\n商品的生产日期,年，月，日");
	for (i = 0; i < 3; i++);
}*/
void PurchaseSystem(Inventory1 *Inventory1head, Inventory2 *Inventory2head) {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("请您选择需要的功能.\n");
	printf("1:从厂商进酒\n");
	printf("2:从厂商进饮料\n");
	printf("2:修改或删除订单\n");
	printf("3:结束使用\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	while (1) {
		char a;
		scanf_s("%c", &a);
		switch (a) {
		case '1':printf("请按数字输入您要进货商品的名称,每次输入一种,输入F结束使用\n");
			printf("  白酒：1:牛栏山 2:二锅头 3:江小白 4:茅台\n");
			printf("  啤酒：5:青岛 6::雪花 7:百威 8;哈尔滨\n");
			printf("  红酒：9:拉菲 10:波尔多 11:布多格 12:勃艮第\n");
			printf("  饮料：13:百事可乐 14:雀巢科菲 15:可口可乐 16:冰红茶\n");
			printf("  水：  17:农夫山泉 18:娃哈哈 19:百岁山 20:冰露\n");
			while (1) {
				char ch[100];
				gets_s(ch);
				if (ch[0] == 'F')break;
				int i;
				i = ch[0] - '0';
				if (i < 1 || i>20) {
					printf("抱歉，该商品不存在\n");
					fflush(stdin);
					continue;
				}char name[30];
				strcpy_s(name, Commoditynames[i]);
				//PurchaseCommodity(name, Inventory1head);
				break;
			}
		case '2':break;
		case '3':return; break;
		default: fflush(stdin); printf("输入错误，请重新输入\n"); break;

		}
	}
}
void Help() {
	printf("\n");
	printf("  欢迎您进入本酒水管理系统帮助及说明！\n");
	printf("  下列是本店销售的商品\n");
	printf("  白酒：1:牛栏山 2:二锅头 3:江小白 4:茅台\n");
	printf("  啤酒：5:青岛 6::雪花 7:百威 8;哈尔滨\n");
	printf("  红酒：9:拉菲 10:波尔多 11:布多格 12:勃艮第\n");
	printf("  饮料：13:百事可乐 14:雀巢科菲 15:可口可乐 16:冰红茶\n");
	printf("  水：  17:农夫山泉 18:娃哈哈 19:百岁山 20:冰露\n");
	printf("  当您进入该系统时,您可以按照系统的提示输入需要执行的步骤，并完成相关操作\n");
	printf("  如果输入有误则会导致无法完成相应功能;请按提示重新输入,所有中文名称请输入对应汉字拼音\n");
	printf("  当您完成某一操作后，系统会为您自动保存。本系统尚不完善，如有考虑不周之处，敬请谅解。\n");
	printf("  最后，感谢您对该系统的信任！\n");
}
void Controlsystem(char match) {
	Inventory1* Inventory1head;
	Inventory2* Inventory2head;
	Client* Clienthead;
	Sellinformation* Sellhead;
	Totaldata *Totalhead;
	Inventory1head = CreateInventory1();
	Inventory2head = CreateInventory2();
	Clienthead = CreateClent();
	Sellhead = buildsell();
	Totalhead = CreateTotalHead();
	char ch[1000] = { 0 };
	switch (match) {
	case '1':
		printf("如果您是客户不小心误触，输入2选择客户身份\n");
		printf("如果您是管理员则请输入密码\n");
	ADMINISTRATOR:
		while (strcmp(ch, Code) != 0) {
			gets_s(ch);
			if (ch[0] == '2') goto CLIENT;
			if (strcmp(ch, Code) == 0) {
				system("cls");
				printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
				printf("欢迎管理员使用本酒水管理系统，请通过输入以下数字选择你所需要的功能\n");
				printf("0:查看使用帮助手册\n");
				printf("1:查询库存信息\n");
				printf("2:查看营业数据统计及分析\n");
				printf("3:管理进货系统\n");
				printf("4:管理客户信息\n");
				printf("5:结束本次使用\n");
				printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> > \n");
				gets_s(ch);
				int i = ch[0] - '0';
				while (1) {
					switch (i) {
					case 0:Help(); break;
					case 1:break;
					case 2:break;
					case 3:PurchaseSystem(Inventory1head, Inventory2head); break;
					case 4:; break;
					case 5:exit(0); break;//在exit(0)前面四个函数，把链表信息写进文件
					default:printf("输入错误，请重新输入\n");
					}gets_s(ch);
					i = ch[0] - '0';
				}
			}
			else {
				printf("密码错误，请重新输入\n");
			}
		}
		break;
	case '2':CLIENT:
		printf("如果您是管理员不小心误触，输入1选择管理员身份,输入其他内容则进行下一步操作\n");
		gets_s(ch);
		char names[30];
		char phonenumber[100];
		int level;
		if (ch[0] == '1')goto ADMINISTRATOR;
		else {
			system("cls");
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("欢迎客户使用本酒水管理系统，请先登录后再通过输入以下数字选择你所需要的功能，如果未注册过则自动注册\n");
			printf("请输入自己的姓名,电话号");
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			scanf_s("%s %s", names, phonenumber);
			level = FindClient(Clienthead, ch, phonenumber);//如果找到了客户的姓名，则匹配电话号，如果匹配成功，则返回一，如果匹配失败，返回0，如果没找到，创建新节点，让客户录入他的信息,
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("0:查看使用帮助手册\n");
			printf("1:查看自己的订单信息\n");
			printf("2:添加自己的订单\n");
			printf("3:修改自己的订单信息\n");
			printf("4:修改自己的用户信息\n");
			printf("5:结束本次使用\n");
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		}
		break;
		gets_s(ch);
		int i = ch[0] - '0';
		while (1) {
			switch (i) {
			case 0:Help(); break;
			case 1:break;
			case 2: goumai(Sellhead, Totalhead, Inventory1head, Inventory2head, names, Clienthead, level);
				break;
			case 3: break;
			case 4:break;
			case 5:  WriteInventory1(Inventory1head);
				WriteInventory2(Inventory2head);
				WriteClient(Clienthead);
				writesell(Sellhead);
				WriteTotaldata(Totalhead);
				exit(0); break;//exit前面4个函数把链表信息写到文件
			default:printf("输入错误，请重新输入"); break;
			}gets_s(ch);
			i = ch[0] - '0';
		}
	}
}
void Maincontrol() {
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("请选择你的身份\n");
	printf("1:管理员身份\n");
	printf("2:客户身份\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	int identity;
	char ch[1000];
	gets_s(ch);
	while (ch[0] != '1' && ch[0] != '2') {
		printf("输入错误，请重新输入\n");
		gets_s(ch);
	}
	Controlsystem(ch[0]);
}
void initial() {
	FILE* test;
	fopen_s(&test, "../important.txt", "r");
	fscanf_s(test, "%lf", &Fund);
	fclose(test);
}
int main() {
	initial();
	void Maincontrol();
	//也可以是while(getchar()!='\n')用来清空输入错的字符，或者fflush(stdin)清空输入流
	//system("cls")清空屏幕，Sleep(1000)暂停函数
}