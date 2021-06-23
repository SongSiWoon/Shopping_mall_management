#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Product {
	char name[20];
	char size[5];
	int price;
}Product;

extern void init_product(Product **p, int size); // 현재 상품 수 만큼 구조체 배열 동적 할당
extern int pre_product_count(char* title); // 파일에 저장되어 있는 상품 수 계산
extern void load_product(Product **p); // 파일의 내용 구조체에 저장
extern void print_product(Product **p); // 상품 정보 출력
extern void save_product(Product **p); // Product구조체 데이터 파일에 저장
extern int buy_product(Product **p, int n); // 선택한 상품 금액 반환
extern void add_product(Product **p); // 메모리 재할당 후 구조체 초기화