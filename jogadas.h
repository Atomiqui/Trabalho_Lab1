#ifndef JOGADAS_H
#define JOGADAS_H

#include <stdbool.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tela.h"
#include "ranking.h"

// Retorna uma string com 4 letras aleatórias que representam o objetivo do jogador.
char **joga_sortear_cores();

// Laço que define o funcionamento do jogo e a quantidade de jogadas possíveis.
void jogar(char **objetivo);

/*  
*   - Retorna true quando o jogador desiste, e assim encerra o laço;
*   - Retorna true quando o jogador acerta a combinação secreta;
*   - Retorna false quando o jogador erra a combinação (jogar de novo).
*/
bool joga_verifica_jogada(char **objetivo, char *jogada, int *pontos, char **historico, int *i);

// Funções Auxiliares:

// Conta a quantidade de cores no lugar correto.
int conta_pretos(char **objetivo, char *jogada);

// Conta a quantidade de cores corretas (não precisa estar na posição correta).
int conta_brancos(char **objetivo, char *jogada);

// Multiplica os pontos obtidos com base no quão cedo o jogado advinhou
void pontua(int *pontos, int i);

void rankear(int *pontos);
char *le_nickname();
void print_objetivo(char **objetivo);

#endif // JOGADAS_H