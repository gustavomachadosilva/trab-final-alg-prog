#include "controlePause.h"

void exibeMenuPause(int *jogoPausado, int *estadoTela, Estado *save, char matrizJogo[][MAX_COLUNAS]) {
    
//    int estadoTela = TELA_PAUSE;

//    while(!WindowShouldClose() && estadoTela != TELA_JOGO){
//        BeginDrawing();
//        ClearBackground(RAYWHITE);

        jogoRolando(estadoTela, save, matrizJogo);

//        EndDrawing();
//    }
    
    if (*estadoTela == TELA_JOGO || *estadoTela == SAINDO || *estadoTela == TELA_MENU) {
        *jogoPausado = FALSE;
    }
    
}
