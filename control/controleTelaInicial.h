#include "../view/telaInicial.h"
#include "../view/visualMapa.h"
#include "raylib.h"
#include "controleSelecaoInfmonInicial.h"

#define TRUE 1
#define FALSE 0

#define BOTAO_NOVO_JOGO 'N'
#define BOTAO_OUTRO 'O'

void exibeTelaInicial(void);
void desenhaElementosTela(void);
void criarNovoJogo(int *naTelaInicial, char *botaoPressionado);
void verificaBotaoPressionado(char *botaoPressionado);
void executaAcaoBotaoPressionado(char *botaoPressionado, int *naTelaInicial);

