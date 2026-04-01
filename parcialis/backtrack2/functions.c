//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>

void solve_delivery(int step, int current_weight, int n, int k, int target_w, int *weights, int *sol, bool *used, bool *found) {
    if (current_weight > target_w) return;

    if (step == k) {
        if (current_weight == target_w) {
            *found = true;
            for (int i = 0; i < k; i++) {
                printf("%d ", weights[sol[i]]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (step > 0) {
                if (weights[sol[step - 1]] > 10 && weights[i] > 10) {
                    continue;
                }
            }

            used[i] = true;
            sol[step] = i;

            solve_delivery(step + 1, current_weight + weights[i], n, k, target_w, weights, sol, used, found);

            used[i] = false;
        }
    }
}