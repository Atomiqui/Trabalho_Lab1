#include "jogadas.h"

int main() {
    printf("\tBem vindo ao Mastermind!\n");

    char controle, **objetivo = joga_sortear_cores();
    // Descomente para ver o segredo sorteado ao início:
    //printf("O segredo sorteado foi: %c %c %c %c\n", objetivo[0][1], objetivo[1][1], objetivo[2][1], objetivo[3][1]);

    do {
        jogar(objetivo);
        printf("Quer jogar novamente?\n(Y/N)");
        scanf(" %c", &controle);
        while(controle != 'y' && controle != 'Y' && controle != 'n' && controle != 'N') {
            printf("Entrada inválida, tente novamente:\n");
            scanf(" %c", &controle);
        }
    } while (controle == 'y' || controle == 'Y');

    printf("Obrigado por jogar, espero que tenha se divertido e não tenha encontrado nenhum bug! ;)\n");

    return 0;
}