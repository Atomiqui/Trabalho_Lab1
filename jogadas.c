#include "jogadas.h"

char **joga_sortear_cores() {
    int random;
    char cores[7][2] = {{'a', 'A'}, {'b', 'B'}, {'c', 'C'}, {'d', 'D'}, {'e', 'E'}, {'f', 'F'}, {'g', 'G'}};
    char **cores_sorteadas = (char **) malloc(4 * sizeof(char *));
    for(int i = 0; i < 4; i++) {
        cores_sorteadas[i] = (char *) malloc(2 * sizeof(char));
    }
    srand(time(NULL));
    for(int i = 0; i < 4; i++) {
        random = rand() % 7;
        for (int j = 0; j < i; j++) {
            if (cores[random][0] == cores_sorteadas[j][0]) {
                random = rand() % 7;
                j = -1;
            }
        }
        cores_sorteadas[i][0] = cores[random][0];
        cores_sorteadas[i][1] = cores[random][1];
    }
    return cores_sorteadas;
}

void jogar(char **objetivo){
    int pontos = 1350;
    char *jogada = (char *) malloc(4 * sizeof(char));
    char **historico = malloc(10 * sizeof(char*));
    for(int i = 0; i < 10; i++) {
        historico[i] = malloc(4 * sizeof(char));
    }
    for(int i = 0; i < 10; i++) {
        tela_le_jogada(jogada);
        if(joga_verifica_jogada(objetivo, jogada, &pontos, historico, &i)) {
            if(pontos == 0) {
                printf("\tGAME OVER\n");
                print_objetivo(objetivo);
                return;
            }
            pontos = pontua(pontos, i);
            printf("Parabéns, você acertou a combinação secreta!\nSeu score é: %d.\n", pontos);
            printa_ranking();
            rankear(&pontos);
            free(jogada);
            libera_mem(historico);
            return;
        }
    }
    printf("Acabaram suas tentativas!\n\tGAME OVER\n");
    print_objetivo(objetivo);
    printa_ranking();
}

bool joga_verifica_jogada(char **objetivo, char *jogada, int *pontos, char **historico, int *i) {
    if(strcmp(jogada, "?") == 0) {
        *i -= 1;
        tela_print_regras();
    } else if(strcmp(jogada, "!") == 0) {
        jogadas_anteriores(historico, objetivo, i);
    } else if(strcmp(jogada, ";") == 0) {
        *pontos = 0;
        return true;
    } else {
        return verifica(historico, jogada, objetivo, pontos, i);
    }

    return false;
}

bool verifica(char **historico, char *jogada, char **objetivo, int *pontos, int *i) {
    strcpy(historico[*i], jogada);
    int pts = 100;
    int pretos = conta_pretos(objetivo, jogada);
    int brancos = conta_brancos(objetivo, jogada);
    pts -= (4/(brancos+1)) * 5;
    pts -= (4/(pretos+1)) * 3;

    *pontos -= pts;

    tela_desenha_retangulos(jogada, pretos, brancos);
    if(pretos == 4) {
        return true;
    }

    return false;
}


int conta_pretos(char **objetivo, char *jogada) {
    int pretos = 0;

    for(int i = 0; i < 4; i++) {
        if(objetivo[i][0] == jogada[i] || objetivo[i][1] == jogada[i]) {
            pretos++;
        }
    }

    return pretos;
}

int conta_brancos(char **objetivo, char *jogada) {
    int brancos = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if((jogada[i] == objetivo[j][0] || jogada[i] == objetivo[j][1])) {
                brancos++;
            }
        }
    }

    return brancos;
}

int pontua(int pontos, int i) {
    if(i < 4) {
        return pontos * ((10-i)*2);
    } 
    return pontos * (10-i);
}

void rankear(int *pontos) {
    char **nomes = malloc(5 * sizeof(char *));
    for(int i = 0; i < 5; i++) {
        nomes[i] = malloc(15 * sizeof(char));
    }
    int *ranking = le_ranking(nomes);
    for(int i = 0; i < 5; i++) {
        if(*pontos > ranking[i]) {
            char *nome = le_nickname();
            escreve_ranking(ranking, *pontos, nome, nomes);
            free(nome);
            free(nomes[i]);
            break;
        }
    }
    free(nomes);
    free(ranking);
}

void libera_mem(char **historico) {
    for(int i = 0; i < 10; i++) {
        free(historico[i]);
    }
    free(historico);
}