#include <stdio.h>

//Main dışında global olarak tanımladım
    struct Node{
        int data;
        struct Node *next;
    };

int main(){
    struct Node deneme;

    deneme.data=10;
    deneme.next= NULL;

    printf("Node degeri: %d", deneme.data);

    return 0;
}
