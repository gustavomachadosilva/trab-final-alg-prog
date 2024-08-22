#ifndef controleMapa_h
#define controleMapa_h

#include <stdio.h>
#include "raylib.h"
#include "../model/save.h"
#include "../view/visualMapa.h"
#include "controlePause.h"
#include "controleBatalha.h"
#include <time.h>
#include <stdlib.h>
#include "controleTelaFinal.h"
#include "controleTelaInicial.h"

#define PASSO_UNIT 1
#define TRUE 1
#define FALSE 0

void exibeMapa(Estado *save);
void movimentaJogador(Estado *save, char matrizChar[][MAX_COLUNAS]);
int verificaSePodeMovimentar(int posX, int posY, char matrizChar[][MAX_COLUNAS]);
void verificaEncontrouInfmonSelvagem(Estado *save, char matrizChar[][MAX_COLUNAS]);
void verificaEncontrouInimigo(Estado *save, char matrizChar[][MAX_COLUNAS]);
void verificaPassarMapa(Estado *save, char matrizJogo[][MAX_COLUNAS], int *estadoTela);

#endif /* controleMapa_h */
