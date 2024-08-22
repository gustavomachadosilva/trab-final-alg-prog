#include "controleTelaFinal.h"

void exibeTelaFinal(void) {
    
    int naTelaFinal = TRUE;
    
    while (!WindowShouldClose() && naTelaFinal == TRUE) {
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        elementosTelaFinal();
        
        verificaClicouSair(&naTelaFinal);
        
        EndDrawing();
        
    }
    
}

void verificaClicouSair(int *naTelaFinal) {
    
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    if (IsKeyPressed(KEY_S) || (mouseX >= 450 && mouseX <= 750 && mouseY >= 400 && mouseY <= 500 && IsMouseButtonPressed(0))) {
        *naTelaFinal = FALSE;
    }
    
}
