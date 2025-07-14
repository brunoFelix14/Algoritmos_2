//2 - Faça uma função que receba um texto por parâmetro e escreva-o na tela (print).
#include<stdio.h>

void printar(char texto[50])
{
  scanf("%s", texto);
  printf("%s", texto);
}

int main()
{
  char texto[50];
  printf("\nInsira uma palavra: ");
  
  printar(texto);
  
  return 0;
}
