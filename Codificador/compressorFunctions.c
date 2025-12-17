#include "compressorFunctions.h"

void checarHomogeneidade(struct QUADTREE *, unsigned char const *, const int, const int, const int, const float);
void escreverBytes(struct QUADTREE *tree, FILE *bitstream);

struct QUADTREE *quadBloco(unsigned char *dados, int larguraTotal, int larg, int alt, float taxaSolicitada){

    struct QUADTREE *bloco = calloc(1, sizeof(struct QUADTREE));
    if(!(bloco)){
        puts("Memoria insuficiente");
        exit(1);
    }

    checarHomogeneidade(bloco, dados, larguraTotal, larg, alt, taxaSolicitada);

    if(bloco->folha){

        bloco->quad1 = bloco->quad2 = bloco->quad3 = bloco->quad4 = NULL;

    }else{

        int meioLarg = larg/2;
        int meioAlt = alt/2;

        bloco->quad1 = quadBloco(dados, larguraTotal, meioLarg, meioAlt, taxaSolicitada);
        bloco->quad2 = quadBloco(dados + meioLarg, larguraTotal, larg-meioLarg, meioAlt, taxaSolicitada);
        bloco->quad3 = quadBloco(dados + (larguraTotal*meioAlt), larguraTotal, meioLarg, alt-meioAlt, taxaSolicitada);
        bloco->quad4 = quadBloco(dados + (larguraTotal*meioAlt) + meioLarg, larguraTotal, larg-meioLarg, alt-meioAlt, taxaSolicitada);

    }

    return bloco;
}


void checarHomogeneidade(struct QUADTREE *bloco, unsigned char const *dados, const int larguraTotal, const int larg, const int alt, const float taxaSolicitada){

    double mediaBloco = 0;
    double variancia = 0;
    int dimensao = larg * alt;

    for(int i = 0; i < alt; i++){ 
        for(int j = 0; j < larg; j++){
            mediaBloco += *(dados + (larguraTotal*i)+j);
        }
    }

    mediaBloco /= dimensao;

    for(int i = 0; i < alt; i++){
        for(int j = 0; j < larg; j++){
            variancia += (*(dados + (larguraTotal*i)+j) - mediaBloco) * (*(dados + (larguraTotal*i)+j) - mediaBloco);
        }
    }

    variancia /=  dimensao;

    double desvioPadrao = sqrt(variancia);

    if((desvioPadrao <= taxaSolicitada) || alt == 1 || larg == 1){

        bloco->folha = 1;
        bloco->valor = (unsigned char) round(mediaBloco);

    }else {

        bloco->folha = 0;

    }
}

void escreverBytes(struct QUADTREE *quadTree, FILE *bitstream){

    fwrite(&quadTree->folha, sizeof(unsigned char), 1, bitstream);
    
    if(quadTree->folha) {

        fwrite(&quadTree->valor, sizeof(unsigned char), 1, bitstream);

    }else {

        escreverBytes(quadTree->quad1, bitstream);
        escreverBytes(quadTree->quad2, bitstream);
        escreverBytes(quadTree->quad3, bitstream);
        escreverBytes(quadTree->quad4, bitstream);

    }

}


void escreverBitstream(struct DATA *pgmDados, struct QUADTREE *quadTree, FILE *bitstream) {
    unsigned char format[] = {'D', 'P'};

    fwrite(format, sizeof(unsigned char), 2, bitstream);

    fwrite(&pgmDados->larg, sizeof(short int), 1, bitstream);

    fwrite(&pgmDados->alt, sizeof(short int), 1, bitstream);

    escreverBytes(quadTree, bitstream);
}


void liberarQuadtree(struct QUADTREE *bloco) {

    if(bloco){

        if(!bloco->folha){

            liberarQuadtree(bloco->quad1);
            liberarQuadtree(bloco->quad2);
            liberarQuadtree(bloco->quad3);
            liberarQuadtree(bloco->quad4);

        }

        free(bloco);

    }

}