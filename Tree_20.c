#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    int i;
    for ( i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode *root, const char *word) {
    while (*word) {
        int index = *word - 'a';
        if (!root->children[index])
            root->children[index] = createNode();
        root = root->children[index];
        word++;
    }
    root->isEndOfWord = true;
}

bool search(TrieNode *root, const char *word) {
    while (*word) {
        int index = *word - 'a';
        if (!root->children[index])
            return false;
        root = root->children[index];
        word++;
    }
    return root->isEndOfWord;
}

int main() {
    TrieNode *root = createNode();
    insert(root, "hello");
    insert(root, "world");
    printf("Search hello: %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search world: %s\n", search(root, "world") ? "Found" : "Not Found");
    printf("Search bye: %s\n", search(root, "bye") ? "Found" : "Not Found");
    return 0;
}