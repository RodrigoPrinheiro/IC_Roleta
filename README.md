# Gather around my friends this is a roulette for IC.


# **IC: Projeto Roleta**
## Trabalho Realizado por: Rodrigo Pinheiro_a21802488 e Tomás Franco_a21803301.
### Solução
  + Ao início, como queriamos aprender melhor como trabalhar com o git, procurámos dar setup do repositório que usámos do github. Dávamos update a partir do [gitbash](https://help.github.com/articles/adding-an-existing-project-to-github-using-the-command-line/) utilizando uma pasta local .git. Após termos isto resolvido, acabámos por simplesmente dar merge no master branch sempre que tinhamos algo novo de relevante no código.
  + Grande parte do trabalho foi entender que funções é que eram mesmo necessárias ou utéis ter e separar do que facilmente pode ser feito e implementado na função main().

### Referencias
+ As bibliotecas utilizadas foram o <stdio.h>, <time.h> e <stdlib.h>.
#### Troca de Ideias
+ É um jogo de roleta, tens um aviso no inicio a dar os controlos (comand_list()) e de seguida o jogo vai te pedir oque queres fazer, de acordo com esses controlos, após inserires um valor para apostar com a opcao b podes escolher um nr para apostar e depois disso podes dar roll para saberes se ganhaste ou não.
+ Tudo em comandos separados.
+ O even e o odd sao controlos que nao precisas de escolher qual é o nr em que apostas especificamente (o mesmo se aplica as cores RED e BLACK), mas tens de pedir para dar roll posteriormente de escolheres essas opcoes.
Depois o jogo fica num loop em que pede os controlos do jogador e da a resposta adequada ATÉ ficar sem dinheiro ou selecionar a opcao s(sair) para sair do jogo.

+ **PS.: Very cool thing you can do inside switches, podes simplesmente escrever uma palavra com dois pontos a frente por exemplo label: e depois escreves wherever you want goto label e o codigo corre a partir da label.
