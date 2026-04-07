//
// Created by norbe on 2026. 03. 31..
//

#ifndef BACKTRACK3_FUNCTIONS_H
#define BACKTRACK3_FUNCTIONS_H

#include <stdbool.h>

bool igeretes_museum(int step, int *sol, bool *used, int *items, int d);
void solve_museum(int step, int n, int k, int d, int *items, int *sol, bool *used, bool *found);

#endif //BACKTRACK3_FUNCTIONS_H
