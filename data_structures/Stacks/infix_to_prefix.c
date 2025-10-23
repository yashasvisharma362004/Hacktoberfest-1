#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push element to stack
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

// Pop element from stack
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

// Peek top element
char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

// Check operator precedence
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Reverse the string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix[j++] = c;
        } else if (c == ')') {
            push(c);
        } else if (c == '(') {
            while (top != -1 && peek() != ')')
                prefix[j++] = pop();
            pop(); // remove ')'
        } else {
            while (top != -1 && precedence(c) < precedence(peek()))
                prefix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        prefix[j++] = pop();

    prefix[j] = '\0';
    reverse(prefix);
}

// Main function
int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
