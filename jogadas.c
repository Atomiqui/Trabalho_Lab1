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
    for(int i = 0; i < 9; i++) {
        int *jogada = joga_le_jogada();
        if(joga_verifica_jogada(objetivo, jogada, &pontos)) {
            return;
        }
    }

    printf("Acabaram suas tentativas!\n\tGAME OVER\n");
}

int *joga_le_jogada() {
   char *jogada = (char *) malloc(4 * sizeof(char));

   do {
    printf("Insira sua jogada:\n");
    for(int i = 0; i < 4; i++) {
        jogada[i] = leia_int();
    }
   } while (valida_jogadas(jogada));   
   
   return jogada;
}

bool joga_verifica_jogada(char **objetivo, int *jogada, int *pontos) {

    /*  
    *   • Conta quantas cores estão corretas e quantas estão no lugar correto;
    *   • Pontuar;
    *   • testar se precisa chamar uma atualização de ranking;
    *   • Encerrar a partida (dar opção de jogar de novo);
    */

    //int quant_pretos = conta_pretos(objetivo, jogada);
    //int quant_brancos = conta_brancos(objetivo, jogada);

    pontos += quant_pretos*5 + quant_brancos*3;

    for(int i = 0; i < quant_pretos; i++) {
        printf("• ");
    }

    for(int i = 0; i < quant_brancos; i++) {
        printf("○ ");
    }

    if(quant_pretos = 4) {
        return true;
    }

    return false;
}

// Funções Auxiliares:

int conta_pretos(int *objetivo, int *jogada) {
    int pretos = 0;

    for(int i = 0; i < 4; i++) {
        if(objetivo[i] == jogada[i]) {
            pretos++;
        }
    }

    return pretos;
}

int conta_brancos(int *objetivo, int *jogada) {
    int brancos = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(jogada[i] == objetivo[j] && i != j) {
                brancos++;
            }
        }
    }

    return brancos;
}

bool valida_jogadas(int *jogada) {
    for(int i = 0; i < 4; i++) {
        if(jogada[i] < 0 || jogada[i] > 6) {
            return false;
        } 
    }

    return true;
}

int leia_char() {
    int var;
	while (scanf("%c", &var) != 1) {
		scanf("%*[^\n]");
		printf("\nInforme apenas numeros!\n");
	}

    return var;
}