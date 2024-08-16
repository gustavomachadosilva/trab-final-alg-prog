//
//  infmon.c
//  INFmon
//
//  Created by Gustavo Machado Silva on 29/07/24.
//

#include "infmon.h"

Infmon criaPrimeiroInfmonJogador(int tipoInfmon) {
    
    Infmon infmonInicial;
    
    infmonInicial.tipo = tipoInfmon;
    infmonInicial.nivel = NIVEL_INICIAL;
    
    defineAtributos(&infmonInicial);
    
    return infmonInicial;
}

Infmon criaInfmonAleatorio(void) {
    
    srand(time(NULL));
    
    Infmon infmonAleatorio;
    
    infmonAleatorio.tipo = defineTipoAleatorio();
    infmonAleatorio.nivel = defineNivelAleatorio();
    
    defineAtributos(&infmonAleatorio);
    
    return infmonAleatorio;
    
}

void defineAtributos(Infmon *infmon) {
    
    nomeiaAtaquesPorTipo(infmon);
    defineNome(infmon);
    defineVida(infmon);
    defineAtaque(infmon);
    defineDefesa(infmon);
    defineDanoAtaques(infmon);
    defineExpInicial(infmon);
    
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

void defineDanoAtaques(Infmon *infmon) {
    
    infmon->ataques[ATAQUE_LEVE].dano = infmon->ataque * FATOR_ATAQUE_LEVE;
    infmon->ataques[ATAQUE_MEDIO].dano = infmon->ataque * FATOR_ATAQUE_MEDIO;
    infmon->ataques[ATAQUE_PESADO].dano = infmon->ataque * FATOR_ATAQUE_PESADO;
    
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
    else if (infmon->tipo == TIPO_TERRA) {
        strcpy(infmon->nome, "Torterra");
    }
    
}

void defineVida(Infmon *infmon) {
    
    infmon->vida = VIDA_BASE + (FATOR_VIDA * infmon->nivel);
    
}

void defineAtaque(Infmon *infmon) {
    
    infmon->ataque = ATAQUE_BASE + (FATOR_ATAQUE * infmon->nivel);
    
}

void defineDefesa(Infmon *infmon) {
    
    infmon->defesa = DEFESA_BASE + (FATOR_DEFESA * infmon->nivel);
    
}

float identificaVantagemEntreInfmons(Infmon atacante, Infmon atacado) {
    
    float vantagem = SEM_VANTAGEM;
    
    if (atacante.tipo != atacado.tipo) {
        
        if (atacante.tipo == TIPO_AGUA) {
            if (atacado.tipo == TIPO_FOGO) {
                vantagem = VANTAGEM_ATACANTE;
            }
            else if (atacado.tipo == TIPO_TERRA) {
                vantagem = VANTAGEM_ATACADO;
            }
        }
        else if (atacante.tipo == TIPO_FOGO) {
            if (atacado.tipo == TIPO_TERRA) {
                vantagem = VANTAGEM_ATACANTE;
            }
            else if (atacado.tipo == TIPO_AGUA) {
                vantagem = VANTAGEM_ATACADO;
            }
        }
        else if (atacante.tipo == TIPO_TERRA) {
            if (atacado.tipo == TIPO_AGUA) {
                vantagem = VANTAGEM_ATACANTE;
            }
            else if (atacado.tipo == TIPO_FOGO) {
                vantagem = VANTAGEM_ATACADO;
            }
        }
        
    }
    
    return vantagem;
    
}

void atacar(Infmon *atacante, Infmon *atacado, int ataque) {
    
    float vantagem = identificaVantagemEntreInfmons(*atacante, *atacado);
    
    atacado->vida -= atacante->ataques[ataque].dano * vantagem;
    
}

void verificaSubirNivel(Infmon *infmon) {
    
    int xpNecessariaParaUpar = EXP_BASE + (FATOR_EXP * infmon->nivel);
    
    if (infmon->exp > xpNecessariaParaUpar && infmon->nivel < MAX_NIVEL) {
        
        infmon->nivel++;
        infmon->exp -= xpNecessariaParaUpar;
        
    }
    
}

void ganhaExpVitoria(Infmon *infmon, Infmon inimigo) {
    
    infmon->exp += GANHO_EXP_BASE + (FATOR_GANHO_EXP * inimigo.nivel);
    
}

void defineExpInicial(Infmon *infmon) {
    
    infmon->exp = 0;
    
}
