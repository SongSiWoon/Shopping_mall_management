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

extern int check_member_number(Member **m); // 입력한 회원번호랑 일치하는 회원 인덱스 찾기
extern void load_member(Member **m); // 파일의 내용을 구조체에 저장
extern void add_member(Member **m); // 메모리 재할당 후 새로운 구조체 초기화
extern int pre_member_count(char* title); // 파일에 저장되어있는 회원수 계산
extern void init_member(Member **m, int size); // 현재 회원수만큼 구조체배열 동적 할당
extern void save_member(Member **m); // Member구조체 데이터 파일에 저장
extern int check_amount(Member **m); // 전체 판매액 계산
extern int check_VIP(Member **m); // 구매 액이 가장 많은 회원 인덱스 찾기
extern void print_admin_check(Member **m); // 회원정보, 총 판매액, vip출력
extern void buy_member(Member **m, int m_num, int n); // 구매한 상품 금액 해당 회원 amount에 적용
extern void print_member(Member **m); //회원 정보 출력