#include <stdio.h>
#include <stdlib.h>

#include "jogadas.h"
#include "tela.h"

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

   printf("Bem vindo ao Mastermind! • ○\n");
   //tela_cria();
   int *objetivo = joga_sortear_cores();
   jogar(objetivo);

    return 0;
}