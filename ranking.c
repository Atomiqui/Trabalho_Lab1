#include "ranking.h"

// Recebe o nome de um arquivo e a maneira que ele deve ser aberto, então retorna o ponteiro para o arquivo.
FILE *open_file(char *nome, char *operation) {
    File *arq = fopen("ranking.txt", operation);
    return arq
}

// Abre um arquivo para leitura e retorna um vetor com as pontuações do ranking
int *le_ranking() {
    FILE *arq = fopen("ranking.txt", 'r'); //open_file(NOME, RT);
    if(arq == NULL) {
        *arq = fopen("ranking.txt", 'w'); //open_file(NOME, WT);
    }

    int *ranking = malloc(5 * sizeof(int));
    char linha[10];
    for(int i = 0; i < 5; i++) {
        ranking[i] = 0;

        if(fgets(linha, 10, arq) != NULL) {
            ranking[i] = atoi(linha);
        }
    }

    fclose(arq);
    return ranking;
}

// Atualiza o ranking
void escreve_ranking(int *ranking, int novo_score, char *nome) {
    for(int i = 4; i > 0; i--) {
        if(ranking[i] < novo_score) {
            ranking[i] = novo_score;
        }
    }

    FILE *arq = fopen("ranking.txt", 'w'); //open_file(NOME, WT);
    
    for(int i = 4; i > 0; i--) {
        char str[30];
        sprintf(str, "%s | %d\n", nome, ranking[i]);
        fputs(str, arq);
    }

    fclose(arq);
}