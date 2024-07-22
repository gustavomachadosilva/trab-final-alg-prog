#include "controleTelaInicial.h"
#include "../view/telaInicial.h"
#include "../view/visualMapa.h"
#include "raylib.h"

#define TRUE 1
#define FALSE 0

void exibeTelaInicial(void) {
    
    int nPressionado = FALSE;
    Color backgroundColor = RAYWHITE;
    int naTelaInicial = TRUE;
    
    while (!WindowShouldClose() && naTelaInicial == TRUE) {
        
        if (IsKeyPressed(KEY_N)) {
            nPressionado = TRUE;
        }

        BeginDrawing();
        ClearBackground(backgroundColor);
        elementosDaTela(nPressionado, &backgroundColor, &naTelaInicial);
        EndDrawing();
        
    }
    
    if (naTelaInicial == FALSE) {
        exibeMapa();
    }
    
}
