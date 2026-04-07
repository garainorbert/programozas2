//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>

bool igeretes_safe(int step, int *sol, bool *used) {
    if (used[sol[step]]) return false;

    if (step > 0 && sol[step] <= sol[step - 1]) return false;

    return true;
}

void solve_safe(int step, int n, int k, int *numbers, int *sol, bool *used, bool *found) {
    for (int i = 0; i < n; i++) {
        sol[step] = i;

        if (igeretes_safe(step, sol, used)) {

            used[i] = true;

            if (step == k - 1) {
                if (numbers[sol[step]] % 2 == 0) {
                    *found = true;
                    for (int j = 0; j <= step; j++) {
                        printf("%d ", numbers[sol[j]]);
                    }
                    printf("\n");
                }
            } else {
                solve_safe(step + 1, n, k, numbers, sol, used, found);
            }

            used[i] = false;
        }
    }
}