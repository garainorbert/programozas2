//
// Created by norbe on 2026. 04. 25..
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

void solve_hatizsak(int capacity, int n, Item items[]) {
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)calloc((capacity + 1), sizeof(int));
    }

    // 2. Lépés: A DP táblázat kitöltése
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(
                        items[i - 1].value + dp[i - 1][w - items[i - 1].weight],
                        dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int max_value = dp[n][capacity];

    printf("Elerheto maximalis ertek: %d\n", max_value);
    printf("A bepakolt targyak:\n");

    int res = max_value;
    int w = capacity;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w]) {
            continue;
        } else {
            printf("- Targy #%d (Suly: %d, Ertek: %d)\n", items[i - 1].id, items[i - 1].weight, items[i - 1].value);
            res -= items[i - 1].value;
            w -= items[i - 1].weight;
        }
    }

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}
