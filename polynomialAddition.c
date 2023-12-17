#include <stdio.h>

void addPolynomials(int poly1[], int poly2[], int result[], int size)
{
    for (int i = 0; i < size; i++)
    {
        result[i] = poly1[i] + poly2[i];
    }
}

void displayPolynomial(int poly[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            if (i > 0 && poly[i - 1] > 0)
            {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

int main()
{
    int degree;

    printf("Enter the degree of the polynomials: ");
    scanf("%d", &degree);

    int size = degree+1;
    int poly1[size], poly2[size], result[size];

    // Get coefficients for the first polynomial from the user
    printf("Enter coefficients for the first polynomial:\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // Get coefficients for the second polynomial from the user
    printf("Enter coefficients for the second polynomial:\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    // Adding two polynomials
    addPolynomials(poly1, poly2, result, size);

    // Displaying the result
    printf("Polynomial 1: ");
    displayPolynomial(poly1, size);

    printf("Polynomial 2: ");
    displayPolynomial(poly2, size);

    printf("Sum: ");
    displayPolynomial(result, size);

    return 0;
}
