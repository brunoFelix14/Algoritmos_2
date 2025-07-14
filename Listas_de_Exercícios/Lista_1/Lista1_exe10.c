//10 - Faça uma função que recebe um valor inteiro e verifica se o valor é par ou ímpar. A função deve retornar um valor inteiro.
#include<stdio.h>
#include<locale.h>

int impoPar(int valor)
{
  if(valor % 2 == 0)
  {
    printf("\nO valor inserido é par!");
  }
  if(valor % 2 == 1)
  {
    printf("\nO valor inserido é ímpar!");
  }

  return valor;
}

int main()
{
  setlocale(LC_ALL,"");
  
  int n;
  
  printf("\nInsira um valor inteiro: ");
  scanf("%d", &n);
  
  impoPar(n);
  
  return 0;
}
