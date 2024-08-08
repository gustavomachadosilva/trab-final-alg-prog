//
//  telaSelecaoInfmonInicial.c
//  INFmon
//
//  Created by Gustavo Machado Silva on 06/08/24.
//

#include "telaSelecaoInfmonInicial.h"

void telaSelecaoInfmonInicial(void) {
    
    DrawText("Selecione o seu INFmon inicial", 220, 50, 50, BLACK);
    
    opcaoInfmon(BLUE, 200, 270);
    opcaoInfmon(GREEN, 500, 270);
    opcaoInfmon(RED, 800, 270);
    
}

void opcaoInfmon(Color cor, int posX, int posY) {
    
    Rectangle rec = {posX, posY, 100, 100};
    
    DrawRectangleRec(rec, cor);
    DrawRectangleLinesEx(rec, 3, BLACK);
    
}
