//
//  infmon.c
//  INFmon
//
//  Created by Gustavo Machado Silva on 29/07/24.
//

#include "infmon.h"

void criaInfmonAleatorio(Infmon *infmon) {
    
    srand(time(NULL));
    
    infmon->tipo = defineTipoAleatorio();
    nomeiaAtaquesPorTipo(infmon);
    
    infmon->nivel = defineNivelAleatorio();
    
    defineNome(infmon);
    
    defineVida(infmon);
    
}

int defineTipoAleatorio(void) {
    
    int tipo;
    
    tipo = rand() % MAX_TIPO;
    
    return tipo;
    
}

void nomeiaAtaquesPorTipo(Infmon *infmon) {
    
    if (infmon->tipo == TIPO_AGUA) {
        defineNomesAtaques(infmon, "jato de agua", "bolhas", "canhao de agua");
    }
    else if (infmon->tipo == TIPO_FOGO) {
        defineNomesAtaques(infmon, "bola de fogo", "lanca chamas", "ingnimpacto");
    }
    else if (infmon->tipo == TIPO_TERRA) {
        defineNomesAtaques(infmon, "pedregulho", "prisao terrena", "terremoto");
    }
    
}

void defineNomesAtaques(Infmon *infmon, char ataqueLeve[], char ataqueMedio[], char ataquePesado[]) {
    
    strcpy(infmon->ataques[ATAQUE_LEVE].nome, ataqueLeve);
    strcpy(infmon->ataques[ATAQUE_MEDIO].nome, ataqueMedio);
    strcpy(infmon->ataques[ATAQUE_PESADO].nome, ataquePesado);
    
}

int defineNivelAleatorio(void) {
    
    int nivel;
    
    nivel = (rand() % MAX_NIVEL) + 1;
    
    return nivel;
    
}

void defineNome(Infmon *infmon) {
    
    if (infmon->tipo == TIPO_AGUA) {
        strcpy(infmon->nome, "Palafin");
    }
    else if (infmon->tipo == TIPO_FOGO) {
        strcpy(infmon->nome, "Ragnaros");
    }
    else if (infmon->tipo == TIPO_FOGO) {
        strcpy(infmon->nome, "Torterra");
    }
    
}

void defineVida(Infmon *infmon) {
    
    infmon->vida = VIDA_BASE * infmon->nivel;
    
}


// Fogo -> Ragnaros
// Agua -> Palafin
// Terra -> Torterra
