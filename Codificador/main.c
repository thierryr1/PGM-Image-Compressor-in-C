#include "compressorFunctions.h"
#include "PGMReaderFunctions.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

    if(argc != 4){

        printf("Formato:\n\t%s <imagemEntrada.pgm> <bistreamNome.bin> <float taxaSolicitada>\n", argv[0]);
        exit(1);
        
    }


    FILE *pgm;
    if(!(pgm = fopen(argv[1], "rb"))){

        perror("Falha na abertura do arquivo.");
        exit(2);

    }


    FILE *bistream;
    if(!(bistream = fopen(argv[2], "wb"))){

        perror("Falha na abertura do arquivo.");
        exit(3); 

    }


    float taxaSolicitada = atof(argv[3]);
    if (taxaSolicitada < 1){

        puts("Taxa abaixo do valor adequado");
        exit(4);

    }
    struct DATA *pgmDados = lerPGMImagem(pgm);
    struct QUADTREE *quadTree = quadBloco(pgmDados->pixelDados, pgmDados->larg, pgmDados->larg, pgmDados->alt, taxaSolicitada);
    

    escreverBitstream(pgmDados, quadTree, bistream);
    
    liberarQuadtree(quadTree);

    fclose(pgm);
    
    fclose(bistream);

    return 0;
}