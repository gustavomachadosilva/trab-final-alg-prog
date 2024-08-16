#include "raylib.h"
#include "controleTelaInicial.h"

#define LARGURA 1200
#define ALTURA 600
#define FPS 60
#define TITULO_TELA "INFmon"

void inicializaTela(void);

int main(void) {
    
    inicializaTela();
    exibeTelaInicial();
    CloseWindow();
    
    return 0;
}

void inicializaTela(void) {
    InitWindow(LARGURA, ALTURA, TITULO_TELA);
    SetTargetFPS(FPS);
}


