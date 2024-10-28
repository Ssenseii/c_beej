#include <stdio.h>
#include <stdarg.h>

int func(int a, ...)
{
    int total = 0;
    va_list va;

    va_start(va, a);

    for(int i = 0; i < a; i++){
        int n = va_arg(va, int);

        total += n;
    }

    va_end(va);

    return total;  // Prints "a is 2"
}

int main(void)
{
    printf("%d\n", func(2, 22, 44));
}