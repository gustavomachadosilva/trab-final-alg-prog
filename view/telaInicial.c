#include "raylib.h"

#define MAX_CHAR 50

#define LARGURA 1200
#define ALTURA 600
#define FPS 60
#define TITULO_TELA "INFmon"

#define TITULO_JOGO "INFmon"
#define POSICAO_TITULO_X 500
#define POSICAO_TITULO_Y 70
#define TAMANHO_FONTE_TITULO 60

#define LARGURA_BOTAO 400
#define ALTURA_BOTAO 100
#define ESPESSURA_LINHA 3
#define TAMANHO_FONTE_BOTAO 30

void inicializaTela(void);
void lacoPrincipal(void);
void elementosDaTela(int nPressionado, Color *ptrBackgroundColor);
void botao(char text[MAX_CHAR], int posY, int addXtext, int addYtext);
void criarNovoJogo(void);

void inicializaTela(void) {
    InitWindow(LARGURA, ALTURA, TITULO_TELA);
    SetTargetFPS(FPS);
}

void lacoPrincipal(void) {
    
    int nPressionado = 0;
    Color backgroundColor = RAYWHITE;
    
    while (!WindowShouldClose()) {
        
        if (IsKeyPressed(KEY_N)) {
            nPressionado = 1;
        }

        BeginDrawing();
        ClearBackground(backgroundColor);
        elementosDaTela(nPressionado, &backgroundColor);
        EndDrawing();
        
    }
    
}

void elementosDaTela(int nPressionado, Color *ptrBackgroundColor) {
    
    DrawText(TITULO_JOGO, POSICAO_TITULO_X, POSICAO_TITULO_Y, TAMANHO_FONTE_TITULO, BLACK);
    botao("Novo Jogo", 190, 120, 30);
    botao("Carregar Jogo", 320, 100, 30);
    botao("Sair", 450, 180, 30);
    
    if (nPressionado == 1) {
        criarNovoJogo();
        *ptrBackgroundColor = LIGHTGRAY;
    }
    
}

void botao(char text[MAX_CHAR], int posY, int addXtext, int addYtext) {
    
    Rectangle rec = { ((float)GetScreenWidth() - LARGURA_BOTAO)/2, posY, (float)LARGURA_BOTAO, (float)ALTURA_BOTAO };
    
    DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
    DrawText(text, rec.x + addXtext, rec.y + addYtext, TAMANHO_FONTE_BOTAO, BLACK);

}

void criarNovoJogo(void) {
    
    Rectangle rec = { ((float)GetScreenWidth() - 400)/2, ((float)GetScreenHeight() - 400)/2, (float)400, (float)400 };
    
    DrawRectangleRec(rec, WHITE);
    DrawRectangleLinesEx(rec, 3.0, BLACK);
    
}
