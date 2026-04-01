//
// Created by norbe on 2026. 03. 30..
//

#ifndef PARC2_FUNCTIONS_H
#define PARC2_FUNCTIONS_H

#define MAX_ELEM 105

// Változók deklarálása, hogy minden fájl lássa őket
extern int n;             // Halmaz elemeinek száma
extern int S;             // Célösszeg
extern int halmaz[MAX_ELEM];     // Az eredeti számok
extern int reszhalmaz[MAX_ELEM]; // Az aktuális kiválasztott számok
extern int talalt;        // Jelzőváltozó (flag): találtunk-e megoldást

// Függvény prototípusa
void backtrack(int index, int aktualis_osszeg, int reszhalmaz_meret);

#endif //PARC2_FUNCTIONS_H
