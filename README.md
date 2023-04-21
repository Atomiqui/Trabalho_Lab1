# Trabalho de Laboratório de Programação 1
## Objetivo:

_Criação de um jogo semelhante ao mastermind, conforme as especificações dadas pelo professor._

## Especificações:
 
* O programa deve sortear uma sequência de 4 cores, entre sete possíveis, que não se repitam; (V)
* O jogador tem até 10 chances; (V)
* Escolha 7 cores e 7 letras que as representem; (V)
    * Não pode ter preto nem branco. (V)
* Uma jogada é feita digitando uma string de 4 caracteres, todos diferentes, correspondentes às quatro cores que o jogador quer chutar; (V)
* Após receber uma jogada, o programa deve validá-la e somente aceitar se contiver 4 cores válidas e não repetidas; (V)
* Após uma jogada, o programa deve imprimir retângulos com as cores correspondentes à jogada, um ao lado do outro, cada um ocupando pelo menos 3 linhas de 5 caracteres cada, com a letra no centro; (v)
* Ao lado, deve imprimir retângulos correspondentes à resposta: um retângulo preto para cada cor chutada na posição certa seguidos de retângulos brancos, um para cada cor que esteja em posição diferente na sequência secreta; (v)
* Se o jogador acertar as quatro cores, serão impressos 4 retângulos pretos; (v)
    * o programa deve felicitar o jogador e encerrar a partida. (v)
* Caso o jogador não acerte na nona jogada, o jogo deve informá-lo do infortúnio e encerrar a partida; (v)
* Ao final de uma partida, o jogo deve perguntar se o jogador quer jogar outra; (v)
* Se a partida não for ganha, o programa deve mostrar a sequência secreta; (v)
* Se a partida for ganha, deve mostrar a pontuação final e as 5 maiores pontuações da história, com o nome dos pontuadores; (v)
  * Caso a pontuação obtida pelo jogador estiver entre as 5 maiores, o programa deve perguntar o nome do jogador e alterar a lista das 5 maiores pontuações; (v)
  * As 5 maiores pontuações devem ser mantidas em um arquivo, e devem ser recuperadas em execução; (v)
  * A eventual inexistência do arquivo deve ser aceita pelo programa, entendida como não tendo ainda a lista de 5 maiores pontuações; (v)
* O jogador pode também digitar comandos:
    * Se o comando for ?, o programa deve imprimir uma tabela com as cores e as letras que as representam; (v)
    * Se o comando for !, o programa deve mostrar todar as respostas que já deu na partida; (v)
    * Acrescente um comando para desistir da partida (comando escolhido: ;). (v)
* A pontuação de uma partida é obtida somando-se a pontuação de cada jogada da partida e multiplicando o total pelo bônus final. Cada cor certa no lugar certo vale 5 pontos, cada cor existente no lugar errado vale 3 pontos. (alterado em acordo) (v)

### Regras de formatação

- Nenhuma função do programa deve ter mais de 22 linhas entre o '{' inicial e o '}' final.
- Nenhuma linha deve ter mais de um ';' (os dois ';' do `for` não contam).
- Em linhas que contenham o caractere '{', esse deve ser o último caractere da linha.
- Em linhas que contenham o caractere '}', esse deve ser o único caractere da linha que não é um espaço.
- Logo antes de cada função deve ter um comentário sucinto dizendo o que ela faz.
- Toda a entrada e saída do programa (exceto aquelas para manter a lista de pontuações em arquivo) deve ser realizada usando as funções em tela.h.

## Construção do trabalho:
### Para compilar:
```
gcc -o mastermind mastermind.c jogadas.c tela.c ranking.c -lncurses
```

### 