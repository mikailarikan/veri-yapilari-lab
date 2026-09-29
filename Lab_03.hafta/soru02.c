#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertAt(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek yetersiz!\n");
        return;
    }

    newNode->data = value;

    //0 veya negatif pozisyona ekleme yapılıyorsa veya liste boşsa başa ekle
    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    //Araya veya sona ekleme
    Node* current = *head;
    int currentIndex = 0;

    // Eklenecek pozisyondan bir önceki düğüme (position - 1) gitmemiz gerekiyor.
    //Eğer liste biterse sona ekliyoruz zaten.
    while (current->next != NULL && currentIndex < position - 1) {
        current = current->next;
        currentIndex++;
    }

    //Uygun pozisyon bulununca yapılacak işlemler
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAt(Node** head, int position) {
    //Listenin boş olma durumu
    if (*head == NULL) {
        return; //
    }

    //Geçersiz pozisyon girilirse işlem yok
    if (position < 0) {
        return; 
    }

    //Silinecek düğüm başta olabilir
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next; 
        free(temp);
        return;
    }

    //Tek tek dolaşmak için current pointer'ı tanımladık
    Node* current = *head;
    int currentIndex = 0;

    while (current->next != NULL && currentIndex < position - 1) {
        current = current->next;
        currentIndex++;
    }

    // Eğer current->next=NULL ise index geçersizdir bizim liste eleman sayısını aşar
    if (current->next == NULL) {
        return;
    }

    //Pozisyonu bulduysak silme işlemi
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
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
    Node* head = NULL;

    printf("Listeye elemanlar ekleniyor\n");
    insertAt(&head, 10, 0);  
    insertAt(&head, 20, 1);   
    insertAt(&head, 30, 2);  
    insertAt(&head, 5, -5); 
    insertAt(&head, 50, 100); 
    insertAt(&head, 15, 2);  

    printList(head); 
    
    printf("Bastaki eleman silindi\n");
    deleteAt(&head, 0);
    printList(head);

    printf("3 indexli eleman silindi\n");
    deleteAt(&head, 3); 
    printList(head);

    printf("\nGecersiz 78.pozisyon silinmeye calisiliyor\n");
    deleteAt(&head, 78); 
    printList(head);

    clear(&head);
    return 0;
}