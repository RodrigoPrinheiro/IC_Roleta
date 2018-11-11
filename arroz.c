#include <stdio.h>
#include <time.h>
//inicializar
int Start();
int rollr();
void comand_list(int Creditos);
void help();
int show_Balance(int Creditos,int bet);
int odd_even(int number, int choice, int cashBet, int Creditos);
int color_check(int roll, int color);
int number_compare(int n, int numberBet);

int main(){
  //variaveis
  int Creditos = 100;
  int cashBet, numberBet, n, playerDecision;
  char choice[2], color[1], R, B;
  int asd = 1;
  //delcarar arrays para vermelho e preto(18 de tamanho, nrs especificos go see rules)
  //welcome titles

  Start();
  comand_list(Creditos);
  printf("\nWhat do you want to do?\n");
  //incio--------------------------------------------------------------------------
  while (Creditos > 0){
    playerDecision = 0;
    switchStart:
    scanf("%c",choice);
    switch(choice[0]){
      case 'b': //player chooses how much to bet___________________________________
        help();
        printf("\n\nBet: ");
        scanf("%d", &cashBet);
        if (cashBet > Creditos){
          printf("Too high, try a bit lower than your earnings.\n");
        }else if(cashBet <= 0){
          printf("We're not here to exchange candy, only money.\n");
        }else{
          printf("You just bet %d for this round\n", cashBet);
          Creditos -= cashBet;
          show_Balance(Creditos, cashBet);
        }
        break;
      case 'n': // player chooses to bet on a number________________________________
        help();
        printf("C'mon then pick one between 1 and 35\n");
        scanf("%d", &numberBet);
        printf("You just bet on the number %d.\n", numberBet);
        choice[1] = 'n';
        break;
      case 'h': // player wants to see control list_________________________________
        help();
        break;
      case 'r': // roll the numbers_________________________________________________
        if (playerDecision == 0){
          printf("lets roll.\n");
          n =rollr();
          playerDecision = 1;
          if (choice[1] == 'e'){
            odd_even(n,choice[1],cashBet,Creditos);
          }else if(choice[1] == 'o'){
            odd_even(n,choice[1],cashBet,Creditos);
          }else if(choice[1] == 'c'){
            color_check(n, color[0]);
          }else if(choice[1] == 'n'){
            number_compare(n, numberBet);
          }
          break;
        }else{
          printf("You need to bet first!\n");
        }
        break;
      case 's': // player wants to see balance______________________________________
        help();
        show_Balance(Creditos, cashBet);
        choice[1] = 's';
        break;
      case 'e': // player bets on an even number. Pays 2 to 1_______________________
        help();
        printf("Alright champ, roll when you are ready.\n");
        choice[1] = 'e';
        break;
      case 'o': // player bets on an odd number. Pays 2 to 1________________________
        printf("Odd it is, roll when you wish.\n");
        choice[1] = 'o';
        break;
      case 'c': // player picks a color on the board red or black to bet____________
        printf("Feeling colorfull aye? In wich color do you want to bet?\nDecision(r or b):\n");
        scanf("%c", color);
        printf("Acknowledged, whenever you are ready, roll.\n");
        choice[1] = 'c';
        break;
    }
  }
  printf("Well... you are finally out of credits. Leave or we'll kick you out.");
  getchar();
  return 0;
}
