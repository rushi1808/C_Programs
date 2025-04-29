#include <stdio.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

CircularQueue init() {
    CircularQueue q = {-1, -1};
    return q;
}

int isFull(CircularQueue q) {
    return q.front == (q.rear + 1) % SIZE;
}

int isEmpty(CircularQueue q) {
    return q.front == -1;
}

CircularQueue enqueue(CircularQueue q, int value) {
    if (isFull(q)) return q;
    if (q.front == -1) q.front = 0;
    q.rear = (q.rear + 1) % SIZE;
    q.items[q.rear] = value;
    return q;
}

CircularQueue dequeue(CircularQueue q) {
    if (isEmpty(q)) return q;
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front = (q.front + 1) % SIZE;
    }
    return q;
}

int front(CircularQueue q) {
    return isEmpty(q) ? -1 : q.items[q.front];
}

int main() {
    CircularQueue q = init();
    q = enqueue(q, 10);
    q = enqueue(q, 20);
    q = enqueue(q, 30);
    q = enqueue(q, 40);
    q = enqueue(q, 50);
    q = enqueue(q, 60); // Full
    printf("Front: %d\n", front(q));
    q = dequeue(q);
    q = enqueue(q, 60); // Works now
    printf("Front: %d\n", front(q));
    return 0;
}