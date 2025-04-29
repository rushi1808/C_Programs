#include <stdio.h>
#include <stdlib.h>

// Structure for HashMap Node
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

#define TABLE_SIZE 100

// Hash function
int hashFunction(int key) {
    return abs(key) % TABLE_SIZE;
}


void insert(HashNode* table[], int key, int value) {
    int hashIndex = hashFunction(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[hashIndex];
    table[hashIndex] = newNode;
}


int search(HashNode* table[], int key) {
    int hashIndex = hashFunction(key);
    HashNode* node = table[hashIndex];
    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Not found
}


void twoSum(int arr[], int n, int target) {
    HashNode* hashTable[TABLE_SIZE] = {NULL};
    int i;
    for ( i = 0; i < n; i++) {
        int complement = target - arr[i];
        int index = search(hashTable, complement);
        if (index != -1) {
            printf("Pair found at indices: %d and %d\n", index, i);
            return;
        }
        insert(hashTable, arr[i], i);
    }
    printf("No pair found\n");
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    twoSum(arr, n, target);
    
    return 0;
}