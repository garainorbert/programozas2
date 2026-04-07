//
// Created by norbe on 2026. 03. 31..
//

#ifndef BACKTRACK2_FUNCTIONS_H
#define BACKTRACK2_FUNCTIONS_H

#include <stdbool.h>

bool igeretes_delivery(int step, int *sol, bool *used, int *weights, int target_w);
void solve_delivery(int step, int n, int k, int target_w, int *weights, int *sol, bool *used, bool *found);

#endif //BACKTRACK2_FUNCTIONS_H
