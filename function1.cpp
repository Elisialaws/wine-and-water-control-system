#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function1.h"
#include"struct.h"
//����ͳ�Ƶĺ�����ͳ��������Ϣ
void tongji(Sellinformation*head1, Totaldata*head2) {//�������ۼ�¼��ͷ����Ϣ��ͷ
	double sellsum = 0;//�����ܶ�
	while (head1 != NULL) {
		sellsum += head1->money;
		head1 = head1->next;
	}
	double coastsum = 0;//�ܳɱ�
	double profitsum = 0;//������
	Totaldata*p = head2;
	while (p != NULL) {
		coastsum += head2->cost;
		profitsum += head2->profit;
		p = p->next;
	}
	printf("�����ܶ�:%.2lf\n", sellsum);
	printf("�ܳɱ�:%.2lf\n", coastsum);
	printf("������:%.2lf\n", profitsum);
	printf("����Ʒ��������:\n");
	while (head2 != NULL) {
		printf("%s:%d\n", head2->name, head2->sellamount);
		head2 = head2->next;
	}

}

//�����û���ӡ����,���������������
void buyerpirnt(Sellinformation*head) {
	char name[30];
	printf("������ͻ�����:");
	scanf("%s", name);
	while (head != NULL) {
		if (strcmp(name, head->client) == 0) {
			printf("��������:%d��%d��%d��\n", head->selltime[0], head->selltime[1], head->selltime[2]);
			printf("������Ϣ:\n");
			for (int i = 0; i < head->point; i++) {
				printf("%s:%d��\n", head->category[i], head->amount[i]);
			}
			printf("�����ܽ��:%.2lf", head->money);
			printf("\n");
		}
		head = head->next;
	}
}

//1.��ӡ�����Ϣ
void kucunprint(Inventory1*head, Inventory2*head1, Totaldata*head3) {
	//��������Ƶ�
	while (head != NULL) {//��������Inventory1���
		printf("��Ʒ����:%s\n", head->category);
		printf("����:%d\n", head->amount);
		printf("���:%d\n", head->years);
		printf("ԭ����:%s\n", head->origin);
		switch (head->label) {
		case 1:printf("����:�׾�\n"); break;
		case 2:printf("����:���\n"); break;
		case 3:printf("����:ơ��\n"); break;
		}
		printf("����:%d\n", head->capacity);
		printf("�ƾ�����:%d\n", head->content);
		printf("�ۼ�:%d\n", head->sellprice);
		//���￪ʼʹ��TotalData���
		printf("��������:%d\n", head3->purchseamount);
		printf("����Ʒ�ܳɱ�:%.2lf\n", head3->cost);
		printf("��������:%d\n", head3->sellamount);
		printf("��������:%d\n", head3->purchseamount);
		printf("����Ʒ������:%.2lf\n", head3->profit);
		printf("����������:%d\n", head3->profitrank);
		printf("\n");

		head = head->next; head3 = head3->next;
	}

	//����������ϵ�
	while (head1 != NULL) {
		printf("��Ʒ����:%s\n", head1->category);
		printf("����:%d\n", head1->amount);
		printf("��������:%d��%d��%d��\n", head1->date[0], head1->date[1], head1->date[2]);
		printf("������:%d��\n", head1->storage);
		printf("�ۼ�:%d\n", head1->sellprice);
		printf("����:%d\n", head1->capacity);
		//���￪ʼʹ��TotalData���
		printf("��������:%d\n", head3->purchseamount);
		printf("����Ʒ�ܳɱ�:%.2lf\n", head3->cost);
		printf("��������:%d\n", head3->sellamount);
		printf("��������:%d\n", head3->purchseamount);
		printf("����Ʒ������:%.2lf\n", head3->profit);
		printf("����������:%d\n", head3->profitrank);
		printf("\n");

		head1 = head1->next; head3 = head3->next;
	}
}

//2����ӡ������Ϣ
void chushoupirnt(Sellinformation*head) {
	printf("�˿�����:%s\n", head->client);
	printf("������Ϣ:\n");
	for (int i = 0; i < head->point; i++) {
		printf("%s:%d��\n", head->category[i], head->amount);
	}
	printf("��������:%d��%d��%d��\n", head->selltime[0], head->selltime[1], head->selltime[2]);
	printf("���׽��:%.2lf\n", head->money);
}


//1����ӡ�����Ϣ2����ӡ������Ϣ3����ӡĳ���ͻ�������Ϣ
void guanliprint(Inventory1*head, Inventory2*haed1, Sellinformation*head2, Totaldata*head3) {
	printf("��������Ҫ���еĲ���:\n");
	printf("1.��ӡ�����Ϣ2.��ӡ������Ϣ3.��ӡ�ͻ�������Ϣ");
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
	printf("��ǰ������õľ�ˮ��:%s\n", max->name);
	printf("������:%d\n", max->sellamount);
}

void find_lirun(Totaldata*head) {
	Totaldata*max = head;
	while (head != NULL) {
		if (head->profit > max->profit)
			max = head;
		head = head->next;
	}
	printf("��ǰ�������ľ�ˮ��:%s\n", max->name);
	printf("������:%d\n", max->sellamount);
}

void find_yali(Totaldata*head) {
	int sum = 0;
	while (head != NULL) {
		sum += head->purchseamount - head->sellamount;
	}
	if (500 - sum < 80) {//��������ݶ�500
		printf("��ǰ������\n");
		printf("���ռ����:%.2lf", sum / 500);
	}
	else {
		printf("��ǰ�����δ����\n");
		printf("���ռ����:%.2lf", sum / 500);
	}
}

void find(Totaldata*head) {//���ǵ��麯��
	printf("��������Ҫ���еĲ���\n");
	printf("1.��ѯ��ǰ������õľ�ˮ\n");
	printf("2.��ѯ��ǰ�����������ľ�ˮ\n");
	printf("3.��ѯ���ѹ��\n");
	int n;
	scanf("%d", &n);
	switch (n) {
	case 1:find_xiaoliang(head); break;
	case 2:find_lirun(head); break;
	case 3:find_yali(head); break;
	}
}