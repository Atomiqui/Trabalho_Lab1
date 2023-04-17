#include "ranking.h"

// Recebe o nome de um arquivo e a maneira que ele deve ser aberto, então retorna o ponteiro para o arquivo.
FILE *open_file(char *nome, char *operation) {
    FILE *arq = fopen("ranking.txt", operation);
    return arq;
}

// Abre um arquivo para leitura e retorna um vetor com as pontuações do ranking
int *le_ranking() {
    FILE *arq = fopen("ranking.txt", "r"); //open_file(NOME, RT);
    if(arq == NULL) {
        //puts("problema pra abrir o arquivo!");
        arq = fopen("ranking.txt", "w"); //open_file(NOME, WT);
    }

    int *ranking = malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++) {
        char linha[30], temp[10];
        ranking[i] = 0;

        if(fgets(linha, 30, arq) != NULL) {
            int j = 0, k = 0;
            while(linha[j++] != '|') {
                // Econtra o |
            }
            for(j+=1; j < strlen(linha); j++) {
                temp[k++] = linha[j];
            }
            //printf("temp:%s\n", temp);
            ranking[i] = atoi(temp);
            //printf("ranking[i]:%d\n", ranking[i]);
        }
    }

    fclose(arq);
    return ranking;
}

// Atualiza o ranking
void escreve_ranking(int *ranking, int novo_score, char *nome) {
    for(int i = 0; i < 5; i++) {
        if(ranking[i] < novo_score) {
            printf("%d > %d", ranking[i], novo_score);
            ranking[i] = novo_score;
        }
    }

    FILE *arq = fopen("ranking.txt", "w"); //open_file(NOME, WT);
    
    for(int i = 4; i >= 0; i--) {
        char str[30];
        sprintf(str, "%s | %d\n", nome, ranking[i]);
        fputs(str, arq);
    }

    fclose(arq);
}