#include "visualMapa.h"

void exibeMapa(void) {
    
    
    char matrizChar[MAX_LINHAS][MAX_COLUNAS];
    int i,j;
    int posX = 0;
    int posY = 0;
    
    leArquivoMapa(matrizChar);
    
    Image imagemChao = LoadImage("./chao.png");
    Texture2D texturaChao = LoadTextureFromImage(imagemChao);
    
    Image imagemGrama = LoadImage("./grama.png");
    Texture2D texturaGrama = LoadTextureFromImage(imagemGrama);
    
    Image imagemArvore = LoadImage("./arvore.png");
    Texture2D texturaArvore = LoadTextureFromImage(imagemArvore);
    
    
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
        
        preencheTelaComElementosMapa(matrizChar, posX, posY, texturaChao, texturaGrama, texturaArvore);
        
        movimentaJogador(&posX, &posY, matrizChar);
        DrawRectangle(X_INICIAL, Y_INICIAL, LARGURA_QUADRADO, ALTURA_QUADRADO, BLUE);
        
        EndDrawing();
        
    }

}

void leArquivoMapa(char matrizChar[][MAX_COLUNAS]) {
    
    char *filename = "./mapas/mapa1.txt";
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

void preencheTelaComElementosMapa(char matrizChar[][MAX_COLUNAS], int posX, int posY, Texture2D texturaChao, Texture2D texturaGrama, Texture2D texturaArvore) {
    
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
    
    for (i=0; i<MAX_LINHAS; i++) {
        for (j=0; j<MAX_COLUNAS; j++) {
            DrawTexture(texturaChao, j*PASSO, i*PASSO, WHITE);
            DrawTexture(texturaArvore, j*PASSO, i*PASSO, WHITE);
        }
    }
    
    for (i=0; i<10; i++) {
        for (j=0; j<20; j++) {
            if (novaMatriz[i][j] == 'W') {
//                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, BLACK);
                DrawTexture(texturaChao, j*PASSO, i*PASSO, WHITE);
                DrawTexture(texturaArvore, j*PASSO, i*PASSO, WHITE);
            }
            else if (novaMatriz[i][j] == 'G') {
//                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, GREEN);
                DrawTexture(texturaChao, j*PASSO, i*PASSO, WHITE);
                DrawTexture(texturaGrama, j*PASSO, i*PASSO, WHITE);
            }
            else if (novaMatriz[i][j] == 'E') {
                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, RED);
            }
            else if (novaMatriz[i][j] == ' ' || novaMatriz[i][j] == 'J'){
//                DrawRectangle(j*PASSO, i*PASSO, LARGURA_QUADRADO, ALTURA_QUADRADO, WHITE);
                DrawTexture(texturaChao, j*PASSO, i*PASSO, WHITE);
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
