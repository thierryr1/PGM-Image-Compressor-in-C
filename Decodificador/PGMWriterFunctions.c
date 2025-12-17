#include "PGMWriterFunctions.h"
#include <stdlib.h>

void escreverPixels(QTree *bloco, unsigned char *matrizPixels, int larg, int alt, int larguraTotal);

void escreverPGM(QTree *tree, FILE *pgm, int larg, int alt) {

    unsigned char *matrizPixels = calloc(larg * alt, 1);
    if(!matrizPixels){
        puts("Memoria Insuficiente");
        exit(1);
    }

    escreverPixels(tree, matrizPixels, larg, alt, larg);

    fprintf(pgm, "P5\n%d %d\n255\n", larg, alt);
    
    fwrite(matrizPixels, 1, larg * alt, pgm);

    free(matrizPixels);

}


void escreverPixels(QTree *bloco, unsigned char *matrizPixels, int larg, int alt, int larguraTotal) {

    if (bloco->folha) {
        for (int i = 0; i < alt; i++)
            for (int j = 0; j < larg; j++)
                matrizPixels[i * larguraTotal + j] = bloco->valor;
    }else {

        int larg2 = larg / 2;
        int alt2 = alt / 2;

        escreverPixels(bloco->q1, matrizPixels,                             larg2,        alt2,       larguraTotal);
        escreverPixels(bloco->q2, matrizPixels + larg2,                     larg-larg2,   alt2,       larguraTotal);
        escreverPixels(bloco->q3, matrizPixels + (larguraTotal*alt2),       larg2,        alt-alt2,   larguraTotal);
        escreverPixels(bloco->q4, matrizPixels + (larguraTotal*alt2)+larg2, larg-larg2,   alt-alt2,   larguraTotal);
    }

}