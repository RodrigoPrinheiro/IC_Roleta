#include <stdio.h>
#include <time.h>
#include <random>

int Creditos = 100;
unsigned int nr_bets = 0;

int comand_list(){
    printf("Welcome to the BCIW, The Biggest Casino In the World!! \n");
    printf("We've been having some technical problems lately and only the roulette is available...\n");
    printf("\t Balance:    %d", &Creditos);
    printf("\t Current Bet:    %d", &nr_bets);
    printf("b <amount> -- the amount you want to bet \n");
    printf("n <number> -- the number you want to bet \n");
    printf("e -- automatically bets on an even number. Pays 2 to 1 \n");
    printf("o -- automatically bets on an odd number. Pays 2 to 1 \n");
    printf("r -- roll \n");
    printf("h -- help \n");
    printf("s -- show balance \n");
    printf("c -- cash out \n");
    return 0;
}

int help (void){
    printf("Well... Here is the manual: \n");
    printf("b <amount> -- the amount you want to bet \n");
    printf("n <number> -- the number you want to bet \n");
    printf("e -- automatically bets on an even number. Pays 2 to 1 \n");
    printf("o -- automatically bets on an odd number. Pays 2 to 1 \n");
    printf("r -- roll \n");
    printf("h -- help \n");
    printf("s -- show balance \n");
    printf("c -- cash out \n");
    return 0;
}

int option_select (){
    char choice;
    int quant, op[2];
    printf("Please select an option! We haven't got all day!!\n")
    scanf(">%c %d", &choice, &quant);

    return op;
}
