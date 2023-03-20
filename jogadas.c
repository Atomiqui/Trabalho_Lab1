#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <curses.h>
#include<stdbool.h>
#include <time.h>

#include "jogadas.h"

int *joga_sortear_cores() {

    int *cores_sorteadas = (int *) malloc(4 * sizeof(int)), random;

    srand(time(NULL));
    
    for(int i = 0; i < 4; i++) {
        random = rand() % 7;
        for (int j = 0; j < i; j++) {
            if (random == cores_sorteadas[j]) {
                random = rand() % 7;
                j = -1;
            }
        }
        
        cores_sorteadas[i] = random;
    }
    
    return cores_sorteadas;
}

void jogar(int *objetivo){
    int pontos = 0;
    for(int i = 0; i < 10; i++) {
        int *jogada = joga_le_jogada();
        if(joga_verifica_jogada(objetivo, jogada, &pontos)) {
            return;
        }
    }

    printf("Acabaram suas tentativas!\n\tGAME OVER\n");
}

int *joga_le_jogada() {
   int *jogada = (int *) malloc(4 * sizeof(int));

   do {
    printf("Insira sua jogada:\n");
    for(int i = 0; i < 4; i++) {
        jogada[i] = leia_int();
    }
   } while (valida_jogadas(jogada));   
   
   return jogada;
}

bool joga_verifica_jogada(int *objetivo, int *jogada, int *pontos) {

    /*  
    *   • Conta quantas cores estão corretas e quantas estão no lugar correto;
    *   • Pontuar;
    *   • testar se precisa chamar uma atualização de ranking;
    *   • Encerrar a partida (dar opção de jogar de novo);
    */

    int quant_pretos = conta_pretos(objetivo, jogada);
    int quant_brancos = conta_brancos(objetivo, jogada);

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

int leia_int() {
    int var;
	while (scanf("%d", &var) != 1) {
		scanf("%*[^\n]");
		printf("\nInforme apenas numeros!\n");
	}

    return var;
}