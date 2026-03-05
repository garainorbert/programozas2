//
// Created by norbe on 2026. 03. 05..
//

#include "functions.h"

void printArray(int *a, int n)
{
    if (n == 0)
        return;

    printf("%d ", *a);
    printArray(a + 1, n - 1);
}

int maxArrayDivEtImp(int *a, int i, int j)
{
    if (i == j)
        return a[i];

    int mid = (i + j) / 2;

    int maxLeft = maxArrayDivEtImp(a, i, mid);
    int maxRight = maxArrayDivEtImp(a, mid + 1, j);

    if (maxLeft > maxRight)
        return maxLeft;
    else
        return maxRight;
}

void Hanoi(int k, int s, int d, int h)
{
    if (k == 1)
    {
        printf("Korong mozgatasa: %d -> %d\n", s, d);
        return;
    }

    Hanoi(k - 1, s, h, d);
    printf("Korong mozgatasa: %d -> %d\n", s, d);
    Hanoi(k - 1, h, d, s);
}