#ifndef visualMapa_h
#define visualMapa_h

#include <stdio.h>
#include "raylib.h"
#include "../model/save.h"

#define MAX_LINHAS 30
#define MAX_COLUNAS 60
#define PASSO 60
#define LARGURA_QUADRADO 60
#define ALTURA_QUADRADO 60
#define X_INICIAL 600
#define Y_INICIAL 300

void preencheTelaComElementosMapa(char matrizJogo[][MAX_COLUNAS], Estado save, Texture2D texturaChao, Texture2D texturaGrama, Texture2D texturaArvore);
void desenhaJogador(void);

#endif /* visualMapa_h */
