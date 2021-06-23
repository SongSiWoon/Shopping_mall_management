#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Product {
	char name[20];
	char size[5];
	int price;
}Product;

extern void init_product(Product **p, int size); // ���� ��ǰ �� ��ŭ ����ü �迭 ���� �Ҵ�
extern int pre_product_count(char* title); // ���Ͽ� ����Ǿ� �ִ� ��ǰ �� ���
extern void load_product(Product **p); // ������ ���� ����ü�� ����
extern void print_product(Product **p); // ��ǰ ���� ���
extern void save_product(Product **p); // Product����ü ������ ���Ͽ� ����
extern int buy_product(Product **p, int n); // ������ ��ǰ �ݾ� ��ȯ
extern void add_product(Product **p); // �޸� ���Ҵ� �� ����ü �ʱ�ȭ