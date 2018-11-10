#include <stdio.h>
#include <time.h>
//inicializar
int rollr();
void comand_list();
void help();
void show_Balance(void)
int odd_even(int n);

int main(){
  //variaveis
  int Creditos = 100;
  int cashBet, numberBet, n;
  char choice, R, B;
  //delcarar arrays para vermelho e preto(18 de tamanho, nrs especificos go see rules)
  //welcome titles
  comand_list();
  //incio
  while (Creditos > 0){
    switchStart:
    printf("What do you want to do? ");
    scanf("%c", &choice);
    switch(choice){
      case 'b':
        scanf("%d", &cashBet);
        if (cashBet > Creditos){
          printf("too high, try a bit lower than your earnings");
        }else if(bet <= 0){
          printf("we're not here to trade candy, only money allowed\n");
        }else{
          printf("You just bet %d for this round\n", cashbet);
          Creditos -= cashBet;
          show_Balance();
        }
        break;
      case 'n':
        scanf("%d",numberBet);
        printf("You just bet on the number %d for this round\n", numberBet);
        break;
      case 'h':
        help();
        break;
      case 'r':
        break;
      case 's':
        show_Balance();
        break;
      case 'e':
        break;
      case 'o':
        break;
      case 'c':
        break;
    }
  }
  printf("Well... you are finally out of credits. Leave or we'll kick you out");
  getchar();
  return 0;
}
