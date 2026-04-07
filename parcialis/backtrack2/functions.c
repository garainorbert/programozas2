//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>

bool igeretes_delivery(int step, int *sol, bool *used, int *weights, int target_w) {
    if (used[sol[step]]) return false;

    // Szabály: két 10-nél nehezebb nem lehet egymás mellett
    if (step > 0) {
        if (weights[sol[step - 1]] > 10 && weights[sol[step]] > 10) return false;
    }

    // Súly ellenőrzése
    int current_sum = 0;
    for (int i = 0; i <= step; i++) {
        current_sum += weights[sol[i]];
    }
    if (current_sum > target_w) return false;

    return true;
}

void solve_delivery(int step, int n, int k, int target_w, int *weights, int *sol, bool *used, bool *found) {
    for (int i = 0; i < n; i++) {
        sol[step] = i;

        if (igeretes_delivery(step, sol, used, weights, target_w)) {

            used[i] = true;

            if (step == k - 1) {
                int final_sum = 0;
                for(int j = 0; j <= step; j++) final_sum += weights[sol[j]];

                if (final_sum == target_w) {
                    *found = true;
                    for (int j = 0; j <= step; j++) printf("%d ", weights[sol[j]]);
                    printf("\n");
                }
            } else {
                solve_delivery(step + 1, n, k, target_w, weights, sol, used, found);
            }

            used[i] = false;
        }
    }
}