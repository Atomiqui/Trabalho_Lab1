#include <stdlib.h>
#include <string.h>
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

    } else if(strcmp(jogada, "!") == 0) {

    } else if(strcmp(jogada, ";") == 0) {

    } else {

    }

    return false;
}

// Funções Auxiliares:

/*int conta_pretos(int *objetivo, int *jogada) {
    int pretos = 0;

    for(int i = 0; i < 4; i++) {
        if(objetivo[i] == jogada[i]) {
            pretos++;
        }
    }

    return pretos;
}*/

/*int conta_brancos(int *objetivo, int *jogada) {
    int brancos = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(jogada[i] == objetivo[j] && i != j) {
                brancos++;
            }
        }
    }

    return brancos;
}*/

bool valida_jogadas(char *jogada) {
    leia_char(jogada);

    if(strcmp(jogada,"?") == 0 || strcmp(jogada,"!") == 0 || strcmp(jogada,";") == 0) {
        return true;
    }

    for(int i = 0; i < 4; i++) {
        if(!((jogada[i] >= 'a' && jogada[i] <= 'g') || (jogada[i] >= 'A' && jogada[i] <= 'G'))) {
            printf("\"%c\" não é um caracter válido!\nSe precisar digite \"?\" para vizualizar os comandos.", jogada[i]);
            return false;
        }
    }
    return true;
}

void leia_char(char *var) {
    scanf("%s", var);

    if(strcmp(var,"?") == 0 || strcmp(var,"!") == 0 || strcmp(var,";") == 0) {
        return;
    }

    while (strlen(var) != 4) {
        puts("As jogadas devem ser feitas usando 4 símbolos, "
        "não utilize mais ou menos do que isso!\nInsira sua jogada novamente:");
        scanf("%s", var);
    }
}