#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;


 Node* createNode(int data) {
     Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void preOrder( Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); 
        preOrder(root->left);     
        preOrder(root->right);    
    }
}


void inOrder( Node* root) {
    if (root != NULL) {
        inOrder(root->left);      
        printf("%d ", root->data); 
        inOrder(root->right);     
    }
}


void postOrder( Node* root) {
    if (root != NULL) {
        postOrder(root->left);    
        postOrder(root->right);   
        printf("%d ", root->data); 
    }
}


int main() {
    // Creating a sample tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
     Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Pre-Order Traversal:\n");
    preOrder(root);
    printf("\nIn-Order Traversal:\n");
    inOrder(root);
    printf("\nPost-Order Traversal:\n");
    postOrder(root);

    return 0;
}