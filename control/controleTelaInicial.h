#ifndef controleTelaInicial_h
#define controleTelaInicial_h

#include "../view/telaInicial.h"
#include "controleMapa.h"
#include "raylib.h"
#include "controleSelecaoInfmonInicial.h"
#include "../model/save.h"

#define TRUE 1
#define FALSE 0

#define BOTAO_NOVO_JOGO 'N'
#define BOTAO_CARREGAR_JOGO 'C'
#define BOTAO_SAIR 'S'
#define BOTAO_OUTRO 'O'

void exibeTelaInicial(void);
void desenhaElementosTela(void);
void criarNovoJogo(int *naTelaInicial, char *botaoPressionado);
void verificaBotaoPressionado(char *botaoPressionado);
void executaAcaoBotaoPressionado(char *botaoPressionado, int *naTelaInicial);
void acionaCarregarJogo(void);

#endif /* controleTelaInicial_h */
