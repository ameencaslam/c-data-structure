#include <stdio.h>
#define size 3

int i, front = -1, rear = -1, ch;
int q[size];

void enq()
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        printf("\nError! Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        printf("Enter the Element : ");
        scanf("%d", &q[rear]);
    }
}

void deq()
{
    if (front == -1)
    {
        printf("\nError! Underflow\n");
    }
    else
    {
        printf("\nDeleted Element : %d\n", q[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nError!, Empty Queue\n\n");
    }
    else
    {
        printf("\n");
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("\t%d", q[i]);
        }
        printf("\t%d", q[i]); // Print the last element
        printf("\n");
    }
}

int main(void)
{
    do
    {
        printf("\n1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. END\n");
        printf("Enter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enq();
            break;

        case 2:
            deq();
            break;

        case 3:
            display();
            break;

        case 4:
            break;

        default:
            printf("\nInvalid Option\n");
        }
    } while (ch != 4);

    printf("\nByeBye...\n\n.");
    return 0;
}
