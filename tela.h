#ifndef TELA_H
#define TELA_H

#include <stdbool.h>
#include <string.h>
#include <ncurses.h>

// Printa as regras do jogo.
void tela_print_regras();

// Laço para leitura de jogadas.
void tela_le_jogada(char *jogada);

// Retorna false se a jogada é válida
bool tela_valida_jogadas(char *jogada);

// Desenha os respectivos retângulos que representam a jogada e os que representam a dica (pretos e brancos).
void tela_desenha_retangulos(char *jogada, int pretos, int brancos);

/* FUNÇÕES AUXILIARES */

// lê uma string e verifica o tamanho (se é igual a 4) e se tem letras repetidas;
void tela_leia_char(char *var);

// Recebe uma string e retorna 'true' se tem letras repetidas.
bool tela_repetidos(char *jogada);

/*  
    -   Inicializa a biblioteca ncurses;
    -   Inicia a exibição de cores;
    -   Inicia as cores que vamos precisar;
    -   'registra' cada cor com um código de 1 a 9.
*/
void tela_inicia_ncurses();

/*
    -   Recebe as coordenadas e as dimenções do primeiro retângulo;
    -   Cria a janela para exibir o retângulo
    -   Define a cor com base na 'calc_num_letra'
    -   Print na letra que está sendo tratada;
    -   att tela e mostra o retângulo;
    -   Incrementa o X para que os retângulos fiquem um ao lado do outro.
*/
void tela_desenha(char *jogada, int altura, int largura, int y, int x);

/*
    -   Retorna um número de 1 a 7 que representa uma letra de 'a' a 'g';
    -   Esse número é usado para escolher a cor, já que elas foram registradas
        em ordem alfabética e com identificadores numéricos crescentes;
        (a = 1, B = 2, ...)
*/
int calc_num_letra(char letra);

// Mostra o objetivo para o jogador (tem opção para mostrar com cores :))
void print_objetivo(char **objetivo);

// Printa as jogadas anteriores, com direito a pontinhos (•○) para as dicas.
void jogadas_anteriores(char **historico, char **objetivo, int *i);

// Função para ler o nickname dessa lenda no pódio
char *le_nickname();

#endif // TELA_H