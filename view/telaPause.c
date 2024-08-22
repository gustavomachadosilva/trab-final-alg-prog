#include "telaPause.h"

void jogoRolando(int *estadoTela, Estado *save, char matrizJogo[][MAX_COLUNAS]){

    switch(*estadoTela){

        case TELA_JOGO:

            // "JOGO ROLANDO"
            break;

        case TELA_PAUSE:
            abrirMenuPause(estadoTela, save, matrizJogo);
            break;

        case TELA_CONFIRMACAO:
            abrirTelaConfirmacao(estadoTela);
            break;
    }
}

void abrirMenuPause(int *estadoTela, Estado *save, char matrizJogo[][MAX_COLUNAS]){
    
    char fileName[MAX_CHAR];
    Color grayFADE = Fade(GRAY, 0.8);

    DrawRectangle(0, 0, LARGURA_TELA, ALTURA_TELA, grayFADE);
    DrawRectangle(425, 145, LARGURA_TELA_PAUSE, ALTURA_TELA_PAUSE, WHITE);
//------------------------------------------------------------------------------------
    botaoTelaPause("CONTINUAR (C)", 450, 165, 30, 20 );
    if(IsKeyPressed(KEY_C)){
        *estadoTela = TELA_JOGO;
    }
    else if(GetMouseX()>= 450 && GetMouseX()<= 625 && GetMouseY()>= 165 && GetMouseY()<= 215){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

        DrawRectangle(450, 165, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE, LIGHTGRAY);
        desenhaBordaBotao(450, 165, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE);
        DrawText("CONTINUAR (C)", 480, 185, TAMANHO_FONTE_BOTAO_PAUSE, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

        if(IsMouseButtonPressed(0)){
            *estadoTela = TELA_JOGO;
        }
    }
//-----------------------------------------------------------------------------------
    botaoTelaPause(" ", 450, 225, 10, 20 );
    DrawText("CARREGAR JOGO (L)", 460, 245, TAMANHO_FONTE_BOTAO_PAUSE, BLACK);
    if(IsKeyPressed(KEY_L)){
        printf("game loaded!\n");
        carregaJogo(save);
        identificaNomeMapa(fileName, *save);
        leArquivoMapa(matrizJogo, fileName);
    }
    else if(GetMouseX()>= 450 && GetMouseX()<= 625 && GetMouseY()>= 225 && GetMouseY()<= 275){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

        DrawRectangle(450, 225, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE, LIGHTGRAY);
        desenhaBordaBotao(450, 225, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE);
        DrawText("CARREGAR JOGO (L)", 460, 245, TAMANHO_FONTE_BOTAO_PAUSE, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

        if(IsMouseButtonPressed(0)){
            printf("game loaded!\n");
            carregaJogo(save);
            identificaNomeMapa(fileName, *save);
            leArquivoMapa(matrizJogo, fileName);
        }
    }
//----------------------------------------------------------------------------------
    botaoTelaPause(" ", 450, 285, 20, 20 );
    DrawText("SALVAR JOGO (S)", 470, 305, TAMANHO_FONTE_BOTAO_PAUSE, BLACK);
    if(IsKeyPressed(KEY_S)){
        printf("saved game!\n");
        salvaJogo(save);
    }
    else if(GetMouseX()>= 450 && GetMouseX()<= 625 && GetMouseY()>= 285 && GetMouseY()<= 335){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

        DrawRectangle(450, 285, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE, LIGHTGRAY);
        desenhaBordaBotao(450, 285, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE);
        DrawText("SALVAR JOGO (S)", 470, 305, TAMANHO_FONTE_BOTAO_PAUSE, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

        if(IsMouseButtonPressed(0)){
            printf("saved game!\n");
            salvaJogo(save);
        }
    }
//----------------------------------------------------------------------------------
    botaoTelaPause(" ", 450, 345, 5, 20 );
    DrawText("VOLTAR AO MENU (B)", 455, 365, TAMANHO_FONTE_BOTAO_PAUSE - 1, BLACK);
    if(IsKeyPressed(KEY_B)){
        printf("voltando ao menu!\n");   // VOLTAR AO MENU INICIAL
        *estadoTela = TELA_MENU;
    }
    else if(GetMouseX()>= 450 && GetMouseX()<= 625 && GetMouseY()>= 345 && GetMouseY()<= 395){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

        DrawRectangle(450, 345, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE, LIGHTGRAY);
        desenhaBordaBotao(450, 345, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE);
        DrawText("VOLTAR AO MENU (B)", 455, 365, TAMANHO_FONTE_BOTAO_PAUSE - 1, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

        if(IsMouseButtonPressed(0)){
           printf("voltando ao menu!\n"); // VOLTAR AO MENU INICIAL
            *estadoTela = TELA_MENU;
        }
    }
//---------------------------------------------------------------------------------

    botaoTelaPause(" ", 450, 405, 55, 20 );
    DrawText("SAIR (Q)", 505, 425, TAMANHO_FONTE_BOTAO_PAUSE , BLACK);
    if(IsKeyPressed(KEY_Q)){
        *estadoTela = TELA_CONFIRMACAO;
    }
    else if(GetMouseX()>= 450 && GetMouseX()<= 625 && GetMouseY()>= 405 && GetMouseY()<= 455){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

        DrawRectangle(450, 405, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE, LIGHTGRAY);
        desenhaBordaBotao(450, 405, LARGURA_BOTAO_PAUSE, ALTURA_BOTAO_PAUSE);
        DrawText("SAIR (Q)", 505, 425, TAMANHO_FONTE_BOTAO_PAUSE - 1, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

        if(IsMouseButtonPressed(0)){
            *estadoTela = TELA_CONFIRMACAO;
        }
    }
}

void abrirTelaConfirmacao(int *estadoTela){

    Color grayFADE = Fade(GRAY, 0.8);

    DrawRectangle(0, 0, LARGURA_TELA, ALTURA_TELA, grayFADE);
    DrawRectangle(400, 225, LARGURA_TELA_CONFIRMACAO, ALTURA_TELA_CONFIRMACAO, WHITE);
    DrawText("Tem certeza que deseja sair do jogo?", 415, 235, TAMANHO_FONTE_BOTAO_CONFIRMACAO + 7, BLACK);
    DrawText("CUIDADO!", 535, 262, TAMANHO_FONTE_BOTAO_CONFIRMACAO + 7, RED);
    DrawText("(se confirmar, todo processo nao salvo sera perdido)", 435, 290, TAMANHO_FONTE_BOTAO_CONFIRMACAO, BLACK);
//-------------------------------------------------------------------------------------------

    DrawRectangle(480, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO, WHITE);
    desenhaBordaBotaoConfirmacao(480, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO);
    DrawText("SIM (S)", 495, 330, TAMANHO_FONTE_BOTAO_CONFIRMACAO + 2, BLACK);

    if(IsKeyPressed(KEY_S)){
        printf("SAINDO DO JOGO!\n");
        *estadoTela = SAINDO;
    }
    else if(GetMouseX()>= 480 && GetMouseX()<= 555 && GetMouseY()>= 320 && GetMouseY()<= 350){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

        DrawRectangle(480, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO, GREEN);
        desenhaBordaBotaoConfirmacao(480, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO);
        DrawText("SIM (S)", 495, 330, TAMANHO_FONTE_BOTAO_CONFIRMACAO + 2, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

        if(IsMouseButtonPressed(0)){
            printf("SAINDO DO JOGO!\n");
            *estadoTela = SAINDO;
        }
    }
//-------------------------------------------------------------------------------------------
    DrawRectangle(595, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO, WHITE);
    desenhaBordaBotaoConfirmacao(595, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO);
    DrawText("NAO (N)", 610, 330, TAMANHO_FONTE_BOTAO_CONFIRMACAO + 2, BLACK);

    if(IsKeyPressed(KEY_N)){
        *estadoTela = TELA_PAUSE;
    }
    else if(GetMouseX()>= 595 && GetMouseX()<= 670 && GetMouseY()>= 320 && GetMouseY()<= 350){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

        DrawRectangle(595, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO, RED);
        desenhaBordaBotaoConfirmacao(595, 320, LARGURA_BOTAO_CONFIRMACAO, ALTURA_BOTAO_CONFIRMACAO);
        DrawText("NAO (N)", 610, 330, TAMANHO_FONTE_BOTAO_CONFIRMACAO + 2, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

        if(IsMouseButtonPressed(0)){
           *estadoTela = TELA_PAUSE;
        }
    }
}

void botaoTelaPause(char text[], int posX, int posY, int addXtext, int addYtext) {

    Rectangle rec = {posX, posY, (float)LARGURA_BOTAO_PAUSE, (float)ALTURA_BOTAO_PAUSE};
    DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
    DrawText(text, rec.x + addXtext, rec.y + addYtext, TAMANHO_FONTE_BOTAO_PAUSE, BLACK);

}

void desenhaBordaBotao(int posX, int posY, int addXtext, int addYtext){
    Rectangle rec = {posX, posY, (float)LARGURA_BOTAO_PAUSE, (float)ALTURA_BOTAO_PAUSE};
    DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
}

void desenhaBordaBotaoConfirmacao(int posX, int posY, int addXtext, int addYtext){
    Rectangle rec = {posX, posY, (float)LARGURA_BOTAO_CONFIRMACAO, (float)ALTURA_BOTAO_CONFIRMACAO};
    DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
}
