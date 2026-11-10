#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    // Eğer düğüm yoksa boyu 0'dır
    if (node == NULL)
        return 0;
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return 1 + max(leftHeight, rightHeight);
}

int balanceFactor(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* rotateLeft(struct Node *x) {
    struct Node *y = x->right;   
    struct Node *T2 = y->left;   

    y->left = x;       
    x->right = T2;     
    
   return y; 
}

struct Node* insertBST(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertBST(node->left, data);
    else if (data > node->data)
        node->right = insertBST(node->right, data);
    else 
        return node;

    return node;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insertBST(root, 10);
    printf("10 eklendi. BF(kok)=%d\n", balanceFactor(root));

    root = insertBST(root, 20);
    printf("20 eklendi. BF(kok)=%d\n", balanceFactor(root));

    root = insertBST(root, 30);
    printf("30 eklendi. BF(kok)=%d\n", balanceFactor(root));

    if (balanceFactor(root) < -1) { 
        printf("RR dengesizligi: Sol rotasyon!\n");
        root = rotateLeft(root);
    }

    printf("Kok: %d\n", root->data);
    
    printf("Inorder: ");
    inorder(root);
    
    printf("\nPreorder: ");
    preorder(root);
    printf("\n");

    return 0;
}