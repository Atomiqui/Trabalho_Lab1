#include "jogadas.h"

int main() {
    printf("Bem vindo ao Mastermind!\n");

    char controle, **objetivo;
    tela_print_regras();

    do {
        objetivo = joga_sortear_cores();
        // Descomente para ver o segredo sorteado ao início:
        printf("O segredo sorteado foi: %c %c %c %c\n", objetivo[0][1], objetivo[1][1], objetivo[2][1], objetivo[3][1]);
        int *ranking = le_ranking();
        /*for(int i = 0; i < 5; i++) {
            printf("Rk%d: %d\n", i, ranking[i]);
        }*/
        jogar(objetivo);
        printf("Quer jogar novamente?\n(Y/N)");
        scanf(" %c", &controle);
        while(controle != 'y' && controle != 'Y' && controle != 'n' && controle != 'N') {
            printf("Entrada inválida, tente novamente:\n");
            scanf(" %c", &controle);
        }
    } while (controle == 'y' || controle == 'Y');

    for(int i = 0; i < 7; i++) {
        free(objetivo[i]);
    }
    free(objetivo);

    printf("Obrigado por jogar, espero que tenha se divertido e não tenha encontrado nenhum bug! ;)\n");

    return 0;
}