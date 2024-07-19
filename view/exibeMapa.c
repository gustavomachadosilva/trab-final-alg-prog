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

void leArquivoMapa(char matrizChar[][MAX_COLUNAS]);
void preencheTelaComElementosMapa(char matrizChar[][MAX_COLUNAS], int posX, int posY);
void movimentaJogador(int *posX, int *posY, char matrizChar[][MAX_COLUNAS]);
int verificaSePodeMovimentar(int posX, int posY, char matrizChar[][MAX_COLUNAS]);

void exibeMapa(void) {
    
    
    char matrizChar[MAX_LINHAS][MAX_COLUNAS];
    int i,j;
    int posX = 0;
    int posY = 0;
    
    leArquivoMapa(matrizChar);
    
    
    for (i=0; i<MAX_LINHAS; i++) {
        for (j=0; j<MAX_COLUNAS; j++) {
            if (matrizChar[i][j] == 'J') {
                posX = j;
                posY = i;
            }
        }
    }
    
    while (!WindowShouldClose()) {
       
        BeginDrawing();
        ClearBackground(GRAY);
        
        preencheTelaComElementosMapa(matrizChar, posX, posY);
        
        movimentaJogador(&posX, &posY, matrizChar);
        DrawRectangle(X_INICIAL, Y_INICIAL, LARGURA_QUADRADO, ALTURA_QUADRADO, BLUE);
        
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

void preencheTelaComElementosMapa(char matrizChar[][MAX_COLUNAS], int posX, int posY) {
    
    int i, j, k, l;
    char novaMatriz[10][20] = {};
    
    k=-1;
    l=-1;
    
    for (i=(posY-5); i<=(posY+4); i++) {
        k++;
        for (j=(posX-10); j<=(posX+9); j++) {
            l++;
            if (i>=0 && i<30 && j>=0 && j<60) {
                novaMatriz[k][l] = matrizChar[i][j];
            }
        }
        l=-1;
    }
    
    for (i=0; i<10; i++) {
        for (j=0; j<20; j++) {
            if (novaMatriz[i][j] == 'W') {
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, BLACK);
            }
            else if (novaMatriz[i][j] == 'G') {
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, GREEN);
            }
            else if (novaMatriz[i][j] == 'E') {
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, RED);
            }
            else if (novaMatriz[i][j] == ' ' || novaMatriz[i][j] == 'J'){
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, WHITE);
            }
        }
    }
}

void movimentaJogador(int *posX, int *posY, char matrizChar[][MAX_COLUNAS]) {
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        if (verificaSePodeMovimentar((*posX)+PASSO_UNIT, *posY, matrizChar) == TRUE) {
            *posX += PASSO_UNIT;
        }
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        if (verificaSePodeMovimentar((*posX)-PASSO_UNIT, *posY, matrizChar) == TRUE) {
            *posX -= PASSO_UNIT;
        }
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        if (verificaSePodeMovimentar(*posX, (*posY)-PASSO_UNIT, matrizChar) == TRUE) {
            *posY -= PASSO_UNIT;
        }
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        if (verificaSePodeMovimentar(*posX, (*posY)+PASSO_UNIT, matrizChar) == TRUE) {
            *posY += PASSO_UNIT;
        }
    }
    
}

int verificaSePodeMovimentar(int posX, int posY, char matrizChar[][MAX_COLUNAS]) {
    
    int numPosX = posX;
    int numPosY = posY;
    int podeMovimentar;
    
    if (matrizChar[numPosY][numPosX] == 'W') {
        podeMovimentar = FALSE;
    }
    else {
        podeMovimentar = TRUE;
    }
    
    return podeMovimentar;
}
