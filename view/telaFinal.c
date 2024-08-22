#include "telaFinal.h"


void elementosTelaFinal(void) {
    
    Rectangle rec = {450, 400, 300, 100};
    Color corBotao = RAYWHITE;
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    if (mouseX >= 450 && mouseX <= 750 && mouseY >= 400 && mouseY <= 500) {
        corBotao = Fade(GRAY, 0.8);
    }
    
    
    DrawText("Fim!", 530, 150, 80, BLACK);
    DrawText("Parabens, voce completou o jogo!", 340, 250, 30, BLACK);
    
    DrawRectangleRec(rec, corBotao);
    DrawRectangleLinesEx(rec, 3, BLACK);
    DrawText("Sair", 565, 430, 40, BLACK);
    
}
