// infixToPostix
// Algorithm:
// 1. Initialize an empty stack to store operators.
// 2. For each token in the infix expression:
//    - If the token is an operand, add it to the output.
//    - If the token is an operator:
//       - While the stack is not empty, and the top operator has higher precedence than the current operator, push the current operator onto the stack.
//       - If the top operator has the same precedence as the current operator, pop the top operator from the stack and add it to the output.
//       - Push the current operator onto the stack.
//    - If the token is an opening parenthesis '(', push it onto the stack.
//    - If the token is a closing parenthesis ')', pop operators from the stack and add them to the output until an opening parenthesis '(' is encountered. Pop and discard the '('.
// 3. After processing all tokens, pop any remaining operators from the stack and add them to the output.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int isOperand(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int getPrecedence(char ch)
{
    switch (ch) {
        case '+':
        case '-':
            return 1;
        
        case '*':
        case '/':
            return 2;
        
        case '^':
            return 3;
        
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isOperand(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
            {
                top--;
            }
        }
        else
        {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(ch))
            {
               postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
         }
    }
    while (top >= 0)
    {
      postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

void main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("\nEnter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);
}
