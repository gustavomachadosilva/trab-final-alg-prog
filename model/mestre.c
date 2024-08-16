//
//  mestre.c
//  INFmon
//
//  Created by Gustavo Machado Silva on 26/07/24.
//

#include "mestre.h"

void salvaInfmonsJogador(Mestre jogador) {
    
    FILE *file;
    char fileName[MAX_CHAR] = "infmons.bin";
    
    file = fopen(fileName, "wb");
    
    if (file == NULL) {
        printf("Erro ao criar arquivo!\n");
    }
    else {
        
        if (fwrite(jogador.infmons, sizeof(Infmon), jogador.numInfmons, file) != jogador.numInfmons) {
            printf("Erro ao salvar infmons!\n");
        }
        
        fclose(file);
    }
    
}

void carregaInfmonsJogador(Mestre jogador) {
    
    FILE *file;
    char fileName[MAX_CHAR] = "infmons.bin";
    
    file = fopen(fileName, "rb");
    
    if (file == NULL) {
        printf("Arquivo nao encontrado!\n");
    }
    else {
        
        if (fread(jogador.infmons, sizeof(Infmon), jogador.numInfmons, file) != jogador.numInfmons) {
            printf("Erro ao ler infmons!\n");
        }
        
        fclose(file);
    }
    
}

//void capturaInfmon(Mestre *jogador, Infmon infmon) {
//    
//    if (jogador->numInfmons == MAX_INFMONS) {
//        printf("Nao eh possivel capturar mais infmons!\n");
//    }
//    else {
//        
//        jogador->infmons[jogador->numInfmons] = infmon;
//        jogador->numInfmons++;
//        
//    }
//    
//}
