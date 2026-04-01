#include <stdio.h>
#include <string.h>
#include "functions.h"

int main()
{
    char str[100];

    printf("Adj meg egy szot: ");
    scanf("%s", str);

    int n = strlen(str);

    printf("\nAnagrammak:\n");
    generateAnagrams(str, 0, n - 1);

    return 0;
}