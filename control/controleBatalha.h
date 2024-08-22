#ifndef controleBatalha_h
#define controleBatalha_h

#include <stdio.h>
#include "../view/telaBatalha.h"
#include "../model/save.h"

void exibeBatalha(Estado *save, int isSelvagem, int numInimigo);
void acaoInimigo(int *turno, Estado *save, Infmon *infInimigo, int *numInfmonJogador, int *naBatalha);
void restauraVidaInfmonsJogador(Estado *save);
void condicaoSaida(Infmon infmonSelvagem, Estado *save, int *naBatalha, int isSelvagem, int numInimigo);
void selecionaProximoInfmonInimigo(Estado *save, int *numInfmonInimigo, int numInimigo, int numInfmonJogador, int *naBatalha);

#endif /* controleBatalha_h */
