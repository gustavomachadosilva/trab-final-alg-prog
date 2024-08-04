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
#define VIDA_BASE 35
#define ATAQUE_BASE 5
#define DEFESA_BASE 2
#define NIVEL_INICIAL 1

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

void criaPrimeiroInfmonJogador(Infmon *infmon, int tipoInfmon);
void criaInfmonAleatorio(Infmon *infmon);
void defineAtributos(Infmon *infmon);
int defineTipoAleatorio(void);
void nomeiaAtaquesPorTipo(Infmon *infmon);
void defineNomesAtaques(Infmon *infmon, char ataqueLeve[], char ataqueMedio[], char ataquePesado[]);
int defineNivelAleatorio(void);
void defineNome(Infmon *infmon);
void defineVida(Infmon *infmon);
void defineAtaque(Infmon *infmon);
void defineDefesa(Infmon *infmon);

#endif /* infmon_h */
