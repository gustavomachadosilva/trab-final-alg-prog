#include "telaBatalha.h"

void botaoTelaInteracao(char text[], int posX, int posY, int addXtext, int addYtext) {

   Rectangle rec = {posX, posY, (float)LARGURA_BOTAO, (float)ALTURA_BOTAO};
   DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
   DrawText(text, rec.x + addXtext, rec.y + addYtext, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK);

}

void botaoTelaAtaques(char text[], int posX, int posY, int addXtext, int addYtext) {

   Rectangle rec = {posX, posY, (float)LARGURA_BOTAO, (float)ALTURA_BOTAO};
   DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
   DrawText(text, rec.x + addXtext, rec.y + addYtext, TAMANHO_FONTE_BOTAO_ATAQUES, BLACK);

}

void abrirSubmenuAtaques(int *estadoTela, Infmon *atacante, Infmon *atacado, int *turno){

   DrawRectangleLines(700, 350, LARGURA_TELA_BOTAO, ALTURA_TELA_BOTAO, BLACK);

   botaoTelaInteracao("ATAQUE 1 (1)", 720, 370, 25, 35); //CIMA ESQUERDA
   if(IsKeyPressed(KEY_ONE)){
       printf("1\n");
       atacar(atacante, atacado, ATAQUE_LEVE);
       (*turno)++;
   }
   else if(GetMouseX()>= 720 && GetMouseX()<= 950 && GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

       DrawRectangle(720, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
       DrawText("ATAQUE 1 (1)", 745, 405, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

       if(IsMouseButtonPressed(0)){
           printf("1\n");
           atacar(atacante, atacado, ATAQUE_LEVE);
           (*turno)++;
       }
   }

   botaoTelaInteracao("ATAQUE 2 (2)", 960, 370, 30, 35); //CIMA DIREITA
   if(IsKeyPressed(KEY_TWO)){
       printf("2\n");
       atacar(atacante, atacado, ATAQUE_MEDIO);
       (*turno)++;
   }
   else if(GetMouseX()>= 960 && GetMouseX()<= 1180 &&GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

       DrawRectangle(960, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
       DrawText("ATAQUE 2 (2)", 990, 405, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK);                          // 1010 = 960 + 50 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

       if(IsMouseButtonPressed(0)){
           printf("2\n");
           atacar(atacante, atacado, ATAQUE_MEDIO);
           (*turno)++;
       }
   }

   botaoTelaInteracao("ATAQUE 3 (3)", 720, 480, 20, 35); //BAIXO ESQUERDA
   if(IsKeyPressed(KEY_THREE)){
       printf("3\n");
       atacar(atacante, atacado, ATAQUE_PESADO);
       (*turno)++;
   }

   else if(GetMouseX()>= 720 && GetMouseX()<= 940 && GetMouseY()>= 480 && GetMouseY()<= 580){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

       DrawRectangle(720, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
       DrawText("ATAQUE 3 (3)", 740, 515, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK); //  740 = 720 + 20 ; 515 = 480 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

       if(IsMouseButtonPressed(0)){
           printf("3\n");
           atacar(atacante, atacado, ATAQUE_PESADO);
           (*turno)++;
       }
   }

   botaoTelaInteracao("VOLTAR (V)", 960, 480, 30, 35); //BAIXO DIREITA

   if(IsKeyPressed(KEY_V)){
       *estadoTela = TELA_INICIO_INTERACAO;
   }
   else if(GetMouseX()>= 960 && GetMouseX()<= 1180 && GetMouseY()>= 480 && GetMouseY()<= 580){     // verifica se o mouse esta dentro do botao, se estiver, muda de cor

       DrawRectangle(960, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
       DrawText("VOLTAR (V)", 990, 515, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK); // 990 = 960 + 30 ; 515 = 480 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

       if(IsMouseButtonPressed(0)){
           *estadoTela = TELA_INICIO_INTERACAO;
       }
   }

}


void abrirSubmenuTrocas(int *estadoTela, int *infmonAtual, Estado *save, int *turno){
   int numInfMon;
   numInfMon = save->jogador.numInfmons;

   DrawRectangleLines(700, 350, LARGURA_TELA_BOTAO, ALTURA_TELA_BOTAO, BLACK);

   switch(numInfMon){

       case 1:
           botaoTelaInteracao("INFMON 1 (1)", 720, 370, 25, 35); //CIMA ESQUERDA
           if(IsKeyPressed(KEY_ONE)){
               printf("1\n");
               *infmonAtual = 0;
               (*turno)++;
           }
           else if(GetMouseX()>= 720 && GetMouseX()<= 950 && GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(720, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("INFMON 1 (1)", 745, 405, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

               if(IsMouseButtonPressed(0)){
                   printf("1\n");
                   *infmonAtual = 0;
                   (*turno)++;
               }
           }

           botaoTelaInteracao(" ", 960, 370, 50, 35); //CIMA DIREITA

           botaoTelaInteracao(" ", 720, 480, 20, 35); //BAIXO ESQUERDA

           botaoTelaInteracao("VOLTAR (V)", 960, 480, 30, 35); //BAIXO DIREITA
           if(IsKeyPressed(KEY_V)){
               *estadoTela = TELA_INICIO_INTERACAO;
           }
           else if(GetMouseX()>= 960 && GetMouseX()<= 1180 && GetMouseY()>= 480 && GetMouseY()<= 580){
               DrawRectangle(960, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("VOLTAR (V)", 990, 515, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);

               if(IsMouseButtonPressed(0)){
                   *estadoTela = TELA_INICIO_INTERACAO;
               }
           }
           break;

       case 2:
           botaoTelaInteracao("INFMON 1 (1)", 720, 370, 25, 35); //CIMA ESQUERDA
           if(IsKeyPressed(KEY_ONE)){
               printf("1\n");
               *infmonAtual = 0;
               (*turno)++;
           }
           else if(GetMouseX()>= 720 && GetMouseX()<= 950 && GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(720, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("INFMON 1 (1)", 745, 405, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

               if(IsMouseButtonPressed(0)){
                   printf("1\n");
                   *infmonAtual = 0;
                   (*turno)++;
               }
           }

           botaoTelaInteracao("INFMON 2 (2)", 960, 370, 30, 35); //CIMA DIREITA
           if(IsKeyPressed(KEY_TWO)){
               printf("2\n");
               *infmonAtual = 1;
               (*turno)++;
           }
           else if(GetMouseX()>= 960 && GetMouseX()<= 1180 &&GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(960, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("INFMON 2 (2)", 990, 405, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);                          // 1010 = 960 + 50 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

               if(IsMouseButtonPressed(0)){
                   printf("2\n");
                   *infmonAtual = 1;
                   (*turno)++;
               }
           }

           botaoTelaInteracao(" ", 720, 480, 20, 35); //BAIXO ESQUERDA

           botaoTelaInteracao("VOLTAR (V)", 960, 480, 30, 35); //BAIXO DIREITA
           if(IsKeyPressed(KEY_V)){
               *estadoTela = TELA_INICIO_INTERACAO;
           }
           else if(GetMouseX()>= 960 && GetMouseX()<= 1180 && GetMouseY()>= 480 && GetMouseY()<= 580){
               DrawRectangle(960, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("VOLTAR (V)", 990, 515, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);

               if(IsMouseButtonPressed(0)){
                   *estadoTela = TELA_INICIO_INTERACAO;
               }
           }
           break;

       case 3:
           botaoTelaInteracao("INFMON 1 (1)", 720, 370, 25, 35); //CIMA ESQUERDA
           if(IsKeyPressed(KEY_ONE)){
               printf("1\n");
               *infmonAtual = 0;
               (*turno)++;
           }
           else if(GetMouseX()>= 720 && GetMouseX()<= 950 && GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(720, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("INFMON 1 (1)", 745, 405, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

               if(IsMouseButtonPressed(0)){
                   printf("1\n");
                   *infmonAtual = 0;
                   (*turno)++;
               }
           }

           botaoTelaInteracao("INFMON 2 (2)", 960, 370, 30, 35); //CIMA DIREITA
           if(IsKeyPressed(KEY_TWO)){
               printf("2\n");
               *infmonAtual = 1;
               (*turno)++;
           }
           else if(GetMouseX()>= 960 && GetMouseX()<= 1180 &&GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(960, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("INFMON 2 (2)", 990, 405, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);                          // 1010 = 960 + 50 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

               if(IsMouseButtonPressed(0)){
                   printf("2\n");
                   *infmonAtual = 1;
                   (*turno)++;
               }
           }

           botaoTelaInteracao("INFMON 3 (3)", 720, 480, 20, 35); //BAIXO ESQUERDA
           if(IsKeyPressed(KEY_THREE)){
               printf("3\n");
               *infmonAtual = 2;
               (*turno)++;
           }
           else if(GetMouseX()>= 720 && GetMouseX()<= 940 && GetMouseY()>= 480 && GetMouseY()<= 580){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(720, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("INFMON 3 (3)", 740, 515, TAMANHO_FONTE_BOTAO_TROCAS, BLACK); //  740 = 720 + 20 ; 515 = 480 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

                if(IsMouseButtonPressed(0)){
                    printf("3\n");
                    *infmonAtual = 2;
                    (*turno)++;
               }
           }

           botaoTelaInteracao("VOLTAR (V)", 960, 480, 30, 35); //BAIXO DIREITA
           if(IsKeyPressed(KEY_V)){
               *estadoTela = TELA_INICIO_INTERACAO;
           }
           else if(GetMouseX()>= 960 && GetMouseX()<= 1180 && GetMouseY()>= 480 && GetMouseY()<= 580){
               DrawRectangle(960, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("VOLTAR (V)", 990, 515, TAMANHO_FONTE_BOTAO_TROCAS, BLACK);

               if(IsMouseButtonPressed(0)){
                   *estadoTela = TELA_INICIO_INTERACAO;
               }
           }
           break;
   }
}

void elementosTelaInteracao(int *estadoTela, int *infmonAtual, int *naBatalha, Infmon *atacante, Infmon *atacado, Estado *save, int *turno, int isSelvagem) {

    DrawRectangleLines(700, 350, LARGURA_TELA_BOTAO, ALTURA_TELA_BOTAO, BLACK);

   switch(*estadoTela){

       case TELA_INICIO_INTERACAO:

           botaoTelaInteracao("ATAQUES (A)", 720, 370, 25, 35); //CIMA ESQUERDA
           if(IsKeyPressed(KEY_A)){
              *estadoTela = TELA_ATAQUES;
           }
           else if(GetMouseX()>= 720 && GetMouseX()<= 950 && GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(720, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("ATAQUES (A)", 745, 405, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK);                            // 745 = 720 + 25 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

               if(IsMouseButtonPressed(0)){
                   *estadoTela = TELA_ATAQUES;
               }
           }

           botaoTelaInteracao("FUGIR (F)", 960, 370, 50, 35); //CIMA DIREITA

           if(IsKeyPressed(KEY_F) && isSelvagem == TRUE){
               printf("F\n");
               *naBatalha = FALSE;
           }
           else if(GetMouseX()>= 960 && GetMouseX()<= 1180 &&GetMouseY()>= 370 && GetMouseY()<= 470){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(960, 370, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("FUGIR (F)", 1010, 405, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK);                          // 1010 = 960 + 50 ; 405 = 370 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

               if(IsMouseButtonPressed(0) && isSelvagem == TRUE){
                   printf("F\n");
                   *naBatalha = FALSE;
               }
           }

           botaoTelaInteracao("CAPTURAR (C)", 720, 480, 20, 35); //BAIXO ESQUERDA
           if(IsKeyPressed(KEY_C) && isSelvagem == TRUE){
               printf("C\n");
               if (capturaInfmon(save, *atacado) == TRUE) {
                   *naBatalha = FALSE;
               }
           }
           else if(GetMouseX()>= 720 && GetMouseX()<= 940 && GetMouseY()>= 480 && GetMouseY()<= 580){      // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(720, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("CAPTURAR (C)", 740, 515, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK); //  740 = 720 + 20 ; 515 = 480 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

                if(IsMouseButtonPressed(0) && isSelvagem == TRUE){
                    printf("C\n");
                    if (capturaInfmon(save, *atacado) == TRUE) {
                        *naBatalha = FALSE;
                    }
               }
           }

           botaoTelaInteracao("TROCAR (T)", 960, 480, 30, 35); //BAIXO DIREITA

           if(IsKeyPressed(KEY_T)){
              *estadoTela = TELA_TROCAS;
           }

           else if(GetMouseX()>= 960 && GetMouseX()<= 1180 && GetMouseY()>= 480 && GetMouseY()<= 580){     // verifica se o mouse esta dentro do botao, se estiver, muda de cor

               DrawRectangle(960, 480, LARGURA_BOTAO, ALTURA_BOTAO, GRAY);
               DrawText("TROCAR (T)", 990, 515, TAMANHO_FONTE_BOTAO_INTERACAO, BLACK); // 990 = 960 + 30 ; 515 = 480 + 35 ; CALCULO PARA CENTRALIZAR O TEXTO NO BOTAO

                if(IsMouseButtonPressed(0)){
                   *estadoTela = TELA_TROCAS;
               }
           }
           break;

       case TELA_ATAQUES:
           abrirSubmenuAtaques(estadoTela, atacante, atacado, turno);

           break;

       case TELA_TROCAS:
           abrirSubmenuTrocas(estadoTela, infmonAtual, save, turno);
   }
}

void desenhaInfmon(int posX, int posY, Infmon infmon, Texture2D texturaInfTerra, Texture2D texturaInfFogo, Texture2D texturaInfAgua) {
    
    Texture2D texturaInfmon;
    
    switch (infmon.tipo) {
        case TIPO_AGUA:
            texturaInfmon = texturaInfAgua;
            break;
        case TIPO_FOGO:
            texturaInfmon = texturaInfFogo;
            break;
        case TIPO_TERRA:
            texturaInfmon = texturaInfTerra;
            break;
            
        default:
            texturaInfmon = texturaInfAgua;
    }
    
    DrawTexture(texturaInfmon, posX, posY, WHITE);
    
    desenhaVida(posX, posY, infmon);
    
}

void desenhaVida(int posX, int posY, Infmon infmon) {
    
    int maxVida = VIDA_BASE + (FATOR_VIDA * infmon.nivel);
    float fatorVida = ((float)infmon.vida / (float)maxVida);
    int xRecVida = (int)(200 * fatorVida);
    
    char lvl[20];
    
    sprintf(lvl, "lvl %d", infmon.nivel);
    
    Rectangle recVidaCheia = {posX, posY - 40, 200, 20};
    Rectangle recVida = {posX, posY - 40, xRecVida, 20};
    
    DrawRectangleRec(recVidaCheia, RED);
    DrawRectangleRec(recVida, GREEN);
    DrawRectangleLinesEx(recVidaCheia, 3, BLACK);
    
    DrawText(lvl, posX - 100, posY - 50, 40, BLACK);
}
