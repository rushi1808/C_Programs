#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    struct Node* result = l1->data <= l2->data ? l1 : l2;
    result->next = l1->data <= l2->data ? 
                   mergeSorted(l1->next, l2) : 
                   mergeSorted(l1, l2->next);
    return result;
}

int main() {
    struct Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    printf("List 1: "); printList(l1);
    printf("List 2: "); printList(l2);
    printf("Merged: "); printList(mergeSorted(l1, l2));
    return 0;
}