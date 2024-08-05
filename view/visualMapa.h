#include <stdio.h>
#include "raylib.h"

#define MAX_LINHAS 30
#define MAX_COLUNAS 60
#define PASSO 60
#define PASSO_UNIT 1
#define LARGURA_QUADRADO 60
#define ALTURA_QUADRADO 60
#define TRUE 1
#define FALSE 0
#define X_INICIAL 600
#define Y_INICIAL 300

void exibeMapa(void);
void preencheTelaComElementosMapa(char matrizChar[][MAX_COLUNAS], int posX, int posY, Texture2D texturaChao, Texture2D texturaGrama, Texture2D texturaArvore);
void leArquivoMapa(char matrizChar[][MAX_COLUNAS]);
void movimentaJogador(int *posX, int *posY, char matrizChar[][MAX_COLUNAS]);
int verificaSePodeMovimentar(int posX, int posY, char matrizChar[][MAX_COLUNAS]);
