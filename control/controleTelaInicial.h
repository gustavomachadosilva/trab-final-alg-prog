#include "../view/telaInicial.h"
#include "../view/visualMapa.h"
#include "raylib.h"

#define TRUE 1
#define FALSE 0

#define BOTAO_NOVO_JOGO 'N'
#define BOTAO_OUTRO 'O'

void exibeTelaInicial(void);
void desenhaElementosTela(Texture2D texturaFundo, Texture2D texturaTitulo, Texture2D texturaNovoJogo, Texture2D texturaNovoJogo2);
void criarNovoJogo(int *naTelaInicial, char *botaoPressionado);
void verificaBotaoPressionado(char *botaoPressionado);
void executaAcaoBotaoPressionado(char *botaoPressionado, int *naTelaInicial);

