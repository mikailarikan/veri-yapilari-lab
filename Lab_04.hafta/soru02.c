#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

// Verilen fonksiyon imzaları
void pushWord(Word** top, char* text);
void popWord(Word** top);
void showWords(Word* top);
void printBottomUp(Word* top);//recursion ile listeyi yazdırmak için

int main() {
    Word* stackTop = NULL;
    char command[20];
    char text[50];

    while (1) {
        scanf("%19s", command);

        //switch-case'lerde yalnızca int veya char veri yapısındaki elemanların kontrolü yapıldığı için burada if/else şeklinde kontrol sağladım

        if (strcmp(command, "add") == 0) {//strcmp eşit iki değeri kontrol ettiğinde 0 döndürdüğü için 0'a eşit olup olmamasını kontrol ettim

            scanf(" %49[^\n]", text); //Regex pattern'i kullanarak entere kadar olan tüm karakterleri aldık
            pushWord(&stackTop, text);
        } 
        else if (strcmp(command, "undo") == 0) {
            popWord(&stackTop);
        } 
        else if (strcmp(command, "show") == 0) {
            showWords(stackTop);
        } 
        else if (strcmp(command, "exit") == 0) {
            break;
        } 
        else {
            printf("Gecersiz komut!\n");
        }
    }

    return 0;
}


void pushWord(Word** top, char* text) {
    Word* newNode = (Word*)malloc(sizeof(Word));
    strcpy(newNode->text, text);
    
    newNode->next = *top;
    *top = newNode;
}


void popWord(Word** top) {
    if (*top == NULL) {
        return;
    }
    
    Word* temp = *top;
    *top = (*top)->next;
    free(temp);
}


void showWords(Word* top) {
    if (top == NULL) {
        printf("-> (Metin bos)\n");
        return;
    }
    
    printf("-> ");
    printBottomUp(top);
    printf("\n");
}

// Stack son giren ilk çıkar yapısında oluduğu için sıralı yazdırmak amacıyla recursion kullanıyoruz
void printBottomUp(Word* top) {
    if (top == NULL) {
        return;
    }
    printBottomUp(top->next); // Önce en dibe in
    printf("%s ", top->text); // Yukarı çıkarken yazdır
}