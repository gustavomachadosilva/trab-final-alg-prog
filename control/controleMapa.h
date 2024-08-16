#ifndef controleMapa_h
#define controleMapa_h

#include <stdio.h>
#include "raylib.h"
#include "../model/save.h"
#include "../view/visualMapa.h"
#include "controlePause.h"

#define PASSO_UNIT 1
#define TRUE 1
#define FALSE 0

void exibeMapa(Estado *save);
void movimentaJogador(Estado *save, char matrizChar[][MAX_COLUNAS]);
int verificaSePodeMovimentar(int posX, int posY, char matrizChar[][MAX_COLUNAS]);

#endif /* controleMapa_h */
