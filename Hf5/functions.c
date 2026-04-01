//
// Created by norbe on 2026. 03. 25..
//

#include "functions.h"
#include <stdio.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generateAnagrams(char *str, int left, int right)
{
    if (left == right)
    {
        printf("%s\n", str);
        return;
    }

    for (int i = left; i <= right; i++)
    {
        swap(&str[left], &str[i]);

        generateAnagrams(str, left + 1, right);

        swap(&str[left], &str[i]);
    }
}