#ifndef __CHAINES_H__
#define __CHAINES_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int lire_fin_ligne();
void lit_format(char *, void *);
int lire_chaine(char *);

int lire_entier(int *);
int lire_decimal(float *);
int lire_long_decimal(double *);
int lire_entier_positif(int *);
int lire_long_decimal_positif(double *);

#endif