/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

// deklarasi struktur node (bagian dari stack)
struct Node {
	char data;
	struct Node* next;
};

// prosedur: push stack
void push(struct Node** top_node, int new_data) {
	struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*top_node);

	(*top_node) = new_node;
}

// fungsi: pop stack (perhatikan bahwa ia bisa return nilai)
int pop(struct Node** top_node) {
	char top_data;
	struct Node* temp;

	temp = *top_node;
    top_data = temp->data;
    *top_node = temp->next;

    free(temp);

    return top_data; // kembalikan node paling atas sebelum dilakukan pop
}

int kiriKananSesuai(char kiri, char kanan) {
	if (kiri == '(' && kanan == ')') {
		return 1;
    } else if (kiri == '{' && kanan == '}') {
		return 1;
    } else if (kiri == '[' && kanan == ']') {
		return 1;
    } else {
		return 0;
    }
}

int main() {

    // input
	char s[100];
    printf("Masukkan string: ");
    scanf("%s", &s);

    // inisialisasi
	struct Node* stack = NULL;
    int i = 0; // iterator untuk parsing string
    int belumFix = 1; // kalau belumFix sudah = 0, berarti jawabannya sudah fix (tidak perlu kompuasi lebih lanjut)

    // baca per karakter, selama masih ada yang bisa dibaca dan belum fix jawabannya
	while (s[i] && belumFix) {

        // kasus 1: ketemu buka kurung
		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
			push(&stack, s[i]);

        // kasus 2: ketemu tutup kurung
		if (s[i] == '}' || s[i] == ')' || s[i] == ']') {

			if (stack == NULL) {
				belumFix = 0;
            }
            
            if (kiriKananSesuai(pop(&stack), s[i]) == 0) {
				belumFix = 0;
            }
		}

        // karakter berikutnya
		i++;
	}
    
    // stack kosong
	if (stack == NULL) {
		printf("Semua kurung sesuai");

    // stack tidak kosong
    } else {
        printf("Ada kurung tidak sesuai");
    }
	return 0;
}
