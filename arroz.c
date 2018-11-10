#include <stdio.h>
#include <time.h>

FILE *in_file = fopen("Creditos.txt", "r");
FILE *out_file = fopen("Creditos.txt", "w");
//inicializar
int Start();
int rollr();
void comand_list(int Creditos);
void help();
int show_Balance(int Creditos,int bet);
int odd_even(int number, int choice, int cashBet);

int main(){
  //variaveis
  int Creditos = 100;
  int cashBet, numberBet, n;
  char choice[1], R, B;
  //delcarar arrays para vermelho e preto(18 de tamanho, nrs especificos go see rules)
  //welcome titles

  Start();
  comand_list(Creditos);

  //incio
  while (Creditos > 0){
    switchStart:
    printf("What do you want to do?");
    scanf("%c",choice);
    switch(choice[0]){
      case 'b': //player chooses how much to bet
        printf("\n\nBet: ");
        scanf("%d", &cashBet);
        if (cashBet > Creditos){
          printf("too high, try a bit lower than your earnings");
        }else if(cashBet <= 0){
          printf("We're not here to exchange candy, only money.\n");
        }else{
          printf("You just bet %d for this round\n", cashBet);
          Creditos -= cashBet;
          show_Balance(Creditos, cashBet);
        }
        break;
      case 'n': // player chooses to bet on a number
        printf("C'mon then pick one between 1 and 35");
        scanf("%d", &numberBet);
        printf("You just bet on the number %d for this round\n", numberBet);
        break;
      case 'h': // player wants to see control list
        help();
        break;
      case 'r': // roll the numbers
        printf("lets roll.");
        rollr();
        break;
      case 's': // player wants to see balance
        show_Balance(Creditos, cashBet);
        break;
      case 'e': // player bets on an even number. Pays 2 to 1
        break;
      case 'o': // player bets on an odd number. Pays 2 to 1
        break;
      case 'c': // player picks a color on the board red or black to bet
        break;
    }
  }
  printf("Well... you are finally out of credits. Leave or we'll kick you out");
  getchar();
  return 0;
}
