# Trabalho de Laboratório de Programação 1
## Objetivo:

_Criação de um jogo semelhante ao mastermind, conforme as especificações dadas pelo professor._

## Especificações:
 
* O programa deve sortear uma sequência de 4 cores, entre sete possíveis, que não se repitam; (V)
* O jogador tem até 9 chances; (V)
* Escolha 7 cores e 7 letras que as representem; (V)
    * Não pode ter preto nem branco. (V)
* Uma jogada é feita digitando uma string de 4 caracteres, todos diferentes, correspondentes às quatro cores que o jogador quer chutar; (V)
* Após receber uma jogada, o programa deve validá-la e somente aceitar se contiver 4 cores válidas e não repetidas; (V)
* Após uma jogada, o programa deve imprimir retângulos com as cores correspondentes à jogada, um ao lado do outro, cada um ocupando pelo menos 3 linhas de 5 caracteres cada, com a letra no centro; (v)
* Ao lado, deve imprimir retângulos correspondentes à resposta: um retângulo preto para cada cor chutada na posição certa seguidos de retângulos brancos, um para cada cor que esteja em posição diferente na sequência secreta; (v)
* Se o jogador acertar as quatro cores, serão impressos 4 retângulos pretos;
    * o programa deve felicitar o jogador e encerrar a partida. (v)
* Caso o jogador não acerte na nona jogada, o jogo deve informá-lo do infortúnio e encerrar a partida; (v)
* Ao final de uma partida, o jogo deve perguntar se o jogador quer jogar outra(v);
* Se a partida não for ganha, o programa deve mostrar a sequência secreta. ();
* Se a partida for ganha, deve mostrar a pontuação final e as 5 maiores pontuações da história, com o nome dos pontuadores. ();
  * Caso a pontuação obtida pelo jogador estiver entre as 5 maiores, o programa deve perguntar o nome do jogador e alterar a lista das 5 maiores pontuações ();
  * As 5 maiores pontuações devem ser mantidas em um arquivo, e devem ser recuperadas em execução ();
  * A eventual inexistência do arquivo deve ser aceita pelo programa, entendida como não tendo ainda a lista de 5 maiores pontuações ().
* O jogador pode também digitar comandos:
    * Se o comando for ?, o programa deve imprimir uma tabela com as cores e as letras que as representam; (v)
    * Se o comando for !, o programa deve mostrar todar as respostas que já deu na partida; ()
    * Acrescente um comando para desistir da partida (comando escolhido: ;). (v)
* A pontuação de uma partida é obtida somando-se a pontuação de cada jogada da partida e multiplicando o total pelo bônus final. Cada cor certa no lugar certo vale 5 pontos, cada cor existente no lugar errado vale 3 pontos.
* 

## Exemplo
Se as cores secretas são "XVBR" e o chute do jogador é "vaxr", a resposta do programa pode ser algo assim:

<div align="center">

![EXEMPLO CORES](cores.png)

</div>

#### Regras de formatação

- Nenhuma função do programa deve ter mais de 22 linhas entre o '{' inicial e o '}' final. (*main* é uma função do programa).
- Nenhuma linha deve ter mais de um ';'.
- Em linhas que contenham o caractere '{', esse deve ser o último caractere da linha.
- Em linhas que contenham o caractere '}', esse deve ser o único caractere da linha que não é um espaço.

#### **DICAS**

Como organizar o programa.

Podem ser jogadas várias partidas, então o programa deve conter um laço como:
```
apresentação
repete
  joga uma partida
  pergunta se quer jogar mais
enquanto o usuário quizer jogar
despedida
```

Uma partida consiste de um certo número de jogadas, algo como:
```
inicializa a partida (sorteia as cores)
repete
  lê uma jogada
  se for especial (inválida,!,?,...)
    processa jogada especial
  senão (jogada normal)
    calcula resposta
    mostra jogada e resposta
até adivinhar ou desistir ou acabarem as chances
```

## Construção do trabalho:
Validção está sendo bem chatinho de elaborar e pensar sobre as possibilidades.

To criando todas as funções dentro de jogadas.c/.h e depois passo para tela.c/.h o que for relacionado a tela.

Para executar o mastermind.c:
```
gcc -o mastermind mastermind.c jogadas.c tela.c ranking.c -lncurses
```

Para executar o teste.c:
```
gcc -o teste teste.c -lncurses
```

* Otimizar as funções;
* Contar a quantidade de linhas em cada função;
* Criar ranking;
* Opção de rever jogadas.
* Sempre que fizer uma jogada vai abrir uma tela para mostrar os retangulos e o jogador vai ter que  clicar em um botão qualquer para fechar a tela, colocar esse aviso.

```
testeseila | 4760
testeseila | 3760
testeseila | 3560
testeseila | 2760
testeseila | 2560
```

* comando: ; está pontuando igual.