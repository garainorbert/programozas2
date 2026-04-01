//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>

void solve_safe(int step, int start, int n, int k, int *numbers, int *sol, bool *found) {
    if (step == k) {
        if (numbers[sol[k - 1]] % 2 == 0) {
            *found = true;
            for (int i = 0; i < k; i++) {
                printf("%d ", numbers[sol[i]]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = start; i < n; i++) {
        sol[step] = i;

        solve_safe(step + 1, i + 1, n, k, numbers, sol, found);
    }
}
