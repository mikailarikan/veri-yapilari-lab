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


int search(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    
    if (value == root->data) {
        return 1;
    }
    
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int findMin(Node* root) {
    // Sol çocuk NULL olana kadar sola doğru ilerle. En soldaki düğüm en küçük düğümdür.
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root->data;
}

int main() {
    Node* root = NULL; 
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};
    
    for (int i = 0; i < 7; i++) {
        root = insert(root, numbers[i]);
    }
    
    if (search(root, 30))
        printf("30 agacta bulundu.\n");
    else
        printf("30 agacta bulunamadi.\n");

    if (search(root, 90))
        printf("90 agacta bulundu.\n");
    else
        printf("90 agacta bulunamadi.\n");

    if (root != NULL)
        printf("En kucuk eleman: %d\n", findMin(root));
    
    return 0;
}