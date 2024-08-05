#ifndef telaInicial_h
#define telaInicial_h

#include "raylib.h"

#define MAX_CHAR 50

#define TITULO_JOGO "INFmon"
#define POSICAO_TITULO_X 500
#define POSICAO_TITULO_Y 70
#define TAMANHO_FONTE_TITULO 60

#define LARGURA_BOTAO 400
#define ALTURA_BOTAO 100
#define ESPESSURA_LINHA 3
#define TAMANHO_FONTE_BOTAO 30

#define TRUE 1
#define FALSE 0

void elementosDaTela(Texture2D botaoN, Color botaoC, Color botaoS, Texture2D texturaFundo, Texture2D texturaTitulo);
void botao(char text[MAX_CHAR], int posY, int addXtext, int addYtext, Color corBotao);
void telaCriarNovoJogo(Color corBotaoSim, Color corBotaoNao);

#endif /* telaInicial_h */
