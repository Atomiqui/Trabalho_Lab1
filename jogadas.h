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

void joga_le_jogada(char *jogada);

bool joga_verifica_jogada(char **objetivo, char *jogada, int *pontos);

bool valida_jogadas(char *jogada);

int conta_pretos(int *objetivo, char **jogada);

int conta_brancos(int *objetivo, char **jogada);

void leia_char(char *jogada);


#endif // JOGADAS_H