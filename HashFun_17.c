#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10 
 
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int key) {
    return key % TABLE_SIZE;
}
				//key-42 value=400
void insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    } 
    return -1;  // Key not found
}
void display() {
	int i;
    for ( i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("(%d -> %d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
    
}
int main() {
    insert(1, 100);
    insert(2, 200);
    insert(42, 400);  // Will collide with key 2 (42 % 10 = 2)
    insert(52, 400);
    insert(4, 300);
    printf("Hash Table:\n");
    display();
    int key = 42;
    int value = search(key);
    if (value != -1) {
        printf("Value for key %d is %d\n", key, value);
    } else {
        printf("Key %d not found!\n", key);
    }
    return 0;
}