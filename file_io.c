#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char s[1024];
    fp = fopen("test.txt", "r");

    while ((fgets(s, sizeof(s), fp)) != NULL)
    {
        printf("%s\n", s);
    }

    fclose(fp);
}