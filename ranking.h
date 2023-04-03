#ifndef RANKING_H
#define RANKING_H

#include <stdio.h>
#include <stdlib.h>

#define NOME "ranking.txt"
#define WT "w"
#define RT "r"

// Recebe o nome de um arquivo e a maneira que ele deve ser aberto, então retorna o ponteiro para o arquivo.
FILE *open_file(char *nome, char *operation);

// Abre um arquivo para leitura e retorna um vetor com as pontuações do ranking
int *le_ranking();

// Atualiza o ranking
void escreve_ranking(int *ranking, int novo_score);

#endif // RANKING_H