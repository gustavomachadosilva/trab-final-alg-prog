#include "telaSelecaoInfmonInicial.h"

void telaSelecaoInfmonInicial(Texture2D texturaInfTerra, Texture2D texturaInfFogo, Texture2D texturaInfAgua) {
    
    DrawText("Selecione o seu INFmon inicial", 220, 50, 50, BLACK);
    
    
    opcaoInfmon(texturaInfAgua, 150, 270, "A", "Infirtle", 70, 50);
    opcaoInfmon(texturaInfFogo, 550, 270, "B", "Infmander", 40, 5);
    opcaoInfmon(texturaInfTerra, 900, 270, "C", "Infssauro", 70, 30);
    
}

void opcaoInfmon(Texture2D texturaInfmon, int posX, int posY, char tecla[], char nomeInfmon[], int ajustXtecla, int ajusteXnome) {
    
    DrawText(tecla, (posX + ajustXtecla), (posY - 45), 40, BLACK);
    
    DrawTexture(texturaInfmon, posX, posY, WHITE);
    
    DrawText(nomeInfmon, (posX + ajusteXnome), (posY + 215), 25, BLACK);
    
}
