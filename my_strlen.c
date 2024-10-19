#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char *s = "Hello Dumbass!";
    int count = 0;

    while(s[count] != '\0'){
        count++;
    }

    printf("count: %d", count);

    return count;
}