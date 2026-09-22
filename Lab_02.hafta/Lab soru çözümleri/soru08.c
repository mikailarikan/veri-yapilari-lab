#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* basaEkle(struct Node* head, int eklenecekDeger) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = eklenecekDeger;
    
    //önceki head'i gösterecek
    newNode->next = head;
    
    //Geri döndüğünde yeni head olacak
    return newNode;
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

    head = basaEkle(head, 5);

    printf("Basa 5 eklendikten sonraki liste:\n");
    listeyiYazdir(head);

    free(head);         
    free(birinci);      
    free(ikinci);       
    free(ucuncu);       

    return 0;
}