#include <stdio.h>

int main()
{
    int temp,i,count,num,value,high,low,mid;

    printf("How many Numbers : ");
    scanf("%d",&num);
    int alpha[num];
    printf("Enter the Numbers : ");
    for(i=0;i<num;i++)
    {
        scanf("%d",&alpha[i]);
    }
    start:
    for(i=0;i<num-1;i++,count++)
    {
        if(alpha[i]>alpha[i+1])
        {
            temp=alpha[i+1];
            alpha[i+1]=alpha[i];
            alpha[i]=temp;
            goto start;
        }
    }
    printf("Enter the Element to be searched : ");
    scanf("%d",&value);
    low = 0;
    high = num;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(alpha[mid] == value)
        {
            printf("\nMatch Found at index %d",mid);
            return 0;
        }

        if(value < alpha[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    printf("Match Not found!");
    return 1;
}