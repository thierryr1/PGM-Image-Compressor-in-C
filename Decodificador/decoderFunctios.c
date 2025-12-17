#include "decoderFunctions.h"
#include <stdlib.h>


QTree* reconstruirQTree(FILE *bitstream) {
    QTree *bloco = calloc(1, sizeof(QTree));
    if (!bloco) {
        puts("Memoria Insuficiente");
        exit(1);
    }

    fread(&bloco->folha, 1, 1, bitstream);

    if (bloco->folha) {
        fread(&bloco->valor, 1, 1, bitstream);
    } else {
        bloco->q1 = reconstruirQTree(bitstream);
        bloco->q2 = reconstruirQTree(bitstream);
        bloco->q3 = reconstruirQTree(bitstream);
        bloco->q4 = reconstruirQTree(bitstream);
    }
    
    return bloco;
}


void liberarQTree(QTree *bloco) {
    if (!bloco) return;
    if (!bloco->folha) {
        liberarQTree(bloco->q1);
        liberarQTree(bloco->q2);
        liberarQTree(bloco->q3);
        liberarQTree(bloco->q4);
    }
    free(bloco);
}


