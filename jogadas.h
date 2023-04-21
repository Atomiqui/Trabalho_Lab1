#ifndef JOGADAS_H
#define JOGADAS_H

#include <stdbool.h>
//#include <ncurses.h>
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
int pontua(int pontos, int i);

// Recebe pos pontos que o jogador fez, verifica se é digno do pódigo, se sim, grava seu nome
void rankear(int *pontos);

// Liberar a memória se não o prof de lab1 me caça pela ufsm.
void libera_mem(char **historico);

// de fato faz a verificação da jogada, pontua e tudo mais!
bool verifica(char **historico, char *jogada, char **objetivoint, int *pontos, int *i);

#endif // JOGADAS_H