//
// Created by norbe on 2026. 03. 01..
//

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computerChoice()
{
    return rand() % 3 + 1;
}

int decideWinner(int player, int computer)
{
    if (player == computer)
        return 0;

    if ((player == 1 && computer == 3) ||
        (player == 2 && computer == 1) ||
        (player == 3 && computer == 2))
        return 1;

    return 2;
}

void printChoice(int choice)
{
    if (choice == 1)
        printf("Ko");
    else if (choice == 2)
        printf("Papir");
    else if (choice == 3)
        printf("Ollo");
}