#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multi_printer(int a[2][5])
{
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            printf("%d\n", a[row][col]);
        }
    }
}

int main(void)
{
    int arr[2][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    multi_printer(arr);
}