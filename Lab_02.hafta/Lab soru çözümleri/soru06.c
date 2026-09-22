#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
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

    int sum=0;

      struct Node *gezinme = birinci; 

    while (gezinme != NULL) {
        sum+=gezinme->data;                
        gezinme = gezinme->next;
    }

    printf("Toplam deger: %d",sum);

    free(birinci);
    free(ikinci);
    free(ucuncu);
    free(dorduncu);

    return 0;
}