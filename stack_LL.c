#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\n%d pushed to the stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("\nStack is Empty.\n");
        return;
    }

    struct Node* temp = top;
    top = temp->next;
    int poppedValue = temp->data;
    free(temp);
    printf("\n%d popped from the stack.\n", poppedValue);
}

void display() {
    if (top == NULL) {
        printf("\nStack is Empty.\n");
        return;
    }

    printf("\nStack elements: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void main() {
    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 0:
                printf("\nExiting the program.\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}
