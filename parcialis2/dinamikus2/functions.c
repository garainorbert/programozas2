//
// Created by norbe on 2026. 04. 25..
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int max_val(int a, int b) {
    return (a > b) ? a : b;
}

void solve_almakert(int rows, int cols, int **grid) {
    int **dp = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int *)malloc(cols * sizeof(int));
    }

    dp[0][0] = grid[0][0];

    for (int j = 1; j < cols; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = grid[i][j] + max_val(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("Maximalisan osszegyujtheto almak szama: %d\n", dp[rows - 1][cols - 1]);

    int i = rows - 1;
    int j = cols - 1;
    int total_steps = rows + cols - 1;

    int *path_x = (int *)malloc(total_steps * sizeof(int));
    int *path_y = (int *)malloc(total_steps * sizeof(int));
    int step_index = total_steps - 1;

    path_x[step_index] = i;
    path_y[step_index] = j;

    while (i > 0 || j > 0) {
        step_index--;
        if (i == 0) {
        } else if (j == 0) {
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        path_x[step_index] = i;
        path_y[step_index] = j;
    }

    printf("Az optimalis utvonal (sor, oszlop):\n");
    for (int k = 0; k < total_steps; k++) {
        printf("(%d, %d)", path_x[k], path_y[k]);
        if (k < total_steps - 1) {
            printf(" -> ");
        }
    }

    free(path_x);
    free(path_y);
    for (int k = 0; k < rows; k++) {
        free(dp[k]);
    }
    free(dp);
}