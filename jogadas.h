#ifndef JOGADAS_H
#define JOGADAS_H

#include <stdbool.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tela.h"

// Retorna uma string com 4 letras aleatórias que representam o objetivo do jogador.
char **joga_sortear_cores();

// Laço que define o funcionamento do jogo e a quantidade de jogadas possíveis.
void jogar(char **objetivo);

/*  
*   - Retorna true quando o jogador desiste, e assim encerra o laço;
*   - Retorna true quando o jogador acerta a combinação secreta;
*   - Retorna false quando o jogador erra a combinação (jogar de novo).
*/
bool joga_verifica_jogada(char **objetivo, char *jogada, int *pontos);

// Funções Auxiliares:

// Conta a quantidade de cores no lugar correto.
int conta_pretos(char **objetivo, char *jogada);

// Conta a quantidade de cores corretas (não precisa estar na posição correta).
int conta_brancos(char **objetivo, char *jogada);

#endif // JOGADAS_H