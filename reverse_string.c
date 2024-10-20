#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char str[])
{
    int len = strlen(str);
    char new_arr[len + 1]; /// +1 for the null terminator

    for (int i = 0; i < len; i++)
    {
        new_arr[i] = str[len - 1 - i];
    }

    new_arr[len] = '\0';

    printf("%s", new_arr);
}

int main(void)
{
    char *s = "Hello World!";
    reverseString(s);
}