#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include "Member.h"
#include "Product.h"
#define Masterkey "a#123"

int main(void) {
	int member_check;
	Member *mem;
	Product *pd;
	init_member(&mem, pre_member_count("MemberData.txt"));
	load_member(&mem);
	init_product(&pd, pre_product_count("ProductData.txt"));
	load_product(&pd);
	while (1) {
		int n = 0;
		printf("\t\n모드를 선택 해주세요\n1. 회원 2. 비회원 3. 관리자 4. 종료");
		scanf("%d", &n);
		if(n == 1){ 
			while (1) {
				member_check = check_member_number(&mem);
				printf("\t\n1. 쇼핑 2. 종료");
				scanf("%d", &n);
				if (n == 1) {
					while (1) {
						print_product(&pd);
						printf("\t\n구매 할 상품의 번호를 입력하시오(이전화면 0 입력) : ");
						scanf("%d", &n);
						if (n == 0) break;
						else {
							buy_member(&mem, member_check, buy_product(&pd, n));
							break;
						}
					}
				}
				else break;
			}
		}
		else if (n == 2) {add_member(&mem);}
		else if (n == 3) {
			char key[10];
			printf("\t\n관리자 비밀번호를 입력하시오 : ");
			scanf("%s", key);
			if (strcmp(key, Masterkey) == 0) {
				printf("\n\t1. 상품 추가 2. 회원정보 및 vip 출력");
				scanf("%d", &n);
				if (n == 1) { add_product(&pd); }
				else if (n == 2) {
					print_admin_check(&mem);
					print_member(&mem);
				}
			}
			else printf("\t※접근 제한※\n");
		}
		else if (n == 4) {
			save_member(&mem);
			save_product(&pd);
			exit(1);}
		else printf("\t다시 선택해주세요\n");
	}
	free(mem);

	return 0;
}