//15 - Escreva uma função que recebe, por parâmetro, dois valores X e Z e calcula e retorna Xz . (sem utilizar funções ou operadores de potência prontos)
#include<stdio.h>
#include<locale.h>

int potencia(int x, int z)
{
  int resultado = 1;
  
  for(int i = 1; i <= z; i++)
  {
    resultado = resultado * x;
  }
  printf("\n%d", resultado);
  return resultado;
}

int main()
{ 
  setlocale(LC_ALL, "");
  int base, expoente;
  
  printf("\nInsira o valor da base: ");
  scanf("%d", &base);
  
  printf("\nInsira o valor do expoente: ");
  scanf("%d", &expoente);

  potencia(base, expoente);

  return 0;
}
