#include "controleBatalha.h"

void exibeBatalha(Estado *save, int isSelvagem, int numInimigo) {
    
    int estadoTela = TELA_INICIO_INTERACAO;
    int naBatalha = TRUE;
    int numInfmonJogador = 0;
    int numInfmonInimigo = 0;
    int turno = 1;
    Infmon infmonSelvagem;
    
    Image imagemInfTerra = LoadImage("./terra.png");
    Texture2D texturaInfTerra = LoadTextureFromImage(imagemInfTerra);
    
    Image imagemInfFogo = LoadImage("./fogo.png");
    Texture2D texturaInfFogo = LoadTextureFromImage(imagemInfFogo);
    
    Image imagemInfAgua = LoadImage("./agua.png");
    Texture2D texturaInfAgua = LoadTextureFromImage(imagemInfAgua);
    
    if (isSelvagem == TRUE) {
        infmonSelvagem = criaInfmonAleatorio();
    }
    else {
        save->inimigos[numInimigo].infmons[0] = criaInfmonAleatorio();
        save->inimigos[numInimigo].infmons[1] = criaInfmonAleatorio();
        save->inimigos[numInimigo].infmons[2] = criaInfmonAleatorio();
    }
    

    while(!WindowShouldClose() && naBatalha == TRUE){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        if (isSelvagem == TRUE) {
            
            elementosTelaInteracao(&estadoTela , &numInfmonJogador, &naBatalha, &save->jogador.infmons[numInfmonJogador], &infmonSelvagem, save, &turno, isSelvagem);
            
            if (turno % 2 == 0) {
                acaoInimigo(&turno, save, &infmonSelvagem, &numInfmonJogador, &naBatalha);
            }
            
            //inimigo
            desenhaInfmon(650, 100, infmonSelvagem, texturaInfTerra, texturaInfFogo, texturaInfAgua);
            
        }
        else {
            
            elementosTelaInteracao(&estadoTela , &numInfmonJogador, &naBatalha, &save->jogador.infmons[numInfmonJogador], &save->inimigos[numInimigo].infmons[numInfmonInimigo], save, &turno, isSelvagem);
            
            if (turno % 2 == 0) {
                acaoInimigo(&turno, save, &save->inimigos[numInimigo].infmons[numInfmonInimigo], &numInfmonJogador, &naBatalha);
            }
            
            //inimigo
            desenhaInfmon(650, 100, save->inimigos[numInimigo].infmons[numInfmonInimigo], texturaInfTerra, texturaInfFogo, texturaInfAgua);
            
            selecionaProximoInfmonInimigo(save, &numInfmonInimigo, numInimigo, numInfmonJogador, &naBatalha);
            
        }
        
        //jogador
        desenhaInfmon(150, 350, save->jogador.infmons[numInfmonJogador], texturaInfTerra, texturaInfFogo, texturaInfAgua);

        EndDrawing();
        
        condicaoSaida(infmonSelvagem, save, &naBatalha, isSelvagem, numInimigo);
    }
    
    if (infmonSelvagem.vida <= 0 && isSelvagem == TRUE) {
        
        ganhaExpVitoria(&save->jogador.infmons[numInfmonJogador], infmonSelvagem);
        verificaSubirNivel(&save->jogador.infmons[numInfmonJogador]);
        
    }
    
    restauraVidaInfmonsJogador(save);
    
}

void acaoInimigo(int *turno, Estado *save, Infmon *infInimigo, int *numInfmonJogador, int *naBatalha) {
    
    int numAtaque = rand() % 3;
    int i;
    int achouInfmonSubstituto = FALSE;
    
    atacar(infInimigo, &save->jogador.infmons[*numInfmonJogador], numAtaque);
    
    (*turno)++;
    
    if (save->jogador.infmons[*numInfmonJogador].vida <= 0) {
        
        i=0;
        while (i<(save->jogador.numInfmons) && achouInfmonSubstituto == FALSE) {
            
            if (save->jogador.infmons[i].vida > 0) {
                
                *numInfmonJogador = i;
                achouInfmonSubstituto = TRUE;
            }
            
            i++;
            
        }
        
        if (achouInfmonSubstituto == FALSE) {
            *naBatalha = FALSE;
        }
        
    }
    
}

void restauraVidaInfmonsJogador(Estado *save) {
    
    int i;
    
    for (i=0; i<(save->jogador.numInfmons); i++) {
        
        defineVida(&save->jogador.infmons[i]);
        
    }
    
}

void condicaoSaida(Infmon infmonSelvagem, Estado *save, int *naBatalha, int isSelvagem, int numInimigo) {
    
    if (isSelvagem == TRUE) {
        
        if (infmonSelvagem.vida <= 0) {
            *naBatalha = FALSE;
        }
        
    }
    else {
        
        if (save->inimigos[numInimigo].infmons[2].vida <= 0) {
            *naBatalha = FALSE;
            save->inimigos[numInimigo].ativo = FALSE;
        }
        
    }
    
}

void selecionaProximoInfmonInimigo(Estado *save, int *numInfmonInimigo, int numInimigo, int numInfmonJogador, int *naBatalha) {
    
    if (save->inimigos[numInimigo].infmons[*numInfmonInimigo].vida <= 0 && *numInfmonInimigo < 2) {
        
        ganhaExpVitoria(&save->jogador.infmons[numInfmonJogador], save->inimigos[numInimigo].infmons[*numInfmonInimigo]);
        verificaSubirNivel(&save->jogador.infmons[numInfmonJogador]);
        
        (*numInfmonInimigo)++;
        save->inimigos[numInimigo].infmons[*numInfmonInimigo] = criaInfmonAleatorio();
    }
    else if (save->inimigos[numInimigo].infmons[*numInfmonInimigo].vida <= 0 && *numInfmonInimigo == 2){
        
        ganhaExpVitoria(&save->jogador.infmons[numInfmonJogador], save->inimigos[numInimigo].infmons[*numInfmonInimigo]);
        verificaSubirNivel(&save->jogador.infmons[numInfmonJogador]);
    
    }
    
}
