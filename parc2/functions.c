//
// Created by norbe on 2026. 03. 30..
//

#include "functions.h"
#include <stdio.h>

int n;
int S;
int halmaz[MAX_ELEM];
int reszhalmaz[MAX_ELEM];
int talalt = 0;

void backtrack(int index, int aktualis_osszeg, int reszhalmaz_meret) {
    if (aktualis_osszeg == S) {
        talalt = 1;
        for (int i = 0; i < reszhalmaz_meret; i++) {
            printf("%d ", reszhalmaz[i]);
        }
        printf("\n");
        return;
    }

    if (aktualis_osszeg > S || index == n) {
        return;
    }
    reszhalmaz[reszhalmaz_meret] = halmaz[index];
    backtrack(index + 1, aktualis_osszeg + halmaz[index], reszhalmaz_meret + 1);

    backtrack(index + 1, aktualis_osszeg, reszhalmaz_meret);
}