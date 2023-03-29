#include <ncurses.h>

int main() {
    // Inicializa a biblioteca ncurses
    initscr();

    // Ativa a exibição de cores
    start_color();

    init_color(1, 965, 915, 670);   // bege
    init_color(2, 0, 1000, 1000);   // ciano
    init_color(3, 1000, 765, 0);    // dourado
    init_color(4, 0, 1000, 500);    // esmeralda
    init_color(5, 780, 300, 0);     // ferrugem
    init_color(6, 450, 500, 540);   // gris

    int COLOR[7] = {COLOR_BLUE, 1, 2, 3, 4, 5, 6};

    // Define as cores do texto e do fundo
    for(int i = 1; i < 8; i++) {
        init_pair(i, COLOR_WHITE, COLOR[i]);
    }
    

    // Define as coordenadas e dimensões do retângulo
    int x = 3;
    int y = 1;
    int largura = 5;
    int altura = 3;

    for(int i = 1; i < 8; i++) {
        // Cria uma janela para o retângulo
        WINDOW* retangulo = newwin(altura, largura, y, x);
        // Define a cor da janela
        wbkgd(retangulo, COLOR_PAIR(i));
        // Imprime a borda do retângulo
        box(retangulo, 0, 0);
        // Imprime o texto dentro do retângulo
        mvwprintw(retangulo, 1, 2, "A");

        // Atualiza a tela para exibir o retângulo
        refresh();
        wrefresh(retangulo);

        x += largura + 1;
    }
        
    // Espera pelo usuário pressionar uma tecla para sair
    getch();

    // Encerra a biblioteca ncurses
    endwin();

    return 0;
}
