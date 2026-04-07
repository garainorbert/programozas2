//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void solve_hacker(int step, int x, int y, int n, int m, int **matrix, bool **visited, int *path_x, int *path_y, bool *found) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny]) {
                bool current_even = (matrix[x][y] % 2 == 0);
                bool next_even = (matrix[nx][ny] % 2 == 0);

                if (current_even != next_even) {

                    path_x[step] = nx;
                    path_y[step] = ny;
                    visited[nx][ny] = true;

                    if (nx == n - 1 && ny == m - 1) {
                        *found = true;
                        for (int j = 0; j <= step; j++) {
                            printf("(%d,%d) ", path_x[j] + 1, path_y[j] + 1);
                        }
                        printf("\n");
                    } else {
                        solve_hacker(step + 1, nx, ny, n, m, matrix, visited, path_x, path_y, found);
                    }

                    visited[nx][ny] = false;
                }
            }
        }
    }
}