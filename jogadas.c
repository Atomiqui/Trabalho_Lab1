#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include<stdbool.h>
#include <time.h>

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
    int pontos = 0;
    char *jogada = (char *) malloc(4 * sizeof(char));

    for(int i = 0; i < 9; i++) {
        joga_le_jogada(jogada);
        if(joga_verifica_jogada(objetivo, jogada, &pontos)) {
            if(pontos == 0) {
                printf("\tGAME OVER\n");
                return;
            }
            // parabens voce ganhou
            return;
        }
    }

    printf("Acabaram suas tentativas!\n\tGAME OVER\n");
}

void joga_le_jogada(char *jogada) {
    do {
        printf("Insira sua jogada:\n");
    } while (valida_jogadas(jogada));
}

bool joga_verifica_jogada(char **objetivo, char *jogada, int *pontos) {

    /*  
    *   • Conta quantas cores estão corretas e quantas estão no lugar correto;
    *   • Pontuar;
    *   • testar se precisa chamar uma atualização de ranking;
    *   • Encerrar a partida (dar opção de jogar de novo);
    */

    if(strcmp(jogada, "?") == 0) {
        printf("\tREGRAS\n"
        "A/a - AZUL\n"
        "B/b - BEGE\n"
        "C/c - CIANO\n"
        "D/d - DOURADO\n"
        "E/e - ESMERALDA\n"
        "F/f - FERRUGEM\n"
        "G/g - GRIS\n"
        " !  - Ver respostas anteriores.\n"
        " ;  - Desistir.\n");
    } else if(strcmp(jogada, "!") == 0) {

    } else if(strcmp(jogada, ";") == 0) {
        pontos = 0;
        return true;
    } else {
        int pretos = conta_pretos(objetivo, jogada);
        int brancos = conta_brancos(objetivo, jogada);
        pontos += 
        printf("Pretos: %d.\nBrancos: %d.\n", pretos, brancos);
    }

    return false;
}

// Funções Auxiliares:

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

bool valida_jogadas(char *jogada) {
    leia_char(jogada);

    if(strcmp(jogada,"?") == 0 || strcmp(jogada,"!") == 0 || strcmp(jogada,";") == 0) {
        return false;
    }

    for(int i = 0; i < 4; i++) {
        if(!((jogada[i] >= 'a' && jogada[i] <= 'g') || (jogada[i] >= 'A' && jogada[i] <= 'G'))) {
            printf("\"%c\" não é um caracter válido!\nSe precisar digite \"?\" para vizualizar os comandos.\n", jogada[i]);
            return true;
        }
    }
    return false;
}

void leia_char(char *var) {
    bool repetidos;
    scanf("%s", var);



    while ((strlen(var) != 4) && ) {
        if((strcmp(var,"?") == 0 || strcmp(var,"!") == 0 || strcmp(var,";") == 0)) {
            return;
        }

        puts("As jogadas devem ser feitas usando 4 símbolos, "
        "não utilize mais ou menos do que isso!\nInsira sua jogada novamente:");
        scanf("%s", var);


    }
}