#include <stdio.h>
#include <ctype.h>

#define MAX 100

int evaluatePostfix(const char *expr) {
    int stack[MAX], top = -1;
    
    for (int i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            stack[++top] = expr[i] - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch (expr[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    return stack[top];
}

int main() {
    char expr[] = "241*+8-";
    printf("Result: %d\n", evaluatePostfix(expr));
    return 0;
}