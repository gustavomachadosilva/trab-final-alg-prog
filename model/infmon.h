//
//  infmon.h
//  INFmon
//
//  Created by Gustavo Machado Silva on 29/07/24.
//

#ifndef infmon_h
#define infmon_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 100
#define MAX_ATAQUES 3
#define MAX_TIPO 3
#define MAX_NIVEL 7
#define ATAQUE_LEVE 0
#define ATAQUE_MEDIO 1
#define ATAQUE_PESADO 2
#define TIPO_AGUA 0
#define TIPO_FOGO 1
#define TIPO_TERRA 2
#define VIDA_BASE 100
#define ATAQUE_BASE 25
#define DEFESA_BASE 15
#define NIVEL_INICIAL 1

#define FATOR_ATAQUE 5
#define FATOR_VIDA 11
#define FATOR_DEFESA 3
#define FATOR_ATAQUE_LEVE 1
#define FATOR_ATAQUE_MEDIO 1.5
#define FATOR_ATAQUE_PESADO 2

#define SEM_VANTAGEM 1
#define VANTAGEM_ATACANTE 1.2
#define VANTAGEM_ATACADO 0.8

#define EXP_BASE 100
#define FATOR_EXP 25
#define GANHO_EXP_BASE 25
#define FATOR_GANHO_EXP 10

typedef struct {
    int dano;
    char nome[MAX_CHAR];
}Ataque;

typedef struct {
    char nome[MAX_CHAR];
    int vida;
    int nivel;
    int exp;
    int tipo;
    int ataque;
    int defesa;
    Ataque ataques[MAX_ATAQUES];
}Infmon;

Infmon criaPrimeiroInfmonJogador(int tipoInfmon);
Infmon criaInfmonAleatorio(void);
void defineAtributos(Infmon *infmon);
int defineTipoAleatorio(void);
void nomeiaAtaquesPorTipo(Infmon *infmon);
void defineNomesAtaques(Infmon *infmon, char ataqueLeve[], char ataqueMedio[], char ataquePesado[]);
int defineNivelAleatorio(void);
void defineNome(Infmon *infmon);
void defineVida(Infmon *infmon);
void defineAtaque(Infmon *infmon);
void defineDefesa(Infmon *infmon);
void defineDanoAtaques(Infmon *infmon);
float identificaVantagemEntreInfmons(Infmon infmon1, Infmon infmon2);
void verificaSubirNivel(Infmon *infmon);
void ganhaExpVitoria(Infmon *infmon, Infmon inimigo);
void defineExpInicial(Infmon *infmon);

#endif /* infmon_h */
