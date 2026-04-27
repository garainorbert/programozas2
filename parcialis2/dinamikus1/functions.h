//
// Created by norbe on 2026. 04. 25..
//

#ifndef DINAMIKUS1_FUNCTIONS_H
#define DINAMIKUS1_FUNCTIONS_H

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void solve_hatizsak(int capacity, int n, Item items[]);

#endif //DINAMIKUS1_FUNCTIONS_H
