#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push to stack
void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

// Pop from stack
int pop() {
    if (top >= 0)
        return stack[top--];
    return -1; // error
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isdigit(c)) {
            push(c - '0'); // convert char to int
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++)
                        res *= val1;
                    push(res);
                    break;
                }
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter a postfix expression (digits only): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
