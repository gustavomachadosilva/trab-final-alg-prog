//
//  mestre.h
//  INFmon
//
//  Created by Gustavo Machado Silva on 26/07/24.
//

#ifndef mestre_h
#define mestre_h

#include <stdio.h>
#include "infmon.h"

#define MAX_INFMONS 3

typedef struct {
    int x;
    int y;
    int numInfmons;
    Infmon infmons[MAX_INFMONS];
}Mestre;

void salvaInfmonsJogador(Mestre jogador);
void carregaInfmonsJogador(Mestre jogador);

#endif /* mestre_h */
