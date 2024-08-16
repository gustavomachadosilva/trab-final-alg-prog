#include "controlePause.h"

void exibeMenuPause(int *jogoPausado, int *estadoTela, Estado *save) {
    
//    int estadoTela = TELA_PAUSE;

//    while(!WindowShouldClose() && estadoTela != TELA_JOGO){
//        BeginDrawing();
//        ClearBackground(RAYWHITE);

        jogoRolando(estadoTela, save);

//        EndDrawing();
//    }
    
    if (*estadoTela == TELA_JOGO || *estadoTela == SAINDO) {
        *jogoPausado = FALSE;
    }
    
}
