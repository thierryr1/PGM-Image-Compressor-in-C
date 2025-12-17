#ifndef COMPRESSOR_FUNCTIONS_H
#define COMPRESSOR_FUNCTIONS_H

#include "PGMReaderFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct QUADTREE {
    unsigned char folha;
    unsigned char valor;
    struct QUADTREE *quad1, *quad2, *quad3, *quad4;
};

void liberarQuadtree(struct QUADTREE *);
struct QUADTREE *quadBloco(unsigned char *, int, int, int, float);
void escreverBitstream(struct DATA *, struct QUADTREE *, FILE *);

#endif