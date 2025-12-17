#ifndef DECODER_FUNCTIONS_H
#define DECODER_FUNCTIONS_H

#include <stdio.h>

typedef struct QUADTREE {
    unsigned char folha;
    unsigned char valor;
    struct QUADTREE *q1, *q2, *q3, *q4;
} QTree;

QTree* reconstruirQTree(FILE *);
void liberarQTree(QTree *);

#endif