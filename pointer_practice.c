#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    /// Pointer Arithmetics With Arrays
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); /// size = (5 * 4) / 4 = 5

    // int *ptr = arr  : the pointer will have the address of the array.
    for (int *ptr = arr; ptr < arr + size; ptr++)
    {
        printf("%d\n", *ptr);       /// (deref a pointer)
    }

}