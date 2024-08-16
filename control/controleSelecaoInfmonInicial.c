//
//  controleSelecaoInfmonInicial.c
//  INFmon
//
//  Created by Gustavo Machado Silva on 06/08/24.
//

#include "controleSelecaoInfmonInicial.h"

void exibeSelecaoInfmonInicial(void) {
    
    int comecarJogo = FALSE;
    int tipoInfmon = TIPO_AGUA;
    
    while(!WindowShouldClose() && comecarJogo == FALSE) {
        
        tipoInfmon = selecionaTipoInfmonInicial(&comecarJogo);
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        telaSelecaoInfmonInicial();
        EndDrawing();
    }
    
    if (comecarJogo == TRUE) {
        
        Infmon infmonInicial = criaPrimeiroInfmonJogador(tipoInfmon);
        Estado save = criaSaveInicial(infmonInicial);
        
        exibeMapa(&save);
    }
    
}

int selecionaTipoInfmonInicial(int *comecarJogo) {
    
    int tipoInfmon = TIPO_AGUA;
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    if (IsKeyPressed(KEY_A) || (mouseX >= 200 && mouseX <= 300 && mouseY >= 270 && mouseY <= 370 && IsMouseButtonPressed(0))) {
        *comecarJogo = TRUE;
        tipoInfmon = TIPO_AGUA;
    }
    else if (IsKeyPressed(KEY_B) || (mouseX >= 550 && mouseX <= 650 && mouseY >= 270 && mouseY <= 370 && IsMouseButtonPressed(0))) {
        *comecarJogo = TRUE;
        tipoInfmon = TIPO_FOGO;
    }
    else if (IsKeyPressed(KEY_C) || (mouseX >= 900 && mouseX <= 1000 && mouseY >= 270 && mouseY <= 370 && IsMouseButtonPressed(0))) {
        *comecarJogo = TRUE;
        tipoInfmon = TIPO_TERRA;
    }
    
    return tipoInfmon;
    
}
