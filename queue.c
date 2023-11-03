#include <stdio.h>
#define size 10
int i,x,front=0,rear=-1,ch;
int q[size];

void enq()
{
    if(rear>=size-1)
    {
        printf("\nError!, Overflow\n\n");
    }
    else
    {
        rear++;
        printf("Enter the Element : ");
        scanf("%d",&q[rear]);
    }
}

void deq()
{
    if(rear<0)
    {
        printf("\nError!, Underflow\n\n");
    }
    else
    {
        for(i=front;i<rear;i++)
        {
            q[i]=q[i+1];
        }
        rear--;
    }
}

void display()
{
    if(rear<0)
    {
        printf("\nError!, Empty Queue\n\n");
    }
    else
    {
        printf("\n");
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",q[i]);
        }
        printf("\n");
    }
}

void main()
{
    do
    {
        printf("\n1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. END\n");
        printf("Enter your Choice : ");
        scanf("%d",&ch);

        switch(ch)
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
    }while(ch!=4);

    printf("\nByeBye...\n\n.");
}