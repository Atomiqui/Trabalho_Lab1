#ifndef JOGADAS_H
#define JOGADAS_H

#include <stdbool.h>

// 

#define AZUL        1
#define BRANCO      2
#define CIANO       3
#define DOURADO     4
#define ESMERALDA   5
#define FERRUGEM    6
#define GRIS        7

void jogar(char **objetivo);

char **joga_sortear_cores();

int *joga_le_jogada();

bool joga_verifica_jogada(int *objetivo, int *jogada, int *pontos);

bool valida_jogadas(int *jogada);

int conta_pretos(int *objetivo, int *jogada);

int conta_brancos(int *objetivo, int *jogada);

int leia_int();


#endif // JOGADAS_H