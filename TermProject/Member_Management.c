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
		printf("\t\n��带 ���� ���ּ���\n1. ȸ�� 2. ��ȸ�� 3. ������ 4. ����");
		scanf("%d", &n);
		if(n == 1){ 
			while (1) {
				member_check = check_member_number(&mem);
				printf("\t\n1. ���� 2. ����");
				scanf("%d", &n);
				if (n == 1) {
					while (1) {
						print_product(&pd);
						printf("\t\n���� �� ��ǰ�� ��ȣ�� �Է��Ͻÿ�(����ȭ�� 0 �Է�) : ");
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
			printf("\t\n������ ��й�ȣ�� �Է��Ͻÿ� : ");
			scanf("%s", key);
			if (strcmp(key, Masterkey) == 0) {
				printf("\n\t1. ��ǰ �߰� 2. ȸ������ �� vip ���");
				scanf("%d", &n);
				if (n == 1) { add_product(&pd); }
				else if (n == 2) {
					print_admin_check(&mem);
					print_member(&mem);
				}
			}
			else printf("\t������ ���ѡ�\n");
		}
		else if (n == 4) {
			save_member(&mem);
			save_product(&pd);
			exit(1);}
		else printf("\t�ٽ� �������ּ���\n");
	}
	free(mem);

	return 0;
}