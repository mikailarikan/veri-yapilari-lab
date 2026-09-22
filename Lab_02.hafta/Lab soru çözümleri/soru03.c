#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node birinci;
    struct Node ikinci;
    struct Node ucuncu;

    birinci.data=10;
    birinci.next=&ikinci;

    ikinci.data=20;
    ikinci.next=&ucuncu;

    ucuncu.data=30;
    ucuncu.next= NULL;

    //Şimdi gezinmek için pointer tanımlayacağım ve ilk baştaki node'un adresini işaret edecek.

    struct Node *gezinme=&birinci;

    //Sürekli dolaşırken gezinme pointerının gösterdiği yeri değiştireceğim NULL olursa sona gelmiş demektir.
    while(gezinme!=NULL)
    {
        printf("%d\n",gezinme->data);
        gezinme= gezinme->next;
    }
    
    return 0;
}