#include "PGMReaderFunctions.h"

void limparComentarios(FILE *);

void limparComentarios(FILE *arquivo){
    
    int chr;

    do {

        chr = fgetc(arquivo);
        if(chr == '#') {
            while(chr != '\n' && chr != '\r' && chr != EOF) {
                chr = fgetc(arquivo);
            }
        }

    }while(chr == ' ' || chr == '\t' || chr == '\n' || chr == '\r' || chr == '\f' || chr == '\v');

    ungetc(chr, arquivo);
}


struct DATA *lerPGMImagem(FILE *pgmArquivo) {

    struct DATA *pgmDados = calloc(1, sizeof(struct DATA));

    fscanf(pgmArquivo, "%2s", pgmDados->tipo);

    limparComentarios(pgmArquivo);

    fscanf(pgmArquivo, "%d %d", &pgmDados->larg, &pgmDados->alt);

    limparComentarios(pgmArquivo);

    fscanf(pgmArquivo, "%d", &pgmDados->valorMax);

    fgetc(pgmArquivo);

    int total = pgmDados->alt * pgmDados->larg;
    pgmDados->pixelDados = calloc(total, sizeof(unsigned char));

    if(pgmDados->tipo[1] == '5') {

        fread(pgmDados->pixelDados, sizeof(unsigned char), total, pgmArquivo);

    }else if(pgmDados->tipo[1] == '2'){

        for(int i = 0; i < total; i++){

            int pixel;
            fscanf(pgmArquivo, "%d", &pixel);
            pgmDados->pixelDados[i] = (unsigned char)pixel;

        }
    }

    return pgmDados;
}


void printPGMImage(struct DATA *pgmDados){

    for(int i = 0; i < pgmDados->alt * pgmDados->larg; i++){

        if(!(i%pgmDados->larg)){
            printf("\n");
        }
        
        printf("%4d", *(pgmDados->pixelDados+i));
    }

}