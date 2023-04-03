#include "ranking.h"

// Recebe o nome de um arquivo e a maneira que ele deve ser aberto, então retorna o ponteiro para o arquivo.
FILE *open_file(char *nome, char *operation) {
    FILE *arq = fopen("ranking.txt", operation);
    if (arq == NULL) {
        printf("Problemas ao abrir o arquivo %s\n", nome);
        //exit(1);
    }

    return arq;
}

// Abre um arquivo para leitura e retorna um vetor com as pontuações do ranking
int *le_ranking() {
    FILE *arq = open_file(NOME, RT);
    int *ranking = malloc(5 * sizeof(int));
    if (ranking == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    } else {
        for(int i = 0; i < 5; i++) {
            ranking[i] = 0;
        }
    }
    char linha[50];
    for(int i = 0; i < 5; i++) {
        if(fgets(linha, 50, arq) != NULL) {
            ranking[i] = atoi(linha);
        }
    }

    fclose(arq);
    return ranking;
}

// Atualiza o ranking
void escreve_ranking(int *ranking, int novo_score) {
    for(int i = 4; i > 0; i--) {
        if(ranking[i] < novo_score) {
            ranking[i] = novo_score;
        }
    }

    FILE *arq = open_file(NOME, WT);
    for(int i = 4; i > 0; i--) {
        char str[20];
        sprintf(str, "%d\n", ranking[i]);
        if(fputs(str, arq) == EOF) {
            printf("Erro na Gravacao\n");
        }
    }

    fclose(arq);
}