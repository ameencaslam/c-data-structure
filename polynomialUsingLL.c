#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
};

void insertTerm(struct Node** poly, int coeff, int exp)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*poly == NULL)
    {
        *poly = newNode;
    }
    else
    {
        struct Node* temp = *poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPoly(struct Node* poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void main()
{
    struct Node* poly = NULL;
    int coeff, exp, count;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
    {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        insertTerm(&poly, coeff, exp);
    }

    printf("\nPolynomial: ");
    displayPoly(poly);
}
