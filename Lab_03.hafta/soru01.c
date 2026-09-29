#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void addOrdered(Node** head, int value){
    Node* newNode=(Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
    printf("Bellek yetersiz, yer ayrilamadi!\n");
    return;
    }

    newNode->data=value;
    newNode->next=NULL;

    //Burada en küçük değer olduğunda ve içi boş liste için
    if (*head == NULL || value <= (*head)->data)
    {
        newNode->next=*head;
        *head=newNode;
        return;
    }

    //Listede baştan sona gezinmek için current adında yeni bir node pointer'ı
    Node* current=*head;

    //Burada aradaki ve sondaki değerler için (Doğru konumu bulana kadar ilerler)
    while(current->next != NULL && current->next->data < value){
        current=current->next;
    }
    
    //Artık doğru yeri bulduktan sonra yapılması gereken işlemler
    newNode->next=current->next;
    current->next=newNode;

}

void removeNode(Node** head, int value){
    //1) Zaten liste boş olabilir
    if (*head == NULL) {
        return;
    }

    //2) Silinecek eleman listenin başında olabilir
    if ((*head)->data == value) {
        Node* temp = *head;      
        *head = (*head)->next;   
        free(temp);              
        return;
    }

    //Silinecek eleman sonda ve arada ise yine dolaşmamız lazım.
    Node* current = *head;

    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    //Eğer aranan değeri bulduysak silme işlemi
    if (current->next != NULL) {
        Node* temp = current->next;       
        current->next = temp->next;       
        free(temp);                       
    }
}

int count(Node* head) {
    //Sayaç ve listede gezinmek için current tanımı
    int count= 0;
    Node* current = head; 

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printList(Node* head) {
    //Listede gezinmek için current tanımı
    Node* current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}


void clear(Node** head) {

    //Tek tek gezinmek için current ve sildiğimizde listeyi kaybetmemek için nextNode tanımı
    Node* current = *head;
    Node* nextNode;

    
    while (current != NULL) {
        nextNode = current->next; 

        //free ile serbest bırakıyoruz malloc ile aldığımız alanları
        free(current);            
        current = nextNode;       
    }
    
    *head = NULL;
}

int main() {
    Node* head = NULL; // Liste boş başlıyor

   
    addOrdered(&head, 23);
    addOrdered(&head, 11);
    addOrdered(&head, 5);
    addOrdered(&head, 9);
    addOrdered(&head, 6);
    addOrdered(&head, 4);
    addOrdered(&head, 12);
    addOrdered(&head, 24);

    printf("Sirali Liste:\n");
    printList(head); 

    printf("Eleman sayisi: %d\n", count(head));

    printf("11 ve 4 degerleri siliniyor\n");
    removeNode(&head, 11);
    removeNode(&head, 4);
    printList(head);

    printf("Liste temizleniyor\n");
    clear(&head);
    
    if (head == NULL) {
        printf("Liste basariyla bosaltildi. Eleman sayisi: %d\n", count(head));
    }

    return 0;
}