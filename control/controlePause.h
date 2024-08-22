#ifndef controlePause_h
#define controlePause_h

#include <stdio.h>
#include "../view/telaPause.h"
#include "../model/save.h"

#define TRUE 1
#define FALSE 0

void exibeMenuPause(int *jogoPausado, int *estadoTela, Estado *save, char matrizJogo[][MAX_COLUNAS]);

#endif /* controlePause_h */
