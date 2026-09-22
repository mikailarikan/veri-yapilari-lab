#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    // 4 düğüm için bellekten yer ayırıyoruz
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

    printf("Lutfen aramak istediginiz sayiyi yaziniz\n");
    int aranan;
    bool bulundu=false;
    scanf("%d", &aranan);

    struct Node *gezinme= birinci;

    while(gezinme!=NULL)
    {
        if(gezinme->data==aranan){
        printf("Aradiginiz deger listede vardir");
        bulundu=true;
        break;
        }
        gezinme=gezinme->next;
    }

    if (bulundu==false)
    printf("Aradiginiz deger listede yoktur");


    free(birinci);
    free(ikinci);
    free(ucuncu);
    free(dorduncu);

    return 0;
}