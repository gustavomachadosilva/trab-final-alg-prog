//
//  controleSelecaoInfmonInicial.c
//  INFmon
//
//  Created by Gustavo Machado Silva on 06/08/24.
//

#include "controleSelecaoInfmonInicial.h"

void exibeSelecaoInfmonInicial(void) {
    
    int comecarJogo = FALSE;
    
    while(!WindowShouldClose() && comecarJogo == FALSE) {
        
        if (IsKeyPressed(KEY_A)) {
            comecarJogo = TRUE;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        telaSelecaoInfmonInicial();
        EndDrawing();
    }
    
    if (comecarJogo == TRUE) {
        exibeMapa();
    }
    
}
