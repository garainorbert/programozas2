#include <stdio.h>
#include "functions.h"

int main() {
        int a[] = {34, 7, 23, 32, 5, 62};
        int n = 6;

        printf("Maximum: %d\n\n", maxArrayDivEtImp(a, 0, n - 1));

        printf("Hanoi (3 korong):\n");
        Hanoi(3, 1, 3, 2);

        int b[] = {34, 7, 23, 32, 5, 62};
        mergeSort(b, 0, n - 1);
        printf("\nMergeSort eredmeny:\n");
        printArray(b, n);

        int c[] = {34, 7, 23, 32, 5, 62};
        quickSort(c, 0, n - 1);
        printf("\nQuickSort eredmeny:\n");
        printArray(c, n);

        return 0;
}
