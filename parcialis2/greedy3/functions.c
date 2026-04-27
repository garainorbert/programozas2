//
// Created by norbe on 2026. 04. 25..
//

#include <stdio.h>
#include "functions.h"

void solve_penztaros(int amount) {
    int coins[] = {200, 100, 50, 10, 5, 1};
    int num_coins = 6;

    int total_count = 0;

    printf("Visszajaro osszeg: %d Ft\n", amount);
    printf("Kiadott cimletek:\n");

    for (int i = 0; i < num_coins; i++) {
        if (amount == 0) {
            break;
        }

        int count = amount / coins[i];

        if (count > 0) {
            printf("- %d db %d Ft-os\n", count, coins[i]);
            total_count += count;

            amount = amount % coins[i];
        }
    }

    printf("Osszesen %d db ermet/bankjegyet adtunk vissza.\n", total_count);
}
