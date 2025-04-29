#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key, value;
    struct Node* next;
};

struct Node* table[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int idx = hash(key);
    struct Node* node = malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = table[idx];
    table[idx] = node;
}

int search(int key) {
    int idx = hash(key);
    struct Node* temp = table[idx];
    while (temp) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }
    return -1;
}

void delete(int key) {
    int idx = hash(key);
    struct Node *temp = table[idx], *prev = NULL;
    while (temp) {
        if (temp->key == key) {
            if (prev) prev->next = temp->next;
            else table[idx] = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = table[i];
        while (temp) {
            printf("(%d->%d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    insert(1, 100);
    insert(2, 200);
    insert(12, 300);
    insert(22, 400);
    
    printf("Hash Table:\n");
    display();
    
    printf("\nSearch 2: %d\n", search(2));
    delete(12);
    printf("\nAfter deleting 12:\n");
    display();
    return 0;
}