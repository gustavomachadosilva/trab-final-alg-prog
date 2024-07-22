#include "raylib.h"
#include "telaInicial.h"

#define MAX_CHAR 50

#define TITULO_JOGO "INFmon"
#define POSICAO_TITULO_X 500
#define POSICAO_TITULO_Y 70
#define TAMANHO_FONTE_TITULO 60

#define LARGURA_BOTAO 400
#define ALTURA_BOTAO 100
#define ESPESSURA_LINHA 3
#define TAMANHO_FONTE_BOTAO 30

#define TRUE 1
#define FALSE 0

void elementosDaTela(void) {
    
    DrawText(TITULO_JOGO, POSICAO_TITULO_X, POSICAO_TITULO_Y, TAMANHO_FONTE_TITULO, BLACK);
    botao("Novo Jogo", 190, 120, 30);
    botao("Carregar Jogo", 320, 100, 30);
    botao("Sair", 450, 180, 30);
    
}

void botao(char text[MAX_CHAR], int posY, int addXtext, int addYtext) {
    
    Rectangle rec = { ((float)GetScreenWidth() - LARGURA_BOTAO)/2, posY, (float)LARGURA_BOTAO, (float)ALTURA_BOTAO };
    
    DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
    DrawText(text, rec.x + addXtext, rec.y + addYtext, TAMANHO_FONTE_BOTAO, BLACK);

}

void telaCriarNovoJogo(void) {
    
    Rectangle rec = { ((float)GetScreenWidth() - 400)/2, ((float)GetScreenHeight() - 400)/2, (float)400, (float)400 };
    
    DrawRectangleRec(rec, WHITE);
    DrawRectangleLinesEx(rec, 3.0, BLACK);
    
}
