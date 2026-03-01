#include <stdio.h>
#include "rec.h"

int main()
{
    int a = 48, b = 18;

    printf("LNKO: %d\n", lnkoRec(a, b));
    printf("LKKT: %d\n", lkktRec(a, b, a, b));
    printf("2^5 = %d\n", powerRec(2, 5));

    int arr[] = {12, 18, 24};
    printf("Osszeg: %d\n", sumArrayRec(arr, 3));
    printf("Max: %d\n", maxArrayRec(arr, 3, arr[0]));
    printf("Tomb LNKO: %d\n", lnkoArrayRec(arr, 3));

    printf("Szamjegyek: ");
    digitsNumberRec(1234);

    printf("\nForditott: %d\n", inverseNumberRec(1234, 0));

    return 0;
}
