#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack variables
char stack[MAX];
int top = -1;

// Function to push an item onto the stack
void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an item from the stack
char pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';  // Return null character if stack is empty
    }
}

// Function to peek at the top item of the stack
char peek() {
    if (top != -1) {
        return stack[top];
    } else {
        return '\0'; // Return null character if stack is empty
    }
}

// Function to check operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to check if the character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert infix to postfix
void infixToPostfix(const char *infix, char *postfix) {
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isalnum(current)) { // If the character is an operand
            postfix[j++] = current;
        } else if (current == '(') { // If the character is '('
            push(current);
        } else if (current == ')') { // If the character is ')'
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop '(' from stack
        } else if (isOperator(current)) { // If the character is an operator
            while (top != -1 && precedence(peek()) >= precedence(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
    }

    // Pop all the operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function to test the conversion
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
