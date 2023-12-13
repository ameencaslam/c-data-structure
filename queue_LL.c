#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enq(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("\n%d Enqueued.",data);
}

void deq()
{
    if (front == NULL)
    {
        printf("\nEmpty!");
        return;
    }

    struct node *temp = front;
    printf("\n%d Dequeued.",temp->data);
    front = front->next;
    free(temp);

    if (front == NULL)
    {
        rear = NULL;
    }
}

void display()
{
    struct node *temp = front;
    if (temp == NULL)
    {
        printf("\nEmpty!");
        return;
    }
    printf("\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, data;

    do
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n\nEnter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the Value : ");
                scanf("%d", &data);
                enq(data);
                break;

            case 2:
                deq();
                break;

            case 3:
                display();
                break;

            case 0:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid Choice!");
                break;
        }
    } while (choice != 0);

    return 0;
}
