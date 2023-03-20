#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(){
    int tentativas = 0;
    int i = 0;
    int j = 0;
    int acertos = 0;
    int cores[4];
    int jogada[4];
    char secreta[4];
    char possiveis[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    
    srand(time(NULL));

// Sorteia a sequência secreta
    for (i=0; i<4; i++){
        cores[i] = rand() % 7;
        secreta[i] = possiveis[cores[i]];
    }

// Permite que o usuário tente adivinhar a sequência
    do {
        acertos = 0;
        printf("Entre com sua tentativa: ");
        for (i=0; i<4; i++){
            scanf(" %c", (char *) &jogada[i]);
        }

// Confere se a jogada foi igual a sequência secreta
        for (i=0; i<4; i++){
            for (j=0; j<4; j++){
                if (jogada[j] == secreta[i]){
                    if (i == j){
                        printf("\033[30;47m%c\033[0m", jogada[i]);
                        acertos++;
                    }
                    else {
                        printf("\033[30;46m%c\033[0m", jogada[i]);
                    }
                }
            }
        }
        printf("\n");

// Incrementa o número de tentativas
        tentativas++;
    } while (acertos < 4 && tentativas < 10);

// Exibe mensagem de acordo com o resultado
    if (acertos == 4){
        printf("Parabéns! Você acertou a sequência secreta!\n");
    }
    else {
        printf("Você não acertou a sequência secreta.\n");
    }

return 0;
}