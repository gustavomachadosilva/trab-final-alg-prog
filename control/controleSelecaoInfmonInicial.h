#ifndef controleSelecaoInfmonInicial_h
#define controleSelecaoInfmonInicial_h

#include <stdio.h>
#include "raylib.h"
#include "../view/telaSelecaoInfmonInicial.h"
#include "controleMapa.h"
//#include "../model/save.h"

#define TRUE 1
#define FALSE 0

void exibeSelecaoInfmonInicial(void);
int selecionaTipoInfmonInicial(int *comecarJogo);

#endif /* controleSelecaoInfmonInicial_h */
