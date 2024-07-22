#include "controleTelaInicial.h"
#include "../view/telaInicial.h"
#include "../view/visualMapa.h"
#include "raylib.h"

#define TRUE 1
#define FALSE 0

#define BOTAO_NOVO_JOGO 'N'

void exibeTelaInicial(void) {
    
    char botaoPressionado;
    Color backgroundColor = RAYWHITE;
    int naTelaInicial = TRUE;
    
    while (!WindowShouldClose() && naTelaInicial == TRUE) {
        
        verificaBotaoPressionado(&botaoPressionado);
        
        BeginDrawing();
        ClearBackground(backgroundColor);
        elementosDaTela();
        
        executaAcaoBotaoPressionado(&botaoPressionado, &naTelaInicial);
        
        EndDrawing();
        
    }
    
    if (naTelaInicial == FALSE) {
        exibeMapa();
    }
    
    
}

void verificaBotaoPressionado(char *botaoPressionado) {
    
    if (IsKeyPressed(KEY_N)) {
        *botaoPressionado = BOTAO_NOVO_JOGO;
    }
    
}

void executaAcaoBotaoPressionado(char *botaoPressionado, int *naTelaInicial) {
    
    if (*botaoPressionado == BOTAO_NOVO_JOGO) {
        criarNovoJogo(naTelaInicial);
        
    }
    
}

void criarNovoJogo(int *naTelaInicial) {
    
    telaCriarNovoJogo();
    
    if (IsKeyPressed(KEY_S)) {
        *naTelaInicial = FALSE;
    }
}
