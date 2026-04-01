//
// Created by norbe on 2026. 03. 30..
//

#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H

#define MAX_MERET 205

extern int n,m;
extern int terkep[MAX_MERET][MAX_MERET];
extern int visited[MAX_MERET][MAX_MERET];
extern int max_hossz;

void backtrack(int x, int y, int aktualis_hossz);

#endif //UNTITLED_FUNCTIONS_H
