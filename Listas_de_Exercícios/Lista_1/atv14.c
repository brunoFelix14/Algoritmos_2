//14 - Faça uma função que leia um número não determinado de valores positivos e retorna a média aritmética dos mesmos
#include<stdio.h>
#include<locale.h>

int media(float n, int quantia)
{
  float media = 0.0 ;
  
  media = n / quantia;
  printf("\nMédia dos valores: %.2f", media);
  
  return media;
}

int main()
{
  setlocale(LC_ALL, "");
  int i = 0, numero;  
  float somador = 0.0;
  
  do
  {
    printf("\nInsira um número ou insira 0 para calcular a média: ");
    scanf("%d", &numero);
    
    if(numero != 0)
    {
      somador += numero;
      i++;
    }
    
  }while(numero != 0);
  
  media(somador, i);
  
  return 0;
}
