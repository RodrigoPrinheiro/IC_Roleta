# Gather around my friends this is a roulette for IC.


# **IC: Projeto Roleta**
## Trabalho Realizado por: Rodrigo Pinheiro_a21802488 e Tomás Franco_a21803301.
#### [Repositório do github](https://github.com/RodrigoPrinheiro/IC_Roleta).
### Solução
  + Ao início, como queriamos aprender melhor como trabalhar com o git, procurámos dar setup do repositório que usámos do github. Dávamos update a partir do [gitbash](https://help.github.com/articles/adding-an-existing-project-to-github-using-the-command-line/) utilizando uma pasta local .git. Após termos isto resolvido, acabámos por simplesmente dar merge no master branch sempre que tinhamos algo novo de relevante no código.
  + Grande parte do trabalho foi entender que funções é que eram mesmo necessárias ou utéis ter e separar do que facilmente pode ser feito e implementado na função main().
  + Criação de funçoes
  + implementação da nossa propria header file (func_roleta.h) para usarmos no arroz.c. Isto foi alcançado pela informação que tinhamos das aulas e uma pequena ajuda do [StackOverflow](https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c).
  + Criação de um sistema para gravar o dinheiro ganho num jogo anterior, podendo fechar e abrir o programa, e partir de um ficheiro extra e com o uso das funcoes fprintf, fscanf, fopen e fclose, carregar o dinheiro ganho numa sessão anterior. Visto que não foi matéria dada usamos o site [Learn C](https://www.programiz.com/c-programming/c-file-input-output) para este feature.
  + ...

### Referencias
##### Bibliotecas usadas
+ As bibliotecas utilizadas foram o <stdio.h>, <time.h> e <stdlib.h>.
##### Competencias
+ Como jogar Roleta.
+ Melhor percepção do que é programar em equipa.
+ Mais conhecimentos gerais sobre C e bases de git(push, pull etc...).
+ Familiarização com a consola Ubuntu.
+ Criação de "save files" para variaveis no jogo.
+ Aprendemos a usar com goto de labels durante um switch.

##### Troca de Ideias
+ É um jogo de roleta, tens um aviso no inicio a dar os controlos (comand_list()) e de seguida o jogo vai te pedir oque queres fazer, de acordo com esses controlos, após inserires um valor para apostar com a opcao b podes escolher um nr para apostar e depois disso podes dar roll para saberes se ganhaste ou não.
+ Tudo em comandos separados.
+ O even e o odd sao controlos que nao precisas de escolher qual é o nr em que apostas especificamente (o mesmo se aplica as cores RED e BLACK), mas tens de pedir para dar roll posteriormente de escolheres essas opcoes.
Depois o jogo fica num loop em que pede os controlos do jogador e da a resposta adequada ATÉ ficar sem dinheiro ou selecionar a opcao s(sair) para sair do jogo.
+ Houve troca de ideias entre o nosso grupo e o aluno João David do mesmo turno para a criação correta das funções save_game() e load_game()
