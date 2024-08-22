#include "controleSelecaoInfmonInicial.h"

void exibeSelecaoInfmonInicial(void) {
    
    int comecarJogo = FALSE;
    int tipoInfmon = TIPO_AGUA;
    
    Image imagemInfTerra = LoadImage("./terra.png");
    Texture2D texturaInfTerra = LoadTextureFromImage(imagemInfTerra);
    
    Image imagemInfFogo = LoadImage("./fogo.png");
    Texture2D texturaInfFogo = LoadTextureFromImage(imagemInfFogo);
    
    Image imagemInfAgua = LoadImage("./agua.png");
    Texture2D texturaInfAgua = LoadTextureFromImage(imagemInfAgua);
    
    while(!WindowShouldClose() && comecarJogo == FALSE) {
        
        tipoInfmon = selecionaTipoInfmonInicial(&comecarJogo);
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        telaSelecaoInfmonInicial(texturaInfTerra, texturaInfFogo, texturaInfAgua);
        EndDrawing();
    }
    
    if (comecarJogo == TRUE) {
        
        Infmon infmonInicial = criaPrimeiroInfmonJogador(tipoInfmon);
        Estado save = criaSaveInicial(infmonInicial);
        
        exibeMapa(&save);
    }
    
}

int selecionaTipoInfmonInicial(int *comecarJogo) {
    
    int tipoInfmon = TIPO_AGUA;
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    if (IsKeyPressed(KEY_A) || (mouseX >= 250 && mouseX <= 350 && mouseY >= 270 && mouseY <= 470 && IsMouseButtonPressed(0))) {
        *comecarJogo = TRUE;
        tipoInfmon = TIPO_AGUA;
    }
    else if (IsKeyPressed(KEY_B) || (mouseX >= 550 && mouseX <= 750 && mouseY >= 270 && mouseY <= 470 && IsMouseButtonPressed(0))) {
        *comecarJogo = TRUE;
        tipoInfmon = TIPO_FOGO;
    }
    else if (IsKeyPressed(KEY_C) || (mouseX >= 900 && mouseX <= 1100 && mouseY >= 270 && mouseY <= 470 && IsMouseButtonPressed(0))) {
        *comecarJogo = TRUE;
        tipoInfmon = TIPO_TERRA;
    }
    
    return tipoInfmon;
    
}
