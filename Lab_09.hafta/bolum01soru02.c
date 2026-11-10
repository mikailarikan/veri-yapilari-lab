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

// Sağa Rotasyon (LL ve LR durumları için)
struct Node* rotateRight(struct Node *x) {
    struct Node *y = x->left;    
    struct Node *T2 = y->right; 

    
    y->right = x;
    x->left = T2;

    return y; 
}

// Sola Rotasyon (RR ve RL durumları için)
struct Node* rotateLeft(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left; 

    y->left = x;
    x->right = T2;

    return y;
}

struct Node* insertAVL(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
    else 
        return node; 

    //Eklediysek kontrol
    int bf = balanceFactor(node);

    
    // LL (Sol-Sol) Durumu
    if (bf > 1 && data < node->left->data)
        return rotateRight(node);

    // RR (Sağ-Sağ) Durumu
    if (bf < -1 && data > node->right->data)
        return rotateLeft(node);

    // LR (Sol-Sağ) Durumu ve iki adım
    if (bf > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left); 
        return rotateRight(node);            
    }

    // RL (Sağ-Sol) Durumu ve iki adım
    if (bf < -1 && data < node->right->data) {
        node->right = rotateRight(node->right); 
        return rotateLeft(node);                
    }

    // Ağaç dengedeyse yapıyı bozmadan geri döndür
    return node;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void runTest(char* testName, int val1, int val2, int val3) {
    struct Node* root = NULL;
    root = insertAVL(root, val1);
    root = insertAVL(root, val2);
    root = insertAVL(root, val3);
    
    printf("%s Testi Kok degeri: %d\n", testName, root->data);
    printf("Preorder: ");
    preorder(root);
    printf("\n\n");
}

int main() {
    runTest("A (LL)", 30, 20, 10);
    runTest("B (RR)", 10, 20, 30);
    runTest("C (LR)", 30, 10, 20);
    runTest("D (RL)", 10, 30, 20);

    return 0;
}