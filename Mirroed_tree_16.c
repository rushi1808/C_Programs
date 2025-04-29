#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int isMirror(Node* tree1, Node* tree2) {
    if (tree1 == NULL || tree2 == NULL)
        return tree1 == tree2; // Both should be NULL to be mirrors

    return (tree1->data == tree2->data) &&
           isMirror(tree1->left, tree2->right) &&
           isMirror(tree1->right, tree2->left);
}
int main() {
    Node* t1 = newNode(1);
    t1->left = newNode(2);
    t1->right = newNode(3);

    Node* t2 = newNode(1);
    t2->left = newNode(3);
    t2->right = newNode(2);

    if (isMirror(t1, t2))
        printf("The trees are mirrored.\n");
    else
        printf("The trees are NOT mirrored.\n");

    return 0;
}