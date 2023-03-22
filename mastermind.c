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

    char **objetivo = joga_sortear_cores();
    printf("O segredo sorteado foi: %c %c %c %c\n", 
    objetivo[0][1], objetivo[1][1], objetivo[2][1], objetivo[3][1]);

    //tela_cria();
    jogar(objetivo);

    return 0;
}