//
//  telaSelecaoInfmonInicial.h
//  INFmon
//
//  Created by Gustavo Machado Silva on 06/08/24.
//

#ifndef telaSelecaoInfmonInicial_h
#define telaSelecaoInfmonInicial_h

#include <stdio.h>
#include "raylib.h"

#define MAX_CHAR 100

void telaSelecaoInfmonInicial(Texture2D texturaInfTerra, Texture2D texturaInfFogo, Texture2D texturaInfAgua);
void opcaoInfmon(Texture2D texturaInfmon, int posX, int posY, char tecla[], char nomeInfmon[], int ajustXtecla, int ajusteXnome);

#endif /* telaSelecaoInfmonInicial_h */
