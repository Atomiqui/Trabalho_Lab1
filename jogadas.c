#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <curses.h>
#include<stdbool.h>

#include "jogadas.h"

void jogar(int *objetivo){
    for(int i = 0; i < 1; i++) {
        int *jogada = joga_le_jogada();
        if(joga_verifica_jogada(objetivo, jogada)) {
            return;
        }
    }

    printf("Acabaram suas tentativas!\n\tGAME OVER\n");
}

int *joga_sortear_cores() {
    int *cores_sorteadas = (int *) malloc(4 * sizeof(int));
    cores_sorteadas[0] = 7;
    cores_sorteadas[1] = 7;
    cores_sorteadas[2] = 7;
    cores_sorteadas[3] = 7;
    
    for(int i = 0; i < 4; i++) {
        int pos_sorteada = rand() % 7;
        if(cores_sorteadas[i] != pos_sorteada) {
            cores_sorteadas[i] = pos_sorteada;
        } else {
            i--;
        }
    }
    
    return cores_sorteadas;
}

int *joga_le_jogada() {
   int *jogada = (int *) malloc(4 * sizeof(int));

   do {
    printf("Insira sua jogada:\n");
    if(scanf("%d %d %d %d", &jogada[0], &jogada[1], &jogada[2], &jogada[3]) != 1) {
        puts("Insira apenas números!\n");
        jogada[0] = 7;
        jogada[1] = 7;
        jogada[2] = 7;
        jogada[3] = 7;
    }
   } while (valida_jogadas(jogada));
   
   
   
   return jogada;
}

bool joga_verifica_jogada(int *objetivo, int *jogada) {
    int acertos = 0;

    for(int i = 0; i < 4; i++) {
        if(objetivo[i] == jogada[i]) {
            acertos++;
        }
    }

    /*  TODO: Vai virar uma função dedicada, pois deverá:
    *   • Pontuar;
    *   • Chamar uma atualização de ranking;
    *   • Encerrar a partida (dar opção de jogar de novo);
    *   • Gerenciar a tela dos itens acima;
    * 
    *   TODO: Tenho que verificar a posição dos números;
    */
    printf("Acertos: %d\n", acertos);
    if(acertos == 4) {
        printf("Parabéns você acertou!");
        return true;
    }

    return false;
}

// Funções Auxiliares:

// se vai ser usada uma tela, n tem necessidade...

bool valida_jogadas(int *jogada) {
    for(int i = 0; i < 4; i++) {
        if(jogada[i] < 0 || jogada[i] > 6) {
            return false;
        } 
    }

    return true;
}