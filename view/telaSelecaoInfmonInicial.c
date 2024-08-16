#include "telaSelecaoInfmonInicial.h"

void telaSelecaoInfmonInicial(void) {
    
    DrawText("Selecione o seu INFmon inicial", 220, 50, 50, BLACK);
    
    opcaoInfmon(BLUE, 200, 270, "A", "Palafin");
    opcaoInfmon(RED, 550, 270, "B", "Ragnaros");
    opcaoInfmon(GREEN, 900, 270, "C", "Torterra");
    
}

void opcaoInfmon(Color cor, int posX, int posY, char tecla[], char nomeInfmon[]) {
    
    Rectangle rec = {posX, posY, 100, 100};
    
    DrawText(tecla, (posX + 38), (posY - 45), 40, BLACK);
    
    DrawRectangleRec(rec, cor);
    DrawRectangleLinesEx(rec, 3, BLACK);
    
    DrawText(nomeInfmon, (posX + 10), (posY + 110), 25, BLACK);
    
}
