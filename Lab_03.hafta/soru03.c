#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* findMiddle(Node* head) {
    // Liste boşsa NULL döndür
    if (head == NULL) {
        return NULL; 
    }

    //İki işaretçi de başlangıçta ilk düğümü gösterir
    Node* slow = head;
    Node* fast = head;

    // fast ile döngüyü kuruyoruz çünkü önden gidiyor.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      

        //next'inin next'i
        fast = fast->next->next; 
    }

    // fast sona ulaştığında slow ortadadır
    return slow; 
}


void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}


void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

int main() {
   
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));
    Node* n5 = (Node*)malloc(sizeof(Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = n4;
    n4->data = 40; n4->next = n5;
    n5->data = 50; n5->next = NULL;

    Node* head = n1;

    printf("Tek Sayida Eleman Testi\n");
    printList(head);
    Node* middleOdd = findMiddle(head);
    if (middleOdd != NULL) {
        printf("Ortadaki dugumun degeri: %d\n\n", middleOdd->data); 
    }

    Node* n6 = (Node*)malloc(sizeof(Node));
    n6->data = 60;
    n6->next = NULL;
    n5->next = n6; 

    printf("Cift Sayida Eleman Testi\n");
    printList(head);
    Node* middleEven = findMiddle(head);
    if (middleEven != NULL) {
        printf("Ortadaki dugumun degeri: %d\n\n", middleEven->data); 
    }

  
    clear(&head);
    if (head == NULL) {
        printf("Liste basariyla temizlendi.\n");
    }

    return 0;
   
}