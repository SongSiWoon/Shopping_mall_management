#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Member.h"

int mcount = 0;
int check_member_number(Member **m) {
	while (1) {
		int n = 0, nn, i = 0, c = 0;
		printf("\tȸ����ȣ�� �Է��Ͻÿ� : ");
		scanf("%d", &nn);
		for (; i < mcount; i++) {
			if (nn == (*m+i)->key) { n++; c = i; }
		}
		if (n == 0) {
			system("cls");
			printf("\tȸ����ȣ�� �߸� �Է� �Ǿ����ϴ�.\n");
		}
		else if (n == 1) { 
			system("cls");
			printf("\tȸ����ȣ�� Ȯ�εǾ����ϴ�.\n\t%s ȸ���� �ݰ����ϴ�~~\n", (*m + c)->name);
			return c; }
		else {printf("��error��"); exit(1);}
	}
}
void load_member(Member **m) {
	FILE *f;
	f = fopen("MemberData.txt", "r");
	if (f != NULL) {
		for (int i = 0; i < mcount; i++) {
			fscanf(f, "%s %s %d %d", (*m+i)->name, (*m + i)->ad, &(*m + i)->key, &(*m + i)->amount);
		}
		fclose(f);
	}
	else { printf("\t�������� �������� �ʽ��ϴ�.��"); exit(1); }
}
void add_member(Member **m){
	mcount++;
	*m = (Member *)realloc(*m, mcount * sizeof(Member));
	printf("\tȸ������\n");
	printf("�̸� : ");
	scanf("%s", (*m+(mcount-1))->name);
	printf("�ּ� : ");
	scanf("%s", (*m + (mcount-1))->ad);
	printf("ȸ����ȣ(1~9 4�ڸ�) : ");
	scanf("%d", &(*m + (mcount-1))->key);
	(*m + (mcount-1))->amount = 0;
}
int pre_member_count(char* title) {
	int line = 0;
	char c;
	FILE *f;
	f = fopen("MemberData.txt", "r");
	while ((c = fgetc(f)) != EOF) {
		if (c == '\n') line++;
	}
	fclose(f);
	mcount = line + 1;
	return line+1;
}
void init_member(Member **m, int size) {
	*m = (Member *)malloc(sizeof(Member)*size);
}
void save_member(Member **m) {
	FILE *f;
	f = fopen("MemberData.txt", "w");
	fprintf(f, "%s %s %d %d", (*m)->name, (*m)->ad, (*m)->key, (*m)->amount);
	for (int i = 1; i < mcount; i++) {
		fprintf(f, "\n%s %s %d %d", (*m + i)->name, (*m + i)->ad, (*m + i)->key, (*m + i)->amount);
	}
	fclose(f);
}
int check_amount(Member **m) {
	int amount = 0;
	for (int i = 0; i < mcount; i++) {
		amount += (*m + i)->amount;
	}
	return amount;
}
int check_VIP(Member **m) {
	int vip = (*m)->amount;
	int vip_num=0;
	for (int i = 0; i < mcount; i++) {
		if ((*m + i)->amount > vip) { 
			vip = (*m + i)->amount;
			vip_num = i;
		}
	}
	return vip_num;
}
void print_admin_check(Member **m) {
	printf("\t�� ȸ���� : %d\n", mcount);
	printf("\t�� ���� �� : %d\n", check_amount(m));
	printf("\tVIP : ȸ�� �̸�(%s) �̿� �ݾ� : %d\n\n", (*m + check_VIP(m))->name, (*m + check_VIP(m))->amount);
}
void buy_member(Member **m, int m_num, int n) {
	(*m + m_num)->amount += n;
	printf("\t�ڱ��ſϷ��\n");
}
void print_member(Member **m) {
	for (int i = 0; i < mcount; i++) {
		printf("�̸� : %3s / �ּ� : %5s / ȸ����ȣ : %4d / ���Աݾ� : %d\n", (*m + i)->name, (*m + i)->ad, (*m + i)->key, (*m + i)->amount);
	}
}