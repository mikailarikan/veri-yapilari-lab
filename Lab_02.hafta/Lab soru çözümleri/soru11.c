#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertBeginning(struct Node* head, int value) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->data = value;
    yeniDugum->next = head;
    return yeniDugum;
}

void display(struct Node* head) {
    struct Node* gezinme = head;
    while (gezinme != NULL) {
        printf("%d\n", gezinme->data);
        gezinme = gezinme->next;
    }
}

void search(struct Node* head, int aranan) {
    struct Node* gezinme = head;
    int bulundu = 0;

    while (gezinme != NULL) {
        if (gezinme->data == aranan) {
            bulundu = 1;
            break;
        }
        gezinme = gezinme->next;
    }

    if (bulundu) {
        printf("%d degeri listede bulundu.\n", aranan);
    } else {
        printf("%d degeri listede bulunamadi.\n", aranan);
    }
}

int main() {
    struct Node* head = NULL;

    head = insertBeginning(head, 43);
    head = insertBeginning(head, 56);
    head = insertBeginning(head, 100);

    display(head);

    search(head, 43);
    search(head,95);

    struct Node* temp;

    //efektif free yöntemi
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}