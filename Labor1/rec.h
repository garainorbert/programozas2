//
// Created by norbe on 2026. 03. 01..
//

#ifndef LABOR1_REC_H
#define LABOR1_REC_H

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

int lnkoRec(int a, int b);
int lkktRec(int a, int b, int a1, int b1);
int powerRec(int b, int e);
void readArrayRec(int *a, int n, FILE *f);
void printArrayRec(int *a, int n);
int sumArrayRec(int *a, int n);
int maxArrayRec(int *a, int n, int max);
int lnkoArrayRec(int *a, int n);
void digitsNumberRec(int n);
int inverseNumberRec(int n, int fn);

#endif

#endif //LABOR1_REC_H
