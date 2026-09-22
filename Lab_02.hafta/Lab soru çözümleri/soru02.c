#include <stdio.h>

struct Node{
    int deger;
    struct Node *next;
};

int main(){
    struct Node birinci;
    struct Node ikinci;

    birinci.deger=10;
    birinci.next=&ikinci;

    ikinci.deger=20;
    ikinci.next=NULL;
    printf("1.Node degeri: %d\n",birinci.deger);

    //Pointerlarda structun verilerine -> ile erişebiliyorsun
    printf("2.Node degeri: %d",birinci.next->deger);
    
    return 0;
}