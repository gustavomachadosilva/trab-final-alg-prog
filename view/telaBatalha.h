#ifndef telaBatalha_h
#define telaBatalha_h

#include <stdio.h>
#include "raylib.h"
#include "../model/infmon.h"
#include "../model/save.h"

//-------TELA--------
#define LARGURA_TELA 1200
#define ALTURA_TELA 600

//-------TELA BOTAO--------
#define LARGURA_TELA_BOTAO 500
#define ALTURA_TELA_BOTAO 250
#define FPS 60
//---------TITULO--------
#define TITULO_ABA_INTERACAO "Escolha uma opcao"
#define POSICAO_TITULO_X_INTERACAO 110
#define POSICAO_TITULO_Y_INTERACAO 7
#define TAMANHO_FONTE_TELA_INTERACAO 20
//---------BOTAO---------
#define LARGURA_BOTAO 220
#define ALTURA_BOTAO 100
#define ESPESSURA_LINHA 3
#define TAMANHO_FONTE_BOTAO_INTERACAO 25
#define TAMANHO_FONTE_BOTAO_ATAQUES 20
#define TAMANHO_FONTE_BOTAO_TROCAS 25
//---------OUTROS-----------
#define TELA_INICIO_INTERACAO 0   // tela de interacao (atacar, trocar, fugir ou capturar)
#define TELA_ATAQUES 1            // para o submenu de ataques
#define TELA_TROCAS 2             // para o submenu de trocas

#define TRUE 1
#define FALSE 0

//prototipos funcoes:
void telaInteracao(void);
void botaoTelaInteracao(char text[], int posX, int posY, int addXtext, int addYtext);
void botaoTelaAtaques(char text[], int posX, int posY, int addXtext, int addYtext);
void abrirSubmenuAtaques(int *estadoTela, Infmon *atacante, Infmon *atacado, int *turno);
void abrirSubmenuTrocas(int *estadoTela, int *infmonAtual, Estado *save, int *turno);
void elementosTelaInteracao(int *estadoTela, int *infmonAtual, int *naBatalha, Infmon *atacante, Infmon *atacado, Estado *save, int *turno, int isSelvagem);
void desenhaInfmon(int posX, int posY, Infmon infmon, Texture2D texturaInfTerra, Texture2D texturaInfFogo, Texture2D texturaInfAgua);
void desenhaVida(int posX, int posY, Infmon infmon);

#endif /* telaBatalha_h */
