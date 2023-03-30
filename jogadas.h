#ifndef JOGADAS_H
#define JOGADAS_H

#include <stdbool.h>
#include <string.h>
#include <ncurses.h>

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

void leia_char(char *jogada);

int conta_pretos(char **objetivo, char *jogada);

int conta_brancos(char **objetivo, char *jogada);

bool repetidos(char *jogada);

void print_regras();

void desenha_retangulos(char *jogada, int pretos, int brancos);

void inicia_ncurses();
int calc_num_letra(char letra);

#endif // JOGADAS_H