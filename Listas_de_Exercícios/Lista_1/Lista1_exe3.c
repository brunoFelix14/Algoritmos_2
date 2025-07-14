//3 - Faça uma função que receba um texto por parâmetro e escreva-o na tela (print), em seguida retorne “Ok”.
#include<stdio.h>

char* texto(char string[50])
{
  scanf("%s", string);
  printf("%s", string);
  return "OK";
}

int main()
{
  char* retorno;
  char txt[50];
  printf("\nInsira qualquer coisa: ");
  retorno = texto(txt);
  printf("\nRetorno: %s", retorno);
  
  return 0;
}
