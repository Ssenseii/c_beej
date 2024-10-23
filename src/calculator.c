#include <stdio.h>

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        return -1;
    }
}

int main()
{
    float x, y;
    int choice;
    
    printf(">===============+ Welcome to Calculator +===============<\n");
    
    while (1)
    {
    printf("\n\nChoose an Operation:\n");
    printf("1 -> Addition\n");
    printf("2 -> Subtraction\n");
    printf("3 -> Multiplication\n");
    printf("4 -> Division\n");
    printf("0 -> Exit\n\n\n");
    printf("Choice:");
    scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Adding...\n");
            printf("Enter First Number: ");
            scanf("%f", &x);
            printf("Enter Second Number:");
            scanf("%f", &y);
            printf("%f + %f = %f", x, y, add(x, y));
            break;

        case 2:
            printf("Substracting...\n");
            printf("Enter First Number: ");
            scanf("%f", &x);
            printf("Enter Second Number:");
            scanf("%f", &y);
            printf("%f + %f = %f", x, y, subtract(x, y));
            break;

        case 3:
            printf("Multiplying...\n");
            printf("Enter First Number: ");
            scanf("%f", &x);
            printf("Enter Second Number:");
            scanf("%f", &y);
            printf("%f + %f = %f", x, y, multiply(x, y));
            break;

        case 4:
            printf("Division...\n");
            printf("Enter First Number: ");
            scanf("%f", &x);
            printf("Enter Second Number:");
            scanf("%f", &y);
            printf("%f + %f = %f", x, y, divide(x, y));
            break;

        case 0:
            printf("Ending Program...");
            return 0;

        default:
            printf("wrong input, try again...");
            break;
        }
    }

}