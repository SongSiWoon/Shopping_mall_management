#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Member.h"

int mcount = 0;
int check_member_number(Member **m) {
	while (1) {
		int n = 0, nn, i = 0, c = 0;
		printf("\t회원번호를 입력하시오 : ");
		scanf("%d", &nn);
		for (; i < mcount; i++) {
			if (nn == (*m+i)->key) { n++; c = i; }
		}
		if (n == 0) {
			system("cls");
			printf("\t회원번호가 잘못 입력 되었습니다.\n");
		}
		else if (n == 1) { 
			system("cls");
			printf("\t회원번호가 확인되었습니다.\n\t%s 회원님 반갑습니다~~\n", (*m + c)->name);
			return c; }
		else {printf("※error※"); exit(1);}
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
	else { printf("\t※파일이 존재하지 않습니다.※"); exit(1); }
}
void add_member(Member **m){
	mcount++;
	*m = (Member *)realloc(*m, mcount * sizeof(Member));
	printf("\t회원가입\n");
	printf("이름 : ");
	scanf("%s", (*m+(mcount-1))->name);
	printf("주소 : ");
	scanf("%s", (*m + (mcount-1))->ad);
	printf("회원번호(1~9 4자리) : ");
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
	printf("\t총 회원수 : %d\n", mcount);
	printf("\t총 매출 액 : %d\n", check_amount(m));
	printf("\tVIP : 회원 이름(%s) 이용 금액 : %d\n\n", (*m + check_VIP(m))->name, (*m + check_VIP(m))->amount);
}
void buy_member(Member **m, int m_num, int n) {
	(*m + m_num)->amount += n;
	printf("\t★구매완료★\n");
}
void print_member(Member **m) {
	for (int i = 0; i < mcount; i++) {
		printf("이름 : %3s / 주소 : %5s / 회원번호 : %4d / 구입금액 : %d\n", (*m + i)->name, (*m + i)->ad, (*m + i)->key, (*m + i)->amount);
	}
}