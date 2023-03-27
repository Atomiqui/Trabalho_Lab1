#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "jogadas.h"
//#include "tela.h"

int main() {
    /*
    *   Estrutura de funcionamento:
    *       • Início de uma partida; V
    *       • Sorteio do objetivo; V
    *       • Laço para ocorrerem as tentativas; v
    *           • Desenha tela;
    *           • Le jogada;
    *           • Verifica jogada;
    *           • Calcula pontuação;
    *           • Informa resultado;
    * 
    *       • Se a verificação retornar true para vitória, encerramos a partida e damos a opção de jogar novamente.
    * 
    *       TODO: Implementar o limite de jogadas (provavelmente no laço).
    */

    printf("\tBem vindo ao Mastermind!\n");

    char controle;
    char **objetivo = joga_sortear_cores();
    printf("O segredo sorteado foi: %c %c %c %c\n", 
    objetivo[0][1], objetivo[1][1], objetivo[2][1], objetivo[3][1]);

    //tela_cria();

    do {
        jogar(objetivo);
        puts("Quer jogar novamente?\n(Y/N)");
        scanf("%c", &controle);
        while(strcmp(&controle, "y") != 0 || strcmp(&controle, "Y") != 0 || strcmp(&controle, "n") != 0 || strcmp(&controle, "N") != 0) {
            puts("Entrada inválida, tente novamente:\n");
            scanf("%c", &controle);
        }
    } while (strcmp(&controle, "y") == 0 || strcmp(&controle, "Y") == 0);

    puts("Obrigado por jogar, espero que tenha se divertido e não encontrado nenhum bug! ;)");

    return 0;
}