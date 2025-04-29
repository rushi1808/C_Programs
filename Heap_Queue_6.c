#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Max Heap structure
struct PriorityQueue {
    int arr[MAX_SIZE];
    int size;
};

// Swap helper function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down function
void heapify(struct PriorityQueue* pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->arr[left] > pq->arr[largest])
        largest = left;
    if (right < pq->size && pq->arr[right] > pq->arr[largest])
        largest = right;

    if (largest != i) {
        swap(&pq->arr[i], &pq->arr[largest]);
        heapify(pq, largest);
    }
}

// Insert into max heap
void insert(struct PriorityQueue* pq, int value) {
    pq->arr[pq->size++] = value;
    int i = pq->size - 1;
    while (i > 0 && pq->arr[(i-1)/2] < pq->arr[i]) {
        swap(&pq->arr[i], &pq->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract maximum element
int extractMax(struct PriorityQueue* pq) {
    if (pq->size <= 0) return -1;
    
    int max = pq->arr[0];
    pq->arr[0] = pq->arr[--pq->size];
    heapify(pq, 0);
    return max;
}

long long findProduct(int arr[], int n) {
    if (n < 3) return -1;

    struct PriorityQueue pq = {{0}, 0};
    
    // Build max heap with distinct elements
    for (int i = 0; i < n; i++) {
        int isDistinct = 1;
        for (int j = 0; j < pq.size; j++) {
            if (pq.arr[j] == arr[i]) {
                isDistinct = 0;
                break;
            }
        }
        if (isDistinct) insert(&pq, arr[i]);
    }

    if (pq.size < 3) return -1;

    // Get three largest elements
    int first = extractMax(&pq);
    int second = extractMax(&pq);
    int third = extractMax(&pq);

    return (long long)first * second * third;
}

int main() {
    int arr[] = {10, 5, 15, 20, 8, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    long long product = findProduct(arr, n);
    if (product != -1)
        printf("Product of three largest distinct elements: %lld\n", product);
    else
        printf("Not enough distinct elements\n");
    return 0;
}