#include <ncurses.h>

int main() {
    // Inicializa a biblioteca ncurses
    initscr();

    // Ativa a exibição de cores
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
    
    for(int i = 1; i < 8; i++) {
        init_pair(i, COLOR_WHITE, i);
    }

    // Define as coordenadas e dimensões do retângulo
    int x = 3;
    int y = 1;
    int largura = 5;
    int altura = 3;
    
    for(int i = 1; i < 8 ; i++) {
        WINDOW* retangulo = newwin(altura, largura, y, x);
        wbkgd(retangulo, COLOR_PAIR(i));
        mvwprintw(retangulo, 1, 2, "A");
        refresh();
        wrefresh(retangulo);
        x += largura+1;
    }
    
    getch();
    endwin();

    return 0;
}
