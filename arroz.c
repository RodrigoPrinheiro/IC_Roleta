#include <stdio.h>
#include <time.h>

FILE *in_file = fopen("Creditos.txt", "r");
FILE *out_file = fopen("Creditos.txt", "w");
//inicializar
int rollr();
void comand_list();
void help();
//colocar painel
unsigned int Creditos;
//main
//escolher dif
int main(){
  //variaveis
  int cashBet, numberBet, n;
  char choice, R, B;
  //delcarar arrays para vermelho e preto(18 de tamanho, nrs especificos go see rules)
  //welcome titles
  comand_list();
  //incio
  while (Creditos > 0){
    //whole thing here inside
  }
  printf("Well... you are finally out of credits. Leave or we'll kick you out");
  getchar();
  return 0;
}
