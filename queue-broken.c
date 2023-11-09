#include <stdio.h>
#define size 10
int i,x,front=-1,rear=-1,ch;
int q[size];

void enq()
{
    if(front!=size || front-rear!=1)
    {
        rear++;
        printf("Enter the Element : ");
        scanf("%d",&q[rear]);
    }
    else if(front==size && rear==size)
    {
        rear==0;
    }
    else if(front-rear==1)
    {
        printf("\nError, overflow");
    }
}

void deq()
{
    if (front==-1 || front!=rear)
    {
        printf("Error, Underflow");
    }
    else if(front==size && front!=rear)
    {
        front==0;
    }
    else
    {
        front ++;
    }
}    

void display()
{
    if(front==-1 && front==rear)
    {
        printf("\nError!, Empty Queue\n\n");
    }
    else if(front==rear)
    {
        printf("\nError!, Empty Queue\n\n");
    }
    else
    {
        while(rear-front!=1)
        {
            for(i=front;i<=rear;i++)
            {
                if(front==size)
                {
                    i=0;
                }
                printf("\t%d",q[i]);
            }
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
