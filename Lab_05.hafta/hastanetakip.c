#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {
    int id;
    char name[50];
    char status[20];
    struct Patient* next;
} Patient;

// Çok fazla kez  fonskiyonlarda kullanacağımız için global alanda tanımladım ki sürekli parametre aldırmakla uğraşmayalım
Patient* queueFront = NULL;
Patient* queueRear = NULL;
Patient* stackTop = NULL;
Patient* historyHead = NULL;
Patient* historyTail = NULL;


void enqueue(int id, const char* name) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Bellek tahsis hatasi!\n");
        return;
    }
    newPatient->id = id;
    strcpy(newPatient->name, name);
    strcpy(newPatient->status, "bekliyor");
    newPatient->next = NULL;

    if (queueRear == NULL) {
        queueFront = queueRear = newPatient;
    } else {
        queueRear->next = newPatient;
        queueRear = newPatient;
    }
}

Patient* dequeue() {
    if (queueFront == NULL) {
        return NULL; 
    }
    Patient* temp = queueFront;
    queueFront = queueFront->next;
    
    if (queueFront == NULL) {
        queueRear = NULL;
    }
    temp->next = NULL; 
    return temp;
}


void push(Patient* p) {
    if (p == NULL) return;
    strcpy(p->status, "muayenede");
    p->next = stackTop;
    stackTop = p;
}

Patient* pop() {
    if (stackTop == NULL) {
        return NULL; 
    }
    Patient* temp = stackTop;
    stackTop = stackTop->next;
    temp->next = NULL;
    return temp;
}


void addToHistory(Patient* p) {
    if (p == NULL) return;
    strcpy(p->status, "tamamlandi");
    p->next = NULL;

    if (historyHead == NULL) {
        historyHead = historyTail = p;
    } else {
        historyTail->next = p;
        historyTail = p;
    }
}


void printQueue() {
    printf("\n--- Bekleyen Hastalar ---\n");
    if (queueFront == NULL) {
        printf("Hasta yok.\n");
    } else {
        Patient* temp = queueFront;
        while (temp != NULL) {
            printf("Hasta ID: %d, Isim: %s, Durum: %s\n", temp->id, temp->name, temp->status);
            temp = temp->next;
        }
    }
}

void printStack() {
    printf("\n--- Muayene Odasindaki Hastalar ---\n");
    if (stackTop == NULL) {
        printf("Hasta yok.\n");
    } else {
        Patient* temp = stackTop;
        while (temp != NULL) {
            printf("Hasta ID: %d, Isim: %s, Durum: %s\n", temp->id, temp->name, temp->status);
            temp = temp->next;
        }
    }
}

void printHistory() {
    printf("\n--- Tamamlanan Hastalar ---\n");
    if (historyHead == NULL) {
        printf("Hasta yok.\n");
    } else {
        Patient* temp = historyHead;
        while (temp != NULL) {
            printf("Hasta ID: %d, Isim: %s, Durum: %s\n", temp->id, temp->name, temp->status);
            temp = temp->next;
        }
    }
}

void printAll() {
    printQueue();
    printStack();
    printHistory();
}

int main() {
   
    enqueue(1, "Ahmet");
    enqueue(2, "Mehmet");
    enqueue(3, "Ayse");

    printf("=== Baslangic Durumu ===\n");
    printAll();
    printf("\n");

    printf("=== Hasta Aktarim Islemleri ===\n");
    
    Patient* p1 = dequeue();
    if (p1 != NULL) {
        printf("Hasta ID: %d (%s) kuyruktan alindi, muayeneye eklendi.\n", p1->id, p1->name);
        push(p1);
    }
    
    Patient* c1 = pop();
    if (c1 != NULL) {
        printf("Hasta ID: %d (%s) muayeneden cikarildi, gecmise eklendi.\n", c1->id, c1->name);
        addToHistory(c1);
    }

    Patient* p2 = dequeue();
    if (p2 != NULL) {
        printf("Hasta ID: %d (%s) kuyruktan alindi, muayeneye eklendi.\n", p2->id, p2->name);
        push(p2);
    }
    
    Patient* c2 = pop();
    if (c2 != NULL) {
        printf("Hasta ID: %d (%s) muayeneden cikarildi, gecmise eklendi.\n", c2->id, c2->name);
        addToHistory(c2);
    }

    printf("Hasta ID: 3 (Ayse) bekleme kuyrugunda birakildi.\n");

    printf("\n=== Tum Islemler Sonrasi ===\n");
    printAll();


    //Bellek temizliği
    Patient* current = historyHead;
    while(current != NULL) {
        Patient* next = current->next;
        free(current);
        current = next;
    }
    current = queueFront;
    while(current != NULL) {
        Patient* next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}