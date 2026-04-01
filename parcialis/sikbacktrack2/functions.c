//
// Created by norbe on 2026. 03. 31..
//

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

bool solve_hacker(int x, int y, int n, int m, int **matrix, bool **visited, int *path_x, int *path_y, int step) {
    path_x[step] = x;
    path_y[step] = y;

    if (x == n - 1 && y == m - 1) {
        for (int i = 0; i <= step; i++) {
            printf("(%d,%d) ", path_x[i] + 1, path_y[i] + 1);
        }
        printf("\n");
        return true;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {

            bool is_current_even = (matrix[x][y] % 2 == 0);
            bool is_next_even = (matrix[nx][ny] % 2 == 0);

            if (!visited[nx][ny] && is_current_even != is_next_even) {

                visited[nx][ny] = true;

                if (solve_hacker(nx, ny, n, m, matrix, visited, path_x, path_y, step + 1)) {
                    return true;
                }

                visited[nx][ny] = false;
            }
        }
    }

    return false;
}