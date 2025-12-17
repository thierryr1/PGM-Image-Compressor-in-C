#ifndef PGM_READER_FUNCTIONS_H
#define PGM_READER_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

struct DATA {
    char tipo[3];
    int larg;
    int alt;
    int valorMax;
    unsigned char *pixelDados;
};

struct DATA *lerPGMImagem(FILE *);
void printPGMImage(struct DATA *);

#endif