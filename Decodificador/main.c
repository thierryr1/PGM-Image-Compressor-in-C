#include "decoderFunctions.h"
#include "PGMWriterFunctions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    if(argc != 3){
        printf("Utilização:\n\t%s <Entrada.dp> <Saída.pgm>\n", argv[0]);
        return 1; 
    }

    FILE *bistream = fopen(argv[1], "rb");
    if (!bistream) {
        perror("Erro abrindo bitstream(arquivo)");
        return 2;
    }

    FILE *pgm = fopen(argv[2], "wb");
    if (!pgm) {
        perror("Erro ao criar pgm");
        return 2;
    }

    unsigned char formato[2];
    fread(formato, 1, 2, bistream);
    if (formato[0] != 'D' || formato[1] != 'P') {
        printf("Bitstream(formato) inválido!\n");
        return 3;
    }


    short int larg, alt;
    fread(&larg, sizeof(short), 1, bistream);
    fread(&alt, sizeof(short), 1, bistream);

    QTree *Qtree = reconstruirQTree(bistream);
    escreverPGM(Qtree, pgm, larg, alt);


    liberarQTree(Qtree);
    fclose(bistream);
    fclose(pgm);
}