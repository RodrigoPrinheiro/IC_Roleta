#include <stdio.h>
#include <time.h>
#include <stdlib.h>
FILE *file;

void delay(int seconds){ //time delay___________________________________________
  int milli_seconds = 1000*seconds;
  clock_t start = clock();
  while(clock() < start + milli_seconds); //"ocupar" o pc com outra coisa enquanto corre.
}

int rollr(){ //roleta tirar novo nr_____________________________________________
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

int comand_list(int Creditos){ //welcome message________________________________
    printf("\t Balance:        %d\n", Creditos);
    printf("b <amount> -- the amount of rice you want to bet \n");
    printf("n <number> -- the number you want to bet \n");
    printf("e ----------- automatically bets on an even number. Pays 2 to 1 \n");
    printf("o ----------- automatically bets on an odd number. Pays 2 to 1 \n");
    printf("c <amount> -- picks a color on the board, red or black\n");
    printf("r ----------- roll \n");
    printf("h ----------- help \n");
    printf("s ----------- show balance \n");
    printf("l ----------- cash out/leave \n");
    return 0;
}

int help (void){ //instrucoes___________________________________________________
    printf("Well... Here is the manual: \n");
    printf("b <amount> -- the amount of rice you want to bet \n");
    printf("n <number> -- the number you want to bet \n");
    printf("e -- automatically bets on an even number. Pays 2 to 1 \n");
    printf("o -- automatically bets on an odd number. Pays 2 to 1 \n");
    printf("c <amount> -- picks a color on the board red or black\n");
    printf("r -- roll \n");
    printf("h -- help \n");
    printf("s -- show balance \n");
    printf("l -- cash out/leave \n");
    printf("Red or black: Choosing a color\n -Red numbers are  1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n -Black numbers are 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n\n");
    return 0;
}

int show_Balance(int Creditos, int bet){// mostrar a balance____________________
  printf("\t Balance:        %d\n", Creditos);
  printf("\t Current Bet:    %d\n", bet);
  return 0;
}

int odd_even(int number, int choice, int cashBet, int Creditos){//par e impar___
  if (choice == 'e') {
    if(number%2 == 0){
      Creditos += cashBet*2;
      printf("You Win.  You have %d credits\n", Creditos);//dizer mais alguma coisa
    }else{
      Creditos -= cashBet;
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

int color_check(int roll){//red and black check______________________
  char color[1];
  int red[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
  int black[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
  int controller = 0;
  int x=0;
  printf("Feeling colorfull aye? In wich color do you want to bet?\nDecision(r or b):\n");
  scanf("%c", color);

  if (color[0] == 'r'){ // if player chooses red = 1
    for (x = 1; x < 18; x++) {
      if(roll == red[x]){
        controller = 1;
      }
    }
  } else if (color[0] == 'b'){ // if player chooses black = 2
    for (x = 1; x < 18; x++) {
      if(roll == black[x]){
        controller = 1;
      }
    }
  }
  if (controller == 1){
    printf("You win!");
  }else if (controller == 0){
    printf("you lose.");
  }

  return 0;
}

int Start(){// first messages___________________________________________________
  printf("Welcome to the rice fields Casino, where money isn't allowed! \nYou may be wondering why money isnt allowed. It's very simple, we do this for fun, not to ruin our lifes and live in misery.\nAnd that is the main reason for the why we use rice as currency.");
  printf("Although, we've been having some technical issues lately and only the roulette is available...Rice got into the circuits of the other games...\n");
  return 0;
}

int number_compare(int n, int numberBet, int Creditos){//betting on a specific number_________
  if (n == numberBet){
    Creditos += Creditos*2;
    printf("The rice gods gave you the blessing of the monocots. You are rewarded with %d rice fields top notch rice. You now have %d jolly rice.\n", Creditos*2, Creditos);
  }else{
    Creditos -= numberBet*2;
    printf("yea, dont get ahead of yourself. You lost %d rice. Currently with %d\n", numberBet*2, Creditos);
  }

  return 0;
}

/*case g:
void save_game(){// saving the game_____________________________________________
  file =fopen("GameSave.sv", "w+");
  fprintf(file, "%d\n", &Creditos);
  fprintf(file, "%d\n", &cashBet);
  fprintf(file, "%d\n", &minBet); //adicionar para a dificuldade opcional que o stor pede (ver github)
  fclose(file);
  printf("Game successfully saved.\n\n");
}

//case t:
void load_game(){// loading previously saved game_______________________________
  if ((file = fopen("GameSave.sv", "r+"")) !=NULL){
    fscanf(file, "%d\n", &Creditos);
    fscanf(file, "%d\n", &cashBet);
    fscanf(file, "%d\n", &minBet); //adicionar para a dificuldade opcional que o stor pede (ver github)
    fclose(file);
    printf("\nYou have successfully loaded your game.\n");
    printf("\n\n");
    show_Balance(Creditos, cashBet);
  }else{
    printf("\nThere is no saved game to load.\n");
  }
}
*/
