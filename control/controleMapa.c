#include "controleMapa.h"

void exibeMapa(Estado *save) {
    
    char matrizJogo[MAX_LINHAS][MAX_COLUNAS];
    char fileName[MAX_CHAR];
    int jogoPausado = FALSE;
    int estadoTela = TELA_PAUSE;
    
    identificaNomeMapa(fileName, *save);
    leArquivoMapa(matrizJogo, fileName);
    
    Image imagemChao = LoadImage("./chao.png");
    Texture2D texturaChao = LoadTextureFromImage(imagemChao);
    
    Image imagemGrama = LoadImage("./grama.png");
    Texture2D texturaGrama = LoadTextureFromImage(imagemGrama);
    
    Image imagemArvore = LoadImage("./arvore.png");
    Texture2D texturaArvore = LoadTextureFromImage(imagemArvore);
    
    while (!WindowShouldClose() && estadoTela != SAINDO) {
       
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        preencheTelaComElementosMapa(matrizJogo, *save, texturaChao, texturaGrama, texturaArvore);
        
        desenhaJogador();
        
        if (IsKeyPressed(KEY_TAB)) {
            jogoPausado = TRUE;
        }
        
        if (jogoPausado == FALSE) {
            movimentaJogador(save, matrizJogo);
            estadoTela = TELA_PAUSE;
        }
        else {
            exibeMenuPause(&jogoPausado, &estadoTela, save);
        }
        
        EndDrawing();
        
    }

}

void movimentaJogador(Estado *save, char matrizChar[][MAX_COLUNAS]) {
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        if (verificaSePodeMovimentar((save->jogador.posicao.x)+PASSO_UNIT, save->jogador.posicao.y, matrizChar) == TRUE) {
            save->jogador.posicao.x += PASSO_UNIT;
        }
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        if (verificaSePodeMovimentar((save->jogador.posicao.x)-PASSO_UNIT, save->jogador.posicao.y, matrizChar) == TRUE) {
            save->jogador.posicao.x -= PASSO_UNIT;
        }
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        if (verificaSePodeMovimentar(save->jogador.posicao.x, (save->jogador.posicao.y)-PASSO_UNIT, matrizChar) == TRUE) {
            save->jogador.posicao.y -= PASSO_UNIT;
        }
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        if (verificaSePodeMovimentar(save->jogador.posicao.x, (save->jogador.posicao.y)+PASSO_UNIT, matrizChar) == TRUE) {
            save->jogador.posicao.y += PASSO_UNIT;
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


