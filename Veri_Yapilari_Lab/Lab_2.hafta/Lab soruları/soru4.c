#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node *birinci=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ikinci=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ucuncu=(struct Node*)malloc(sizeof(struct Node));

    birinci->data=10;
    birinci->next=ikinci;

    ikinci->data=20;
    ikinci->next=ucuncu;

    ucuncu->data=30;
    ucuncu->next=NULL;

    struct Node *gezinme=birinci;
    
    while(gezinme!=NULL){
        printf("%d\n",gezinme->data);
        gezinme=gezinme->next;
    }

    free(birinci);
    free(ikinci);
    free(ucuncu);

    return 0;
}