//
// Created by norbe on 2026. 03. 05..
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void printArray(int *a, int n)
{
    if (n == 0)
        return;

    printf("%d ", *a);
    printArray(a + 1, n - 1);
}

void merge(int *a, int i, int mid, int j)
{
    int n1 = mid - i + 1;
    int n2 = j - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int k = 0; k < n1; k++)
        L[k] = a[i + k];

    for (int k = 0; k < n2; k++)
        R[k] = a[mid + 1 + k];

    int p = 0, q = 0, k = i;

    while (p < n1 && q < n2)
    {
        if (L[p] <= R[q])
            a[k++] = L[p++];
        else
            a[k++] = R[q++];
    }

    while (p < n1)
        a[k++] = L[p++];

    while (q < n2)
        a[k++] = R[q++];

    free(L);
    free(R);
}

void mergeSort(int *a, int i, int j)
{
    if (i >= j)
        return;

    int mid = (i + j) / 2;

    mergeSort(a, i, mid);
    mergeSort(a, mid + 1, j);
    merge(a, i, mid, j);
}
