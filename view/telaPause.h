#ifndef telaPause_h
#define telaPause_h

#include <stdio.h>
#include "raylib.h"
#include "../model/save.h"

//---------TELA----------
#define LARGURA_TELA 1200
#define ALTURA_TELA 600
//------TELA PAUSE--------
#define LARGURA_TELA_PAUSE 230
#define ALTURA_TELA_PAUSE 330
//-------TELA BOTAO--------
#define LARGURA_TELA_BOTAO 500
#define ALTURA_TELA_BOTAO 250
#define FPS 60
//------TELA CONFIRMACAO------
#define LARGURA_TELA_CONFIRMACAO 350
#define ALTURA_TELA_CONFIRMACAO 150
#define TAMANHO_FONTE_BOTAO_CONFIRMACAO 10
#define LARGURA_BOTAO_CONFIRMACAO 75
#define ALTURA_BOTAO_CONFIRMACAO 30
//---------TITULO----------
#define TITULO_ABA_INTERACAO "Escolha uma opcao"
#define POSICAO_TITULO_X_INTERACAO 110
#define POSICAO_TITULO_Y_INTERACAO 7
#define TAMANHO_FONTE_TELA_INTERACAO 20
//-----BOTAO TELA INTERACAO---------
#define LARGURA_BOTAO 220
#define ALTURA_BOTAO 100
#define ESPESSURA_LINHA 3
#define TAMANHO_FONTE_BOTAO_INTERACAO 25
#define TAMANHO_FONTE_BOTAO_ATAQUES 20
#define TAMANHO_FONTE_BOTAO_TROCAS 25
//------BOTAO TELA PAUSE-----
#define LARGURA_BOTAO_PAUSE 180
#define ALTURA_BOTAO_PAUSE 50
#define TAMANHO_FONTE_BOTAO_PAUSE 17
//---------OUTROS-----------
#define TELA_INICIO_INTERACAO 0   // tela de interacao (atacar, trocar, fugir ou capturar)
#define TELA_ATAQUES 1            // para o submenu de ataques
#define TELA_TROCAS 2             // para o submenu de trocas
#define TELA_PAUSE 3              // para a tela de pause
#define TELA_JOGO 4               // tela do 'jogo rolando'
#define TELA_CONFIRMACAO 5        // tela para confirmar se o jogador deseja mesmo fazer
#define SAINDO 6
#define TELA_FINAL 7
#define TELA_MENU 8

//prototipos funcoes:
void botaoTelaPause(char text[], int posX, int posY, int addXtext, int addYtext);
void botaoTelaAtaques(char text[], int posX, int posY, int addXtext, int addYtext);
void abrirMenuPause(int *estadoTela, Estado *save, char matrizJogo[][MAX_COLUNAS]);
void jogoRolando(int *estadoTela, Estado *save, char matrizJogo[][MAX_COLUNAS]);
void abrirTelaConfirmacao(int *estadoTela);
void desenhaBordaBotao(int posX, int posY, int addXtext, int addYtext);
void desenhaBordaBotaoConfirmacao(int posX, int posY, int addXtext, int addYtext);


#endif /* telaPause_h */
