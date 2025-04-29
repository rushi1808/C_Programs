#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int isBSTcheck(Node* root, int min, int max) { 
    if (root == NULL) {
        return 1;
}
    if (root->data <= min || root->data >= max) {
        return 0;
    }

    int leftIsBST = isBSTcheck(root->left, min, root->data);
    int rightIsBST = isBSTcheck(root->right, root->data, max);
return leftIsBST && rightIsBST;
}


int isValidBST(Node* root) {
    return isBSTcheck(root, INT_MIN, INT_MAX);
}


int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);
   

    if (isValidBST(root)) {
        printf("The tree is a valid BST.\n");
    } else {
        printf("The tree is NOT a valid BST.\n");
    }

    return 0;
}