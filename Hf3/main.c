#include <stdio.h>
#include "functions.h"

int main()
{
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    printf("Eredeti tomb:\n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);

    printf("\n\nRendezett tomb:\n");
    printArray(a, n);

    return 0;
}