//12 - Faça um procedimento que recebe 3 valores inteiros por parâmetro e imprima-os ordenados em ordem crescente.
#include<stdio.h>
#include<locale.h>

void ordenador(int v1, int v2, int v3)
{
  int vtp;
  
  if(v1 < v2)
  {
    vtp = v1;
    v1 = v2;
    v2 = vtp;
  }
  if(v2 < v3)
  {
    vtp = v2;
    v2 = v3;
    v3 = vtp;
  }
  
  printf("\nValores ordenados em ordem crescente: %d, %d, %d", v3, v2, v1);
}

int main()
{
  int valor1, valor2, valor3;
  
  printf("\nInsira o valor 1: ");
  scanf("%d", &valor1);
  
  printf("\nInsira o valor 2: ");
  scanf("%d", &valor2);
  
  printf("\nInsira o valor 3: ");
  scanf("%d", &valor3);
  
  ordenador(valor1, valor2, valor3);
  
  return 0;
}
