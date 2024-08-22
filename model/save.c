#include "save.h"

int salvaJogo(Estado *save) {
    
    FILE *file;
    int foiSalvo = FALSE;
    
    file = fopen("save.bin", "wb");
    
    if (file == NULL) {
        printf("Sem armazenamento para criar arquivo!\n");
    }
    else {
        
        if (fwrite(save, sizeof(Estado), NUM_SAVES, file) != NUM_SAVES) {
            foiSalvo = TRUE;
        }
        
        fclose(file);
    }
    
    return foiSalvo;
    
}

int carregaJogo(Estado *save) {
    
    FILE *file;
    int foiCarregado = FALSE;
    
    file = fopen("save.bin", "rb");
    
    if (file == NULL) {
        printf("Arquivo nao encontrado!\n");
    }
    else {
        
        if (fread(save, sizeof(Estado), NUM_SAVES, file) != NUM_SAVES) {
            foiCarregado = TRUE;
        }
        
        fclose(file);
    }
    
    return foiCarregado;
    
}

int capturaInfmon(Estado *save, Infmon infmon) {
    
    int capturou = FALSE;
    int maxVida = VIDA_BASE + (FATOR_VIDA * infmon.nivel);
    
    if (save->jogador.numInfmons == MAX_INFMONS || (infmon.vida > (maxVida / 4))) {
        printf("Nao eh possivel capturar mais infmons!\n");
    }
    else {
        defineVida(&infmon);
        save->jogador.infmons[save->jogador.numInfmons] = infmon;
        save->jogador.numInfmons++;
        capturou = TRUE;
        printf("Infmon capturado!\n");
    }
    
    return capturou;
    
}

void identificaNomeMapa(char fileName[], Estado save) {
    
    switch (save.numMapa) {
        case MAPA_INICIAL:
            strcpy(fileName, "./mapas/limgrave.txt");
            break;
        case MAPA_2:
            strcpy(fileName, "./mapas/rayaLucaria.txt");
            break;
        case MAPA_3:
            strcpy(fileName, "./mapas/nokron.txt");
            break;
        case MAPA_4:
            strcpy(fileName, "./mapas/caelid.txt");
            break;
            
        default:
            printf("Erro ao escolher nome!\n");
            break;
    }
    
    
}

void leArquivoMapa(char matrizJogo[][MAX_COLUNAS], char fileName[]) {
    
    FILE *file;
    int i, j;
    char c;
    
    file = fopen(fileName, "r");
    
    if (file == NULL) {
        printf("Arquivo %s nao ecnontrado\n", fileName);
    }
    else {
        
        for (i=0; i<MAX_LINHAS; i++) {
            for (j=0; j<(MAX_COLUNAS + 1); j++) {
                c = fgetc(file);
                
                if (c != '\n') {
                    matrizJogo[i][j] = c;
                }
            }
        }
        
        printf("LEU ARQUIVO MAPA COM SUCESSO\n");
        
        fclose(file);
        
    }
    
    
    
}

void encontraPosicaoInicialJogadorEInimigos(char matrizJogo[][MAX_COLUNAS], Estado *save) {
    
    int i, j;
    
    save->numInimigos = 0;
    
    for (i=0; i<MAX_LINHAS; i++) {
        for (j=0; j<MAX_COLUNAS; j++) {
            if (matrizJogo[i][j] == 'J') {
                save->jogador.posicao.x = j;
                save->jogador.posicao.y = i;
            }
            
            if (matrizJogo[i][j] == 'E') {
                save->inimigos[save->numInimigos].ativo = ATIVO;
                save->inimigos[save->numInimigos].posicao.x = j;
                save->inimigos[save->numInimigos].posicao.y = i;
                save->numInimigos += 1;
            }
        }
    }
    
}

Estado criaSaveInicial(Infmon infmonInicial) {
    
    char matrizJogo[MAX_LINHAS][MAX_COLUNAS];
    char fileName[MAX_CHAR];
    Estado saveInicial;
    
    saveInicial.jogador.numInfmons = NUM_INFMONS_INICIAL;
    saveInicial.jogador.infmons[POS_INFMON_INICIAL] = infmonInicial;
    
    saveInicial.numMapa = MAPA_INICIAL;
    
    identificaNomeMapa(fileName, saveInicial);
    leArquivoMapa(matrizJogo, fileName);
    
    encontraPosicaoInicialJogadorEInimigos(matrizJogo, &saveInicial);
    
    return saveInicial;
}

int passaParaProximoMapa(Estado *save) {
    
    char matrizJogo[MAX_LINHAS][MAX_COLUNAS];
    char fileName[MAX_CHAR];
    int passou = TRUE;
    
    if (save->numMapa < MAX_MAPAS) {
        save->numMapa++;
        
        identificaNomeMapa(fileName, *save);
        leArquivoMapa(matrizJogo, fileName);
        
        encontraPosicaoInicialJogadorEInimigos(matrizJogo, save);
        
    }
    else {
        passou = FALSE;
    }
    
    return passou;
    
}
