#include <stdio.h>
#include "functions.h"

int main()
{
    int a[] = {12, 45, 7, 89, 23, 56};
    int n = 6;

    printf("Tomb elemei:\n");
    printArray(a, n);

    int max = maxArrayDivEtImp(a, 0, n - 1);
    printf("\nMaximum: %d\n", max);

    printf("\nHanoi tornyai (3 korong):\n");
    Hanoi(3, 1, 3, 2);

    return 0;
}