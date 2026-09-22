#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* degerSil(struct Node* head, int silinecekDeger) {
    
    if (head->data == silinecekDeger) {
        //ileride free ile serbest bırakmak için temp ile head'i aynı yeri gösterttirdik
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* gezinme = head;
    while (gezinme->next != NULL && gezinme->next->data != silinecekDeger) {
        gezinme = gezinme->next;
    }

    if (gezinme->next == NULL) {
        return head;
    }

    struct Node* silinecekDugum = gezinme->next;
    gezinme->next = silinecekDugum->next;
    
    free(silinecekDugum);

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
    struct Node *dorduncu = (struct Node*)malloc(sizeof(struct Node));

    birinci->data = 10;
    birinci->next = ikinci;

    ikinci->data = 20;
    ikinci->next = ucuncu;

    ucuncu->data = 30;
    ucuncu->next = dorduncu;

    dorduncu->data = 40;
    dorduncu->next = NULL;

    struct Node* head = birinci;

    printf("Silmeden once:\n");
    listeyiYazdir(head);

    head = degerSil(head, 30);

    printf("30 silindikten sonra:\n");
    listeyiYazdir(head);

    //30'u zaten fonksiyonda free'ledik
    free(birinci); // 10
    free(ikinci);  // 20
    free(dorduncu);// 40

    return 0;
}