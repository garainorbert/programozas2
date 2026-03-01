//
// Created by norbe on 2026. 03. 01..
//

#include "rec.h"

#include <stdio.h>

int lnkoRec(int a, int b)
{
    if (b == 0)
        return a;
    return lnkoRec(b, a % b);
}

int lkktRec(int a, int b, int a1, int b1)
{
    if (b == 0)
        return (a1 * b1) / a;
    return lkktRec(b, a % b, a1, b1);
}

int powerRec(int b, int e)
{
    if (e == 0)
        return 1;
    return b * powerRec(b, e - 1);
}

void readArrayRec(int *a, int n, FILE *f)
{
    if (n <= 0)
        return;

    fscanf(f, "%d", a);
    readArrayRec(a + 1, n - 1, f);
}

void printArrayRec(int *a, int n)
{
    if (n <= 0)
        return;

    printf("%d ", *a);
    printArrayRec(a + 1, n - 1);
}

int sumArrayRec(int *a, int n)
{
    if (n == 0)
        return 0;

    return *a + sumArrayRec(a + 1, n - 1);
}

int maxArrayRec(int *a, int n, int max)
{
    if (n == 0)
        return max;

    if (*a > max)
        max = *a;

    return maxArrayRec(a + 1, n - 1, max);
}

int lnkoArrayRec(int *a, int n)
{
    if (n == 1)
        return a[0];

    return lnkoRec(a[0], lnkoArrayRec(a + 1, n - 1));
}

void digitsNumberRec(int n)
{
    if (n == 0)
        return;

    digitsNumberRec(n / 10);
    printf("%d ", n % 10);
}

int inverseNumberRec(int n, int fn)
{
    if (n == 0)
        return fn;

    return inverseNumberRec(n / 10, fn * 10 + n % 10);
}