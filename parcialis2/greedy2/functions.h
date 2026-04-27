//
// Created by norbe on 2026. 04. 25..
//

#ifndef GREEDY2_FUNCTIONS_H
#define GREEDY2_FUNCTIONS_H

typedef struct {
    int id;
    double weight;
    double price;
    double ratio;
} Candy;

void solve_edesseges(double capacity, int n, Candy candies[]);

#endif //GREEDY2_FUNCTIONS_H
