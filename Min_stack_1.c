#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *stack;     // Main stack
    int *min;       // Auxiliary stack for minimum elements
    int capacity;   // Max size of the stack
    int top;        // Top index
    int minTop;     // Top index of min stack
} MinStack;

// Initialize the stack
MinStack* createStack(int capacity) {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = capacity;
    stack->stack = (int*)malloc(capacity * sizeof(int));
    stack->min = (int*)malloc(capacity * sizeof(int));
    stack->top = stack->minTop = -1;
    return stack;
}

// Push element
void push(MinStack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->stack[++stack->top] = value;
        if (stack->minTop == -1 || value <= stack->min[stack->minTop]) {
            stack->min[++stack->minTop] = value;
        }
    }
}

// Pop element
void pop(MinStack* stack) {
    if (stack->top != -1) {
        int popped = stack->stack[stack->top--];
        if (popped == stack->min[stack->minTop]) {
            stack->minTop--;
        }
    }
}

// Get top element
int top(MinStack* stack) {
    return stack->top != -1 ? stack->stack[stack->top] : INT_MIN;
}

// Get minimum element
int getMin(MinStack* stack) {
    return stack->minTop != -1 ? stack->min[stack->minTop] : INT_MIN;
}

// Free memory
void freeStack(MinStack* stack) {
    free(stack->stack);
    free(stack->min);
    free(stack);
}

// Main function
int main() {
    MinStack* stack = createStack(5);
    push(stack, 3);
    push(stack, 5);
    push(stack, 2);
    push(stack, 1);
    push(stack, 4);
    pop(stack);
    
    printf("Top: %d\n", top(stack));
    printf("Min: %d\n", getMin(stack));

    freeStack(stack);
    return 0;
}