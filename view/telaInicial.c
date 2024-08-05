#include "telaInicial.h"

void elementosDaTela(Texture2D texturaNovoJogo, Color botaoC, Color botaoS, Texture2D texturaFundo, Texture2D texturaTitulo) {
    
    DrawTexture(texturaFundo, 0, 0, WHITE);
    
    DrawTexture(texturaTitulo, 400, 20, WHITE);
    DrawTexture(texturaNovoJogo, 375, 190, WHITE);
//    botao("Novo Jogo", 190, 120, 30, botaoN);
    botao("Carregar Jogo", 320, 100, 30, botaoC);
    botao("Sair", 450, 180, 30, botaoS);
    
}

void botao(char text[MAX_CHAR], int posY, int addXtext, int addYtext, Color corBotao) {
    
    Rectangle rec = { ((float)GetScreenWidth() - LARGURA_BOTAO)/2, posY, (float)LARGURA_BOTAO, (float)ALTURA_BOTAO };
    
    DrawRectangleRec(rec, corBotao);
    DrawRectangleLinesEx(rec, ESPESSURA_LINHA, BLACK);
    DrawText(text, rec.x + addXtext, rec.y + addYtext, TAMANHO_FONTE_BOTAO, BLACK);

}

void telaCriarNovoJogo(Color corBotaoSim, Color corBotaoNao) {
    
    float xTelinha = ((float)GetScreenWidth() - 500)/2;
    float yTelinha = ((float)GetScreenHeight() - 300)/2;
    
    Rectangle recTelinha = { xTelinha, yTelinha, (float)500, (float)300 };
    Color grayFade = Fade(GRAY, 0.8);
    
    DrawRectangle(0, 0, 1200, 600, grayFade);
    DrawRectangleRec(recTelinha, WHITE);
    DrawRectangleLinesEx(recTelinha, 3.0, BLACK);
    
    DrawText("Deseja criar novo jogo?", xTelinha + 100, yTelinha + 50, 25, BLACK);
    DrawText("Todo o progresso anterior será perdido", xTelinha + 38, yTelinha + 90, 20, BLACK);
    
    Rectangle recBotaoSim = {xTelinha + 100, yTelinha + 180, 110, 50};
    DrawRectangleRec(recBotaoSim, corBotaoSim);
    DrawRectangleLinesEx(recBotaoSim, 3.0, BLACK);
    DrawText("Sim", recBotaoSim.x + 36, recBotaoSim.y + 12, 30, BLACK);
    
    Rectangle recBotaoNao = {xTelinha + 290, yTelinha + 180, 110, 50};
    DrawRectangleRec(recBotaoNao, corBotaoNao);
    DrawRectangleLinesEx(recBotaoNao, 3.0, BLACK);
    DrawText("Não", recBotaoNao.x + 30, recBotaoNao.y + 12, 30, BLACK);
    
}
