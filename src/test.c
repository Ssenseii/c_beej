#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(const int x)
{
    
    printf("%d", x + 30);
}

int main(void)
{
    foo(1);
}