#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int searchTreasure(Node* root, int target) {

    if (root == NULL) {
        return 0;
    }

    //Hangi dügümü ziyaret ettim
    printf("-> Ziyaret edilen dugum: %d\n", root->data);

    if (root->data == target) {
        return 1;
    }

    // Rekürsif bir şekilde aramaya devam
    if (target < root->data) {
        return searchTreasure(root->left, target);
    } else {
        return searchTreasure(root->right, target);
    }
}

int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {
    Node* root = NULL;
    
    int treasures[] = {56, 48, 72, 37, 51, 60, 63, 19};
    int n = sizeof(treasures) / sizeof(treasures[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, treasures[i]);
    }

    int guess;
    printf("=== HAZINE AGACI OYUNU ===\n");
    printf("Aramak istediginiz hazine degerini girin: ");
    scanf("%d", &guess);

    printf("\nArama basliyor...\n");
    
    if (searchTreasure(root, guess)) {
        printf("\nSonuc: Hazine bulundu!\n");
    } else {
        printf("\nSonuc: Hazine bulunamadi!\n");
    }

    printf("\nHazineyi bulmak icin en kotu durumda gereken adim sayisi (Agac Yuksekligi): %d\n", treeHeight(root));

    return 0;
}