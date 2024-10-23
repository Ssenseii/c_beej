#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /*
        TASK LIST:
            - Binary Conversion
            - Octal Conversion
            - Decimal Conversion
            - Hexadecimal Conversion

            - int to float
            - float to char
            - int char
    */

    // From Binary to Integer

    char *s = "101010";
    unsigned long int bintoInt = strtoul(s, NULL, 2);
    printf("%s => Binary to Long Integer => %lu\n", s, bintoInt);

    // From Integer To Binary
    int IntToBin[32];
    int n = 42;
    int i = 0;

    while (n > 0)
    {
        IntToBin[i] = n % 2;
        n = n / 2;
        i++;
    };

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d => Integer to Binary => %d", n, IntToBin[j]);
    };
}