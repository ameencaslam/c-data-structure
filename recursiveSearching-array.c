#include <stdio.h>

int search(int alpha[],int size,int value,int position)
{
    if(size == 0)
    {
        return -1;
    }
    if(alpha[0] == value)
    {
        return position;
    }
    return search(alpha+1,size-1,value,position+1);
}

void main()
{
    int position,size,x,i,num,value;
    printf("How many Numbers : ");
    scanf("%d",&num);
    int alpha[num];
    printf("Enter the Numbers : ");
    for(i=0;i<num;i++)
    {
        scanf("%d",&alpha[i]);
    }
    printf("Enter the Element to be searched : ");
    scanf("%d",&value);
    size=sizeof(alpha)/sizeof(alpha[0]);
    x = search(alpha,size,value,0);
    if(x != -1)
    {
        printf("Match found at index %d",x);
    }
    else
    {
        printf("Match not found!");
    }
}