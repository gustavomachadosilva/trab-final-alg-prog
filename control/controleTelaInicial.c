#include "controleTelaInicial.h"

void exibeTelaInicial(void) {
    
    char botaoPressionado;
    Color backgroundColor = RAYWHITE;
    int naTelaInicial = TRUE;
    
    while (!WindowShouldClose() && naTelaInicial == TRUE) {
        
        verificaBotaoPressionado(&botaoPressionado);
        
        BeginDrawing();
        ClearBackground(backgroundColor);
        desenhaElementosTela();
        
        executaAcaoBotaoPressionado(&botaoPressionado, &naTelaInicial);
        
        EndDrawing();
        
    }
    
    if (naTelaInicial == FALSE) {
        exibeSelecaoInfmonInicial();
    }
    
    
}

void desenhaElementosTela(void) {
    
    Color botaoN = WHITE;
    Color botaoC = WHITE;
    Color botaoS = WHITE;
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    if (mouseX > 400 && mouseX < 800 && mouseY > 190 && mouseY < 290) {
        botaoN = GRAY;
    }

    if (mouseX > 400 && mouseX < 800 && mouseY > 320 && mouseY < 420) {
        botaoC = GRAY;
    }
    
    if (mouseX > 400 && mouseX < 800 && mouseY > 450 && mouseY < 550) {
        botaoS = GRAY;
    }
    
    elementosDaTela(botaoN, botaoC, botaoS);
    
}

void verificaBotaoPressionado(char *botaoPressionado) {
    
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    if (IsKeyPressed(KEY_N) || (mouseX > 400 && mouseX < 800 && mouseY > 190 && mouseY < 290 && IsMouseButtonPressed(0))) {
        *botaoPressionado = BOTAO_NOVO_JOGO;
    }
    
    
    
}

void executaAcaoBotaoPressionado(char *botaoPressionado, int *naTelaInicial) {
    
    if (*botaoPressionado == BOTAO_NOVO_JOGO) {
        criarNovoJogo(naTelaInicial, botaoPressionado);
        
    }
    
}

void criarNovoJogo(int *naTelaInicial, char *botaoPressionado) {
    
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    Color corBotaoSim;
    Color corBotaoNao;
    
    if (mouseX > 450 && mouseX < 560 && mouseY > 330 && mouseY < 380) {
        corBotaoSim = GREEN;
    }
    else {
        corBotaoSim = WHITE;
    }
    
    if (mouseX > 640 && mouseX < 750 && mouseY > 330 && mouseY < 380) {
        corBotaoNao = RED;
    }
    else {
        corBotaoNao = WHITE;
    }
    
    telaCriarNovoJogo(corBotaoSim, corBotaoNao);
    
    if (IsKeyPressed(KEY_S) || (mouseX > 450 && mouseX < 560 && mouseY > 330 && mouseY < 380 && IsMouseButtonPressed(0))) {
        *naTelaInicial = FALSE;
    }
    
    if (mouseX > 640 && mouseX < 750 && mouseY > 330 && mouseY < 380 && IsMouseButtonPressed(0)) {
        *botaoPressionado = BOTAO_OUTRO;
    }
    
}
