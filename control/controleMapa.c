#include "controleMapa.h"

void exibeMapa(Estado *save) {
    
    srand(time(NULL));
    
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
    
    Image imagemJogador = LoadImage("./jogador.png");
    Texture2D texturaJogador = LoadTextureFromImage(imagemJogador);
    
    Image imagemInimigo = LoadImage("./inimigo.png");
    Texture2D texturaInimigo = LoadTextureFromImage(imagemInimigo);
    
    while (!WindowShouldClose() && estadoTela != SAINDO && estadoTela != TELA_FINAL && estadoTela != TELA_MENU) {
       
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        preencheTelaComElementosMapa(matrizJogo, *save, texturaChao, texturaGrama, texturaArvore, texturaInimigo);
        
        desenhaJogador(texturaJogador);
        
        if (IsKeyPressed(KEY_TAB)) {
            jogoPausado = TRUE;
        }
        
        if (jogoPausado == FALSE) {
            movimentaJogador(save, matrizJogo);
            estadoTela = TELA_PAUSE;
        }
        else {
            exibeMenuPause(&jogoPausado, &estadoTela, save, matrizJogo);
        }
        
        EndDrawing();
        
        verificaPassarMapa(save, matrizJogo, &estadoTela);
        
    }
    
    if (estadoTela == TELA_FINAL) {
        exibeTelaFinal();
    }
    else if (estadoTela == TELA_MENU) {
        exibeTelaInicial();
    }

}

void movimentaJogador(Estado *save, char matrizChar[][MAX_COLUNAS]) {
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        if (verificaSePodeMovimentar((save->jogador.posicao.x)+PASSO_UNIT, save->jogador.posicao.y, matrizChar) == TRUE) {
            save->jogador.posicao.x += PASSO_UNIT;
            verificaEncontrouInfmonSelvagem(save, matrizChar);
            verificaEncontrouInimigo(save, matrizChar);
        }
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        if (verificaSePodeMovimentar((save->jogador.posicao.x)-PASSO_UNIT, save->jogador.posicao.y, matrizChar) == TRUE) {
            save->jogador.posicao.x -= PASSO_UNIT;
            verificaEncontrouInfmonSelvagem(save, matrizChar);
            verificaEncontrouInimigo(save, matrizChar);
        }
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        if (verificaSePodeMovimentar(save->jogador.posicao.x, (save->jogador.posicao.y)-PASSO_UNIT, matrizChar) == TRUE) {
            save->jogador.posicao.y -= PASSO_UNIT;
            verificaEncontrouInfmonSelvagem(save, matrizChar);
            verificaEncontrouInimigo(save, matrizChar);
        }
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        if (verificaSePodeMovimentar(save->jogador.posicao.x, (save->jogador.posicao.y)+PASSO_UNIT, matrizChar) == TRUE) {
            save->jogador.posicao.y += PASSO_UNIT;
            verificaEncontrouInfmonSelvagem(save, matrizChar);
            verificaEncontrouInimigo(save, matrizChar);
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

void verificaEncontrouInfmonSelvagem(Estado *save, char matrizChar[][MAX_COLUNAS]) {
    
    int valor = rand() % 100;
    int posX = save->jogador.posicao.x;
    int posY = save->jogador.posicao.y;
    
    if (valor == 2 && matrizChar[posY][posX] == 'G') {
        
        exibeBatalha(save, TRUE, 3);
        
    }
    
}

void verificaEncontrouInimigo(Estado *save, char matrizChar[][MAX_COLUNAS]) {
    
    int posX = save->jogador.posicao.x;
    int posY = save->jogador.posicao.y;
    int i;
    int encontrouInimigo = FALSE;
    int inimigoAtivo = FALSE;
    int numInimigo = 3;
    
    if (matrizChar[posY][posX] == 'E') {
        
        i=0;
        while (i < save->numInimigos && encontrouInimigo == FALSE) {
            
            if (save->inimigos[i].posicao.x == posX && save->inimigos[i].posicao.y == posY) {
                
                encontrouInimigo = TRUE;
                
                if (save->inimigos[i].ativo == TRUE) {
                    inimigoAtivo = TRUE;
                    numInimigo = i;
                }
                
            }
            
            i++;
        }
        
        if (encontrouInimigo == TRUE && inimigoAtivo == TRUE) {
            
            exibeBatalha(save, FALSE, numInimigo);
            
        }
        
    }
    
}


void verificaPassarMapa(Estado *save, char matrizJogo[][MAX_COLUNAS], int *estadoTela) {
    
    int i;
    int devePassar = TRUE;
    char fileName[MAX_CHAR];
    
    i=0;
    while (i < (save->numInimigos) && devePassar == TRUE) {
        
        if (save->inimigos[i].ativo == TRUE) {
            devePassar = FALSE;
        }
        
        i++;
        
    }
    
    if (devePassar == TRUE) {
        if (passaParaProximoMapa(save) == TRUE) {
            identificaNomeMapa(fileName, *save);
            leArquivoMapa(matrizJogo, fileName);
        }
        else {
            *estadoTela = TELA_FINAL;
        }
        
    }
    
}
