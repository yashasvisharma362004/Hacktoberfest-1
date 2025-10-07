/*
  Program: Simple Calculator (Calci)
  Problem Statement: Perform basic arithmetic operations (addition, subtraction, multiplication, division) based on user input.

  Input Example:
    Enter first number: 5
    Enter operator (+, -, *, /): *
    Enter second number: 3

  Output Example:
    Result: 5 * 3 = 15

  Complexity: O(1) for each operation
*/

#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;
    
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch(op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;
        default:
            printf("Error: Unsupported operator '%c'\n", op);
            return 1;
    }
    return 0;
}
