#include "visualMapa.h"

void preencheTelaComElementosMapa(char matrizJogo[][MAX_COLUNAS], Estado save, Texture2D texturaChao, Texture2D texturaGrama, Texture2D texturaArvore) {
    
    int i, j, k, l, m;
    char novaMatriz[10][20] = {};
    int achouInimigo;
    
    k=-1;
    l=-1;
    
    for (i=(save.jogador.posicao.y - 5); i<=(save.jogador.posicao.y + 4); i++) {
        k++;
        for (j=(save.jogador.posicao.x - 10); j<=(save.jogador.posicao.x + 9); j++) {
            l++;
            if (i>=0 && i<MAX_LINHAS && j>=0 && j<MAX_COLUNAS) {
                
                if (matrizJogo[i][j] == 'E') {
                    m = 0;
                    achouInimigo = FALSE;
                    while (m<MAX_INIMIGOS && achouInimigo == FALSE) {
                        
                        if (i == save.inimigos[m].posicao.y && j == save.inimigos[m].posicao.x && save.inimigos[m].ativo == ATIVO) {
                            achouInimigo = TRUE;
                        }
                        
                        m++;
                    }
                    
                    if (achouInimigo == TRUE) {
                        novaMatriz[k][l] = 'E';
                    }
                    else {
                        novaMatriz[k][l] = ' ';
                    }
                }
                else {
                    novaMatriz[k][l] = matrizJogo[i][j];
                }
                
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

void desenhaJogador(void) {
    DrawRectangle(X_INICIAL, Y_INICIAL, LARGURA_QUADRADO, ALTURA_QUADRADO, BLUE);
}




