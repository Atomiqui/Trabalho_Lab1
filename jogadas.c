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
    char **historico = malloc(10 * sizeof(char*));
    /*for(int i = 0; i < 10; i++) {
        historico[i] = malloc(4 * sizeof(char));
    }*/
    char *jogada = (char *) malloc(4 * sizeof(char));
    tela_print_regras();

    for(int i = 0; i < 10; i++) {
        tela_le_jogada(jogada);
        if(joga_verifica_jogada(objetivo, jogada, &pontos, historico)) {
            if(pontos == 0) {
                printf("\tGAME OVER\n");
                print_objetivo(objetivo);
                return;
            }
            pontua(&pontos, i);
            printf("Parabéns, você acertou a combinação secreta!\nSeu score é: %d.", pontos);
            rankear(&pontos);
            return;
        }
    }

    printf("Acabaram suas tentativas!\n\tGAME OVER\n");
    print_objetivo(objetivo);

}

void print_objetivo(char **objetivo) {
    char objetivo2[4] = {objetivo[0][1], objetivo[1][1], objetivo[2][1], objetivo[3][1]};
    printf("A sequencia correta era: %s\n\n", objetivo2);

    char cont;
    printf("Gostaria de ver as cores?\n[1] - sim\n[2] - não\n");
    scanf(" %c", &cont);
    if(cont == '1') {
        tela_desenha_retangulos(objetivo2, 0 ,0);
    }
}

bool joga_verifica_jogada(char **objetivo, char *jogada, int *pontos, char **historico) {

    int pts = 100;

    if(strcmp(jogada, "?") == 0) {
        tela_print_regras();
    } else if(strcmp(jogada, "!") == 0) {
        for(int i = 0; i < 10; i++) {
            if(historico[i] != NULL) {
                printf("%s\n", historico[i]);
            }
        }
    } else if(strcmp(jogada, ";") == 0) {
        *pontos = 0;
        return true;
    } else {
        int i = 0;
        while (historico[i] != NULL) {
            i++;
        }
        historico[i] = jogada;
        
        int pretos = conta_pretos(objetivo, jogada);
        int brancos = conta_brancos(objetivo, jogada);

        pts -= (4 - brancos) * 5;
        pts -= (4 - pretos) * 10;

        *pontos -= pts;

        tela_desenha_retangulos(jogada, pretos, brancos);
        if(pretos == 4) {
            return true;
        }
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

void pontua(int *pontos, int i) {
    if(i < 4) {
        *pontos *= 4;
    } else if( i < 7) {
        *pontos *= 2;
    } else {
        *pontos *= 1.5;
    }
}

void rankear(int *pontos) {
    int *ranking = le_ranking();
    for(int i = 0; i < 5; i++) {
        if(*pontos > ranking[i]) {
            char *nome = le_nickname();
            escreve_ranking(ranking, *pontos, nome);
            break;
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("Rk%d: %d\n", i, ranking[i]);
    }
}

char *le_nickname() {
    char *nome = malloc(15 * sizeof(char));
    printf("Parabés! Você teve um ótimo desempenho, queremos registrar isso.\nInforme seu nome (no máximo 15 caracteres): ");
    scanf("%s", nome);

    return nome;
}