#include <stdio.h>
#include "raylib.h"

#define MAX_LINHAS 30
#define MAX_COLUNAS 60
#define PASSO 20
#define LARGURA_QUADRADO 20
#define ALTURA_QUADRADO 20
#define TRUE 1
#define FALSE 0

void leArquivoMapa(char matrizChar[][MAX_COLUNAS]);
void preencheTelaComElementosMapa(char matrizChar[][MAX_COLUNAS]);
void movimentaJogador(int *posX, int *posY, char matrizChar[][MAX_COLUNAS]);
int verificaSePodeMovimentar(int posX, int posY, char matrizChar[][MAX_COLUNAS]);

void exibeMapa(void) {
    
    
    char matrizChar[MAX_LINHAS][MAX_COLUNAS];
    int i,j;
    int posX = 0, posY = 0;
    
    leArquivoMapa(matrizChar);
    
    
    for (i=0; i<MAX_LINHAS; i++) {
        for (j=0; j<MAX_COLUNAS; j++) {
            if (matrizChar[i][j] == 'J') {
                posX = j*PASSO;
                posY = i*PASSO;
            }
        }
    }
    
    while (!WindowShouldClose()) {
       
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        preencheTelaComElementosMapa(matrizChar);
        
        movimentaJogador(&posX, &posY, matrizChar);
        DrawRectangle(posX, posY, LARGURA_QUADRADO, ALTURA_QUADRADO, BLUE);
        
        EndDrawing();
        
    }

}

void leArquivoMapa(char matrizChar[][MAX_COLUNAS]) {
    
    char *filename = "mapa.txt";
    FILE *fp = fopen(filename, "r");
    int i, j;
    
    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
    }
    
    for (i=0; i<=MAX_LINHAS; i++) {
        for (j=0; j<=MAX_COLUNAS; j++) {
            matrizChar[i][j] = fgetc(fp);
        }
    }
    
    fclose(fp);
    
}

void preencheTelaComElementosMapa(char matrizChar[][MAX_COLUNAS]) {
    
    int i, j;
    
    for (i=0; i<MAX_LINHAS; i++) {
        for (j=0; j<MAX_COLUNAS; j++) {
            if (matrizChar[i][j] == 'W') {
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, BLACK);
            }
            else if (matrizChar[i][j] == 'G') {
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, GREEN);
            }
            else if (matrizChar[i][j] == 'E') {
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, RED);
            }
        }
    }
}

void movimentaJogador(int *posX, int *posY, char matrizChar[][MAX_COLUNAS]) {
    
    if (IsKeyDown(KEY_RIGHT)) {
        if (verificaSePodeMovimentar((*posX)+PASSO, *posY, matrizChar) == TRUE) {
            *posX += PASSO;
        }
    }
    if (IsKeyDown(KEY_LEFT)) {
        if (verificaSePodeMovimentar((*posX)-PASSO, *posY, matrizChar) == TRUE) {
            *posX -= PASSO;
        }
    }
    if (IsKeyDown(KEY_UP)) {
        if (verificaSePodeMovimentar(*posX, (*posY)-PASSO, matrizChar) == TRUE) {
            *posY -= PASSO;
        }
    }
    if (IsKeyDown(KEY_DOWN)) {
        if (verificaSePodeMovimentar(*posX, (*posY)+PASSO, matrizChar) == TRUE) {
            *posY += PASSO;
        }
    }
    
}

int verificaSePodeMovimentar(int posX, int posY, char matrizChar[][MAX_COLUNAS]) {
    
    int numPosX = posX / LARGURA_QUADRADO;
    int numPosY = posY/ ALTURA_QUADRADO;
    int podeMovimentar;
    
    if (matrizChar[numPosY][numPosX] == 'W') {
        podeMovimentar = FALSE;
    }
    else {
        podeMovimentar = TRUE;
    }
    
    return podeMovimentar;
}
