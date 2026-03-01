//
// Created by norbe on 2026. 03. 01..
//

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int maxArrayDivEtImp(int *a, int i, int j)
{
    if (i == j)
        return a[i];

    int mid = (i + j) / 2;

    int maxLeft = maxArrayDivEtImp(a, i, mid);
    int maxRight = maxArrayDivEtImp(a, mid + 1, j);

    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

void Hanoi(int k, int s, int d, int h)
{
    if (k == 1)
    {
        printf("Korong %d: %d -> %d\n", k, s, d);
        return;
    }

    Hanoi(k - 1, s, h, d);
    printf("Korong %d: %d -> %d\n", k, s, d);
    Hanoi(k - 1, h, d, s);
}

void merge(int *a, int i, int mid, int j)
{
    int n1 = mid - i + 1;
    int n2 = j - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int x = 0; x < n1; x++)
        L[x] = a[i + x];

    for (int x = 0; x < n2; x++)
        R[x] = a[mid + 1 + x];

    int x = 0, y = 0, k = i;

    while (x < n1 && y < n2)
    {
        if (L[x] <= R[y])
            a[k++] = L[x++];
        else
            a[k++] = R[y++];
    }

    while (x < n1)
        a[k++] = L[x++];

    while (y < n2)
        a[k++] = R[y++];

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

int partition(int *a, int i, int j)
{
    int pivot = a[j];
    int pIndex = i;

    for (int k = i; k < j; k++)
    {
        if (a[k] <= pivot)
        {
            int temp = a[k];
            a[k] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = a[pIndex];
    a[pIndex] = a[j];
    a[j] = temp;

    return pIndex;
}

void quickSort(int *a, int i, int j)
{
    if (i < j)
    {
        int p = partition(a, i, j);
        quickSort(a, i, p - 1);
        quickSort(a, p + 1, j);
    }
}

void printArray(int *a, int n)
{
    if (n <= 0)
        return;

    printf("%d ", *a);
    printArray(a + 1, n - 1);
}
