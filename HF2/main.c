#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    int player, computer, result;

    srand(time(NULL));

    printf("Ko (1), Papir (2), Ollo (3)\n");
    printf("Valasztasod: ");
    scanf("%d", &player);

    if (player < 1 || player > 3)
    {
        printf("Hibas valasztas!\n");
        return 0;
    }

    computer = computerChoice();

    printf("Te: ");
    printChoice(player);

    printf("\nGep: ");
    printChoice(computer);

    result = decideWinner(player, computer);

    if (result == 0)
        printf("\nDontetlen!\n");
    else if (result == 1)
        printf("\nNyertel!\n");
    else
        printf("\nA gep nyert!\n");
    return 0;
}
