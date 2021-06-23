#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Member {
	char name[10];
	char ad[10];
	int key;
	int amount;
}Member;

extern int check_member_number(Member **m); // �Է��� ȸ����ȣ�� ��ġ�ϴ� ȸ�� �ε��� ã��
extern void load_member(Member **m); // ������ ������ ����ü�� ����
extern void add_member(Member **m); // �޸� ���Ҵ� �� ���ο� ����ü �ʱ�ȭ
extern int pre_member_count(char* title); // ���Ͽ� ����Ǿ��ִ� ȸ���� ���
extern void init_member(Member **m, int size); // ���� ȸ������ŭ ����ü�迭 ���� �Ҵ�
extern void save_member(Member **m); // Member����ü ������ ���Ͽ� ����
extern int check_amount(Member **m); // ��ü �Ǹž� ���
extern int check_VIP(Member **m); // ���� ���� ���� ���� ȸ�� �ε��� ã��
extern void print_admin_check(Member **m); // ȸ������, �� �Ǹž�, vip���
extern void buy_member(Member **m, int m_num, int n); // ������ ��ǰ �ݾ� �ش� ȸ�� amount�� ����
extern void print_member(Member **m); //ȸ�� ���� ���