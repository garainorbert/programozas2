//
// Created by norbe on 2026. 04. 25..
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int compare_candies(const void *a, const void *b) {
    Candy *c1 = (Candy *)a;
    Candy *c2 = (Candy *)b;

    if (c1->ratio < c2->ratio) return 1;
    if (c1->ratio > c2->ratio) return -1;
    return 0;
}

void solve_edesseges(double capacity, int n, Candy candies[]) {
    qsort(candies, n, sizeof(Candy), compare_candies);

    double total_value = 0.0;


    for (int i = 0; i < n; i++) {
        if (capacity <= 0.0) {
            break;
        }

        double take_weight = (candies[i].weight < capacity) ? candies[i].weight : capacity;
        double take_value = take_weight * candies[i].ratio;

        printf("Uveg #%d: Berakva %.2f gramm, erteke: %.2f Ft (Fajlagos ar: %.2f Ft/g)\n",
               candies[i].id, take_weight, take_value, candies[i].ratio);

        total_value += take_value;
        capacity -= take_weight;
    }

    printf("A dobozba pakolt edessegek osszerteke: %.2f Ft\n", total_value);
}
