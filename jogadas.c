#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <stdbool.h>
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
    print_regras();

    for(int i = 0; i < 9; i++) {
        joga_le_jogada(jogada);
        if(joga_verifica_jogada(objetivo, jogada, &pontos)) {
            if(pontos == 0) {
                printf("\tGAME OVER\n");
                return;
            }
            printf("Parabéns, você acertou a combinação secreta!\nSeu score é: %d.", pontos);
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

    if(strcmp(jogada, "?") == 0) {
        print_regras();
    } else if(strcmp(jogada, "!") == 0) {

    } else if(strcmp(jogada, ";") == 0) {
        pontos = 0;
        return true;
    } else {
        int pretos = conta_pretos(objetivo, jogada);
        int brancos = conta_brancos(objetivo, jogada);
        *pontos += pretos*5 + brancos*3;
        desenha_retangulos(jogada, pretos, brancos);
        printf("Pretos: %d.\nBrancos: %d.\n", pretos, brancos);
        if(pretos == 4) {
            return true;
        }
    }

    return false;
}

// Funções Auxiliares:

int conta_pretos(char **objetivo, char *jogada) {
    int pretos = 0;

    for(int i = 0; i < 4; i++) {
        if(objetivo[i][0] == jogada[i] || objetivo[i][1] == jogada[i]) {
            pretos++;
        }
    }

    return pretos;
}

int conta_brancos(char **objetivo, char *jogada) {
    int brancos = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if((jogada[i] == objetivo[j][0] || jogada[i] == objetivo[j][1])) {
                brancos++;
            }
        }
    }

    return brancos;
}

bool valida_jogadas(char *jogada) {
    leia_char(jogada);

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

void leia_char(char *var) {
    scanf("%s", var);
    bool tamanho = strlen(var) != 4;
    bool rep = repetidos(var);

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
        rep = repetidos(var);
    }
}

bool repetidos(char *jogada) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if((jogada[i] == jogada[j] || jogada[i]+32 == jogada[j] || jogada[i]-32 == jogada[j]) && i != j) {
                return true;
            }
        }
    }
    return false;
}

void print_regras() {
    printf("\tREGRAS\n"
        "A/a - AZUL\n"
        "B/b - BEGE\n"
        "C/c - CIANO\n"
        "D/d - DOURADO\n"
        "E/e - ESMERALDA\n"
        "F/f - FERRUGEM\n"
        "G/g - GRIS\n"
        " !  - Ver respostas anteriores.\n"
        " ;  - Desistir.\n");
}

void desenha_retangulos(char *jogada, int pretos, int brancos) {
    inicia_ncurses();

    int x = 3, y = 1, largura = 5, altura = 3;
    
    for(int i = 0; i < 4 ; i++) {
        WINDOW* retangulo = newwin(altura, largura, y, x);
        int j = calc_num_letra(jogada[i]);
        wbkgd(retangulo, COLOR_PAIR(j));
        mvwprintw(retangulo, 1, 2, "%c", jogada[i]);
        refresh();
        wrefresh(retangulo);
        x += largura+1;
    }

    int brancos_alem = brancos-pretos;
    x = 35;

    for(int i = 0; i < brancos; i++) {
        WINDOW* retangulo = newwin(altura, largura, y, x);
        if(pretos > i) {
            wbkgd(retangulo, COLOR_PAIR(8));
        } else {
            wbkgd(retangulo, COLOR_PAIR(9));
        }
        refresh();
        wrefresh(retangulo);
        x += largura+1;
    }
    
    getch();
    endwin();
}

void inicia_ncurses() {
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

int calc_num_letra(char letra) {
    if(letra >= 'a' && letra <= 'g') {
        return letra - 'a' + 1;
    } else {
        return letra - 'A' + 1;
    }
}