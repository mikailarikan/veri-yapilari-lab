#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;             
    struct Node *left;    
    struct Node *right;   
} Node;

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        
        if (newNode == NULL) {
            printf("Bellek tahsisi basarisiz!\n");
            exit(1); 
        }
        
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Eşitlik durumunda bir şey yapma
    return root;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);        
        printf("%d ", root->data);  
        inorder(root->right);        
    }
}

int main() {
    Node* root = NULL; 
    
   
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};
    
    
    for (int i = 0; i < 7; i++) {
        root = insert(root, numbers[i]);
    }
    
    printf("Inorder: ");
    inorder(root); 
    printf("\n");
    
    return 0;
}