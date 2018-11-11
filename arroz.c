#include <stdio.h>
#include <time.h>
//inicializar funçoes--------------------------------------------------------------
int Start();
int rollr();
void comand_list(int Creditos);
void help();
int show_Balance(int Creditos,int bet);
int odd_even(int number, int choice, int cashBet, int Creditos);
int color_check(int roll,int choice, int Creditos, int bet);
int number_compare(int n, int numberBet);
void load_game();
void save_game();
FILE *file;

int main(){
  //variaveis----------------------------------------------------------------------
  int Creditos = 100;
  int cashBet, numberBet, n;
  char choice[5], color[1];

  /*
  choice[0] = travel in menu
  choice[1] = bet option
  choice[2] = if player bet
  choice[3] = if player chose on what to bet
  choice[4] = color, r-RED and b-Black
  */

  //welcome titles
  choice[2] = 0;
  choice[3] = 0;
  Start();
  comand_list(Creditos);
  printf("\nWhat do you want to do?\n");
  //incio--------------------------------------------------------------------------
  while (Creditos > 0){

    switchStart:
    scanf("%c",choice);
    switch(choice[0]){
      case 'b': //player chooses how much to bet___________________________________
        printf("\nRice to Bet: ");
        scanf("%d", &cashBet);
        if ((cashBet < Creditos) && (cashBet >= 0)){
          Creditos -= cashBet;
          show_Balance(Creditos, cashBet);
          choice[2] = 1;
        }if ((cashBet > Creditos) || (cashBet <= 0)){
          while ((cashBet > Creditos) || (cashBet <= 0)){
            printf("\nGoddamn it outsider, behave. Bet something realistic...\nRice to Bet: ");
            scanf("%d", &cashBet);
        }
            printf("You just bet %d for this round\n", cashBet);
        }
        break;
      case 'n': // player chooses to bet on a number________________________________
        printf("C'mon then pick one between 1 and 36\n");
        scanf("%d", &numberBet);
        printf("You just bet on the number %d.\n", numberBet);
        choice[1] = 'n';
        choice[3] = 1;
        break;
      case 'h': // player wants to see control list_________________________________
        help();
        break;
      case 'r': // roll the numbers_________________________________________________
        if ((choice[2] == 1) && (choice[3] == 1)){
          printf("lets roll.\n");
          n =rollr();
          if (choice[1] == 'e'){
            odd_even(n,choice[1],cashBet,Creditos);
          }else if(choice[1] == 'o'){
            odd_even(n,choice[1],cashBet,Creditos);
          }else if(choice[1] == 'c'){
            color_check(n, choice[4], Creditos, cashBet);
          }else if(choice[1] == 'n'){
            number_compare(n, numberBet);
          }
        }else if(choice[2] == 0){
          printf("You need to bet first!\n");
        }else if(choice[3] == 0){
          printf("Choose on what to bet first!\n");
        }
        break;
      case 's': // player wants to see balance______________________________________
        show_Balance(Creditos, cashBet);
        choice[1] = 's';
        break;
      case 'e': // player bets on an even number. Pays 2 to 1_______________________
        printf("Even hm? Alright champ, roll when you are ready.\n");
        choice[1] = 'e';
        choice[3] = 1;
        break;
      case 'o': // player bets on an odd number. Pays 2 to 1________________________
        printf("Odd it is, roll when you wish.\n");
        choice[1] = 'o';
        choice[3] = 1;
        break;
      case 'c': // player picks the color red to bet________________________________
        printf("Acknowledged, Red it is. Whenever you are ready, roll.\n");
        choice[1] = 'c';
        choice[3] = 1;
        choice[4] = 'r';
        break;
      case 'v': // player picks the color red to bet________________________________
        printf("You little punk, Black it is. Whenever you are ready, roll.\n");
        choice[1] = 'c';
        choice[3] = 1;
        choice[4] = 'b';
        break;
      case 'g': // player wants to save progress____________________________________
        save_game();
        break;
      case 't': //player wants to load save file____________________________________
        load_game();
        break;
      case 'm':
        rollr();
        break;
      case 'l':
        save_game();
        Creditos = 0;
    }
  }
  printf("Looks like you are done for today. Comeback sometime!");
  getchar();
  return 0;
}
