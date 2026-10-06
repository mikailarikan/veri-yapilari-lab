#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;


typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;

void enqueuePrintJob(Queue* q, char* fileName);
void processNextJob(Queue* q);
void showQueue(Queue q);

int main() {
    Queue printerQueue;
    printerQueue.front = NULL;
    printerQueue.rear = NULL;

    int choice;
    char fileName[50];

    while (1) {
        printf("\n --YAZICI KUYRUK SISTEMI-- \n");
        printf("1) Yeni dosya ekle\n"); 
        printf("2) Yazdir\n");          
        printf("3) Kuyrugu goster\n");  
        printf("0) Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Dosya adi: ");
                scanf(" %49[^\n]", fileName);
                enqueuePrintJob(&printerQueue, fileName);
                break;

            case 2:
                processNextJob(&printerQueue);
                break;

            case 3:
                showQueue(printerQueue);
                break;

            case 0:
                printf("Sistemden cikiliyor...\n");
                return 0;

            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
                break;
        }
    }

    return 0;
}

void enqueuePrintJob(Queue* q, char* fileName) {
    PrintJob* newJob = (PrintJob*)malloc(sizeof(PrintJob));
    strcpy(newJob->fileName, fileName);
    newJob->next = NULL;

    // Kuyruk tamamen boşsa ilk eleman hem front hem rear olur
    if (q->rear == NULL) {
        q->front = newJob;
        q->rear = newJob;
    } else {
        q->rear->next = newJob;
        q->rear = newJob;
    }

    printf("'%s' kuyruga eklendi.\n", fileName);
}


void processNextJob(Queue* q) {
    if (q->front == NULL) {
        printf("Kuyruk bos! Yazdirilacak dosya yok.\n");
        return;
    }

    PrintJob* temp = q->front;
    printf("Yazdiriliyor: %s\n", temp->fileName);

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}


void showQueue(Queue q) {
    if (q.front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }

    printf("\n--- Bekleyen Yazdirma Kuyrugu ---\n");
    PrintJob* current = q.front;
    int index = 1;

    while (current != NULL) {
        printf("%d. %s\n", index++, current->fileName); //post increment yapısı sayesinde önce index yazdırılacak sonra arttırılacak
        current = current->next;
    }
}