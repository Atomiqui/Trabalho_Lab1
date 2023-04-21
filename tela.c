#include <stdio.h>

#include "tela.h"
#include <stdlib.h>
#include "jogadas.h"

void tela_print_regras() {
    printf("\tREGRAS\n"
        "A/a - AZUL\n"
        "B/b - BEGE\n"
        "C/c - CIANO\n"
        "D/d - DOURADO\n"
        "E/e - ESMERALDA\n"
        "F/f - FERRUGEM\n"
        "G/g - GRIS\n"
        " !  - Ver respostas anteriores.\n"
        " ;  - Desistir.\n"
        " ?  - Ver regras.\n");
}

void tela_le_jogada(char *jogada) {
    do {
        printf("Insira sua jogada:\n");
    } while (tela_valida_jogadas(jogada));
}

bool tela_valida_jogadas(char *jogada) {
    tela_leia_char(jogada);

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

void tela_desenha_retangulos(char *jogada, int pretos, int brancos) {
    tela_inicia_ncurses();

    int x = 3, y = 1, largura = 5, altura = 3;
    
    tela_desenha(jogada, altura, largura, y, x);

    int brancos_alem = brancos-pretos;
    x = 35;

    for(int i = 0; i < 4; i++) {
        WINDOW* retangulo = newwin(altura, largura, y, x);
        if(pretos > i) {
            wbkgd(retangulo, COLOR_PAIR(8));
        } else if(brancos > i){
            wbkgd(retangulo, COLOR_PAIR(9));
        } else {
            wbkgd(retangulo, COLOR_PAIR(0));
        }
        refresh();
        wrefresh(retangulo);
        x += largura+1;
    }
    
    getch();
    endwin();
}

void tela_leia_char(char *var) {
    scanf("%s", var);
    bool tamanho = strlen(var) != 4;
    bool rep = tela_repetidos(var);

    while (tamanho || rep) {
        if((strcmp(var,"?") == 0 || strcmp(var,"!") == 0 || strcmp(var,";") == 0)) {
            return;
        }

        if(rep) {
            printf("As jogadas não devem conter cores repetidas!\n");
        }

        if(tamanho) {
            puts("As jogadas devem ser feitas usando 4 símbolos, "
                 "não utilize mais ou menos do que isso!\n");
        }

        puts("Tente novamente!");
        scanf("%s", var);
        tamanho = strlen(var) != 4;
        rep = tela_repetidos(var);
    }
}

bool tela_repetidos(char *jogada) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if((jogada[i] == jogada[j] || jogada[i]+32 == jogada[j] || jogada[i]-32 == jogada[j]) && i != j) {
                return true;
            }
        }
    }
    return false;
}

void tela_inicia_ncurses() {
    initscr();
    start_color();

    // Descobri que a cor com identificador '0' é colocada como cor de fundo do terminal.
    // Define a cor de fundo do terminal como cinza.
    init_color(0, 300, 300, 300);

    init_color(1, 0, 0, 1000);      // azul
    init_color(2, 965, 915, 670);   // bege
    init_color(3, 0, 1000, 1000);   // ciano
    init_color(4, 1000, 765, 0);    // dourado
    init_color(5, 0, 1000, 500);    // esmeralda
    init_color(6, 780, 300, 0);     // ferrugem
    init_color(7, 450, 500, 540);   // gris
    init_color(8, 0, 0, 0);   // gris
    init_color(9, 1000, 1000, 1000);   // gris
    
    for(int i = 1; i < 10; i++) {
        init_pair(i, COLOR_WHITE, i);
    }
}


void tela_desenha(char *jogada, int altura, int largura, int y, int x) {
    for(int i = 0; i < 4 ; i++) {
        WINDOW* retangulo = newwin(altura, largura, y, x);
        int j = calc_num_letra(jogada[i]);
        wbkgd(retangulo, COLOR_PAIR(j));
        mvwprintw(retangulo, 1, 2, "%c", jogada[i]);
        refresh();
        wrefresh(retangulo);
        x += largura+1;
    }
}


int calc_num_letra(char letra) {
    if(letra >= 'a' && letra <= 'g') {
        return letra - 'a' + 1;
    } else {
        return letra - 'A' + 1;
    }
}

void print_objetivo(char **objetivo) {
    char objetivo2[4] = {objetivo[0][1], objetivo[1][1], objetivo[2][1], objetivo[3][1]};
    printf("A sequencia correta era: %s\n\n", objetivo2);

    char cont;
    printf("Gostaria de ver as cores?\n[1] - sim\n[2] - não\n");
    scanf(" %c", &cont);
    if(cont == '1') {
        tela_desenha_retangulos(objetivo2, 0 ,0);
    }
}

void jogadas_anteriores(char **historico, char **objetivo, int *i) {
    printf("\tJogadas anteriores:\n");
    for(int j = 0; j < *i; j++) {
        printf("%s | ", historico[j]);
        int pretos = conta_pretos(objetivo, historico[j]);
        int brancos = conta_brancos(objetivo, historico[j]);
        for(int j = 0; j < 4; j++) {
            if(pretos > j) {
                printf("•");
            } else if(brancos > j){
                printf("○");
            }
        }
        puts("\n");
    }
    *i -= 1;
}

char *le_nickname() {
    char *nome = malloc(15 * sizeof(char));
    printf("Parabés! Você teve um ótimo desempenho, queremos registrar isso.\nInforme seu nome (no máximo 15 caracteres): ");
    scanf("%s", nome);
    return nome;
}