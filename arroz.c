#include <stdio.h>
#include <time.h>
//inicializar funçoes--------------------------------------------------------------
int Start();
int rollr();
void comand_list(int Creditos);
void help();
int show_Balance(int Creditos,int bet);
int odd_even(int number, int choice, int cashBet, int Creditos);
int color_check(int roll);
int number_compare(int n, int numberBet);
//void load_game();
//void save_game();
FILE *file;

int main(){
  //variaveis----------------------------------------------------------------------
  int Creditos = 100;
  int cashBet, numberBet, n;
  char choice[4], R, B;
  //delcarar arrays para vermelho e preto(18 de tamanho, nrs especificos go see rules)
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
        printf("\nBet: ");
        scanf("%d", &cashBet);
        if (cashBet > Creditos){
          printf("Too high, try a bit lower than your earnings.\n");
        }else if(cashBet <= 0){
          printf("We're not here to exchange candy, only money.\n");
        }else{
          printf("You just bet %d for this round\n", cashBet);
          Creditos -= cashBet;
          show_Balance(Creditos, cashBet);
          choice[2] = 1;
        }
        break;
      case 'n': // player chooses to bet on a number________________________________
        printf("C'mon then pick one between 1 and 35\n");
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
            color_check(n);
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
        printf("Alright champ, roll when you are ready.\n");
        choice[1] = 'e';
        choice[3] = 1;
        break;
      case 'o': // player bets on an odd number. Pays 2 to 1________________________
        printf("Odd it is, roll when you wish.\n");
        choice[1] = 'o';
        choice[3] = 1;
        break;
      case 'c': // player picks a color on the board red or black to bet____________
        printf("Acknowledged, whenever you are ready, roll.\n");
        choice[1] = 'c';
        choice[3] = 1;
        break;
      case 'g': // player wants to save progress____________________________________
        //save_game();
        break;
      case 't': //player wants to load save file____________________________________
        //load_game();
        break;
    }
  }
  printf("Well... you are finally out of credits. Leave or we'll kick you out.");
  getchar();
  return 0;
}
