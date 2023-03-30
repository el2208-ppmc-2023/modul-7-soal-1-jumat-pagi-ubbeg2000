/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node* next;
};

int push(struct Node** top_node, int new_data) {
	struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*top_node);
	(*top_node) = new_node;
    return 0;
}

int pop(struct Node** top_node) {
	char top_data;
	struct Node* temp;
	temp = *top_node;
    top_data = temp->data;
    *top_node = temp->next;
    free(temp);
    return top_data; 
}

int main() {

    // input
	char s[100];
    printf("Masukkan string: ");
    scanf("%s", s);

	struct Node* stack = NULL;
	
	// do something...
	
	if (stack == NULL) {
		// printf("Semua kurung sesuai");
    } else {
        // printf("Ada kurung tidak sesuai");
    }

	return 0;
}
