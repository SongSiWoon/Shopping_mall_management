#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Product.h"

int pcount = 0;

void init_product(Product **p, int size) {
	*p = (Product *)malloc(sizeof(Product)*size);
}
int pre_product_count(char* title) {
	int line = 0;
	char c;
	FILE *f;
	f = fopen("ProductData.txt", "r");
	while ((c = fgetc(f)) != EOF) {
		if (c == '\n') line++;
	}
	fclose(f);
	pcount = line + 1;
	return line + 1;
}
void load_product(Product **p) {
	FILE *f;
	f = fopen("ProductData.txt", "r");
	if (f != NULL) {
		for (int i = 0; i < pcount; i++) {
			fscanf(f, "%s %s %d", (*p + i)->name, (*p + i)->size, &(*p + i)->price);
		}
		fclose(f);
	}
	else { printf("\t※파일이 존재하지 않습니다.※"); exit(1); }
}
void print_product(Product **p) {
	system("cls");
	for (int i = 0; i < pcount; i++) {
		printf("%d. 이름: %10s 사이즈: %3s 가격: %d\n", i + 1, (*p + i)->name, (*p + i)->size, (*p + i)->price);
	}
}
void save_product(Product **p) {
	FILE *f;
	f = fopen("ProductData.txt", "w");
	fprintf(f, "%s %s %d", (*p)->name, (*p)->size, (*p)->price);
	for (int i = 1; i < pcount; i++) {
		fprintf(f, "\n%s %s %d", (*p + i)->name, (*p + i)->size, (*p + i)->price);
	}
	fclose(f);
}
int buy_product(Product **p, int n) {
	if (n > pcount + 1) {printf("\t다시 입력하시오"); return 0; }
	else return (*p + (n-1))->price;
}
void add_product(Product **p) {
	pcount++;
	*p = (Product *)realloc(*p, pcount * sizeof(Product));
	printf("\t상품 추가\n");
	printf("이름 : ");
	scanf("%s", (*p + (pcount - 1))->name);
	printf("사이즈 : ");
	scanf("%s", (*p + (pcount - 1))->size);
	printf("가격 : ");
	scanf("%d", &(*p + (pcount - 1))->price);
}