//
//  save.h
//  INFmon
//
//  Created by Gustavo Machado Silva on 08/08/24.
//

#ifndef save_h
#define save_h

#include <stdio.h>
#include "infmon.h"
#include <string.h>

#define MAX_INFMONS 3
#define MAX_INIMIGOS 4
#define NUM_SAVES 1
#define TRUE 1
#define FALSE 0
#define NUM_INFMONS_INICIAL 1
#define POS_INFMON_INICIAL 0
#define MAPA_INICIAL 1
#define MAPA_2 2
#define MAPA_3 3
#define MAPA_4 4
#define MAX_MAPAS 4
#define ATIVO 1
#define INATIVO 0
#define MAX_COLUNAS 60
#define MAX_LINHAS 30

typedef struct {
    int x;
    int y;
}Posicao;

typedef struct {
    Posicao posicao;
    int numInfmons;
    Infmon infmons[MAX_INFMONS];
}Jogador;

typedef struct {
    Posicao posicao;
    Infmon infmons[MAX_INFMONS];
    int ativo;
}Inimigo;

typedef struct {
    Jogador jogador;
    int numInimigos;
    Inimigo inimigos[MAX_INIMIGOS];
    int numMapa;
}Estado;

int salvaJogo(Estado *save);
int carregaJogo(Estado *save);
int capturaInfmon(Estado *save, Infmon infmon);
Estado criaSaveInicial(Infmon infmonInicial);
int passaParaProximoMapa(Estado *save);
void leArquivoMapa(char matrizJogo[][MAX_COLUNAS], char fileName[]);
void encontraPosicaoInicialJogadorEInimigos(char matrizJogo[][MAX_COLUNAS], Estado *save);
void identificaNomeMapa(char fileName[], Estado save);

#endif /* save_h */
