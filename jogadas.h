#ifndef JOGADAS_H
#define JOGADAS_H

#include <stdbool.h>

// 

#define AMARELO 0
#define AZUL 1
#define BRANCO 2
#define LARANJA 3
#define ROXO 4
#define VERDE 5
#define VERMELHO 6

void jogar(int *objetivo);

int *joga_sortear_cores();

int *joga_le_jogada();

bool joga_verifica_jogada(int *objetivo, int *jogada, int *pontos);

bool valida_jogadas(int *jogada);

int conta_pretos(int *objetivo, int *jogada);

int conta_brancos(int *objetivo, int *jogada);

int leia_int();


#endif // JOGADAS_H