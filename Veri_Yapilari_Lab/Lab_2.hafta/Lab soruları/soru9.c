#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* sonaEkle(struct Node* head, int yeni) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->data = yeni;
    yeniDugum->next = NULL; 
    
    struct Node* gezinme = head;
    while (gezinme->next != NULL) {
        gezinme = gezinme->next;
    }
    gezinme->next = yeniDugum;

    return head;
}

void listeyiYazdir(struct Node* head) {
    struct Node* gezinme = head;
    while (gezinme != NULL) {
        printf("%d\n", gezinme->data);
        gezinme = gezinme->next;
    }
}

int main() {
    struct Node *birinci = (struct Node*)malloc(sizeof(struct Node));
    struct Node *ikinci = (struct Node*)malloc(sizeof(struct Node));
    struct Node *ucuncu = (struct Node*)malloc(sizeof(struct Node));

    birinci->data = 10;
    birinci->next = ikinci;

    ikinci->data = 20;
    ikinci->next = ucuncu;

    ucuncu->data = 30;
    ucuncu->next = NULL;
   
    struct Node* head = birinci;

    printf("Onceki Liste:\n");
    listeyiYazdir(head);

    head = sonaEkle(head, 40);
    printf("Sona 40 eklendikten sonraki liste:\n");
    listeyiYazdir(head);

    free(birinci);     
    free(ikinci);       
    free(ucuncu);      
    //Sondakini silmek için
    free(ucuncu->next);


    return 0;
}