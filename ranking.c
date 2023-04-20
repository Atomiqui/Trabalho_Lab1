#include "ranking.h"

// Recebe o nome de um arquivo e a maneira que ele deve ser aberto, então retorna o ponteiro para o arquivo.
FILE *open_file(char *nome, char *operation) {
    FILE *arq = fopen("ranking.txt", operation);
    return arq;
}

// Abre um arquivo para leitura e retorna um vetor com as pontuações do ranking
int *le_ranking() {
    FILE *arq = fopen("ranking.txt", "r");
    if(arq == NULL) {
        arq = fopen("ranking.txt", "w");
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
            ranking[i] = atoi(temp);
        }
    }

    fclose(arq);
    return ranking;
}

void printa_ranking() {
    FILE *arq = fopen("ranking.txt", "r");
    if(arq == NULL) {
        arq = fopen("ranking.txt", "w");
    }

    printf("\tRANKING\n");
    for(int i = 0; i < 5; i++) {
        char linha[30];
        fgets(linha, 30, arq);
        printf("%s", linha);
    }

    fclose(arq);
}

// Atualiza o ranking
void escreve_ranking(int *ranking, int novo_score, char *nome) {
    for(int i = 4; i >= 0; i--) {
        bool verifica = true;
        if(i != 0) {
            verifica = novo_score <= ranking[i-1];
            //printf("%d < %d?", novo_score, ranking[i-1]);
            //if(verifica) printf("sim!");
        } 
        if(novo_score > ranking[i] && verifica) {
            FILE *arq = fopen("ranking.txt", "w");
            for(int i = 0; i < 5; i++) {
                char str[30];
                sprintf(str, "%s | %d\n", nome, ranking[i]);
                fputs(str, arq);
            }
            break;
        }
    }
    
    fclose(arq);
}