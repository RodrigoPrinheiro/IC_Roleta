#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Creditos;
int bet;

void delay(int seconds){ //time delay
  int milli_seconds = 1000*seconds;
  clock_t start = clock();
  while(clock() < start + milli_seconds); //"ocupar" o pc com outra coisa enquanto corre.
}

int rollr(){ //roleta tirar novo nr
  int n, i;
  srand(time(NULL));
  n=(rand()%37);
  while (n == 0){
    n=(rand()%37);
  }
  printf("the number is...");
  for (i = 0; i<4; i++){
    delay(1);
    printf(".");
  }
  printf("%d !!\n", n);
  return n;
}

int comand_list(int Creditos){ //welcome message
    printf("\t Balance:        %d\n", Creditos);
    printf("b <amount> -- the amount you want to bet \n");
    printf("n <number> -- the number you want to bet \n");
    printf("e -- automatically bets on an even number. Pays 2 to 1 \n");
    printf("o -- automatically bets on an odd number. Pays 2 to 1 \n");
    printf("c <amount> -- picks a color on the board red or black\n");
    printf("r -- roll \n");
    printf("h -- help \n");
    printf("s -- show balance \n");
    printf("l -- cash out/leave \n");
    return 0;
}

int help (void){ //instrocoes
    printf("Well... Here is the manual: \n");
    printf("b <amount> -- the amount you want to bet \n");
    printf("n <number> -- the number you want to bet \n");
    printf("e -- automatically bets on an even number. Pays 2 to 1 \n");
    printf("o -- automatically bets on an odd number. Pays 2 to 1 \n");
    printf("c <amount> -- picks a color on the board red or black\n");
    printf("r -- roll \n");
    printf("h -- help \n");
    printf("s -- show balance \n");
    printf("l -- cash out/leave \n");
    printf("Red or black: Choose a color\n Red numbers are  1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n Black numbers are 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n\n");
    return 0;
}

int show_Balance(int Creditos, int bet){
  printf("\t Balance:        %d\n", Creditos);
  printf("\t Current Bet:    %d\n", bet);
  return 0;
}

int odd_even(int number, int choice, int cashBet){
  if (choice == 'e') {
    if(number%2 == 0){
      Creditos += cashBet*2;
      printf("You Win.  You have %d credits\n", Creditos);//dizer mais alguma coisa
    }else{
      Creditos-= cashBet;
      printf("You Loose. You have %d credits\n", Creditos);//dizer mais alguma coisa
    }
  }else if(choice =='o'){
    if(number%2 == 1){
      Creditos += cashBet*2;
        printf("You Win.  You have %d credits\n", Creditos);//dizer mais alguma coisa
    }else{
      Creditos -= cashBet;
      printf("You Loose. You have %d credits\n", Creditos);//dizer mais alguma coisa
    }
  }
  return 0;
}

int color_check(int a, int b){
  int red[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
  int black[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

  int controller = 0;
  int x=0;
  int color = b;

  if (color == 1){ // if player chooses red = 1
    for (x = 1; x < 18; x++) {
      if(a == red[x]){
        controller = 1;
        if (controller == 1){
          printf("You win!");
        }
      }
    }
    if (controller == 0){
      printf("you lose.");
    }
  }

  if (color == 2){ // if player chooses black = 2
    for (x = 1; x < 18; x++) {
      if(a == black[x]){
        controller = 1;
        if (controller == 1){
          printf("You win!");
        }
      }
    }
    if (controller == 0){
      printf("you lose.");
    }
  }
  return 0;
}

int Start(){
  printf("Welcome to the BCIW, The Biggest Casino In the World! \n");
  printf("We've been having some technical problems lately and only the roulette is available...\n");
  return 0;
}
