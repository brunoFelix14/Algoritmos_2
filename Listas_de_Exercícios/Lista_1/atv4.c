//4 - Faça um procedimento que recebe por parâmetro os valores necessário para o cálculo da fórmula de báskara e imprima as suas raízes, caso seja possível calcular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int delta(int a, int b, int c)
{
  int delta; 
  delta = (b*b)- 4 * a * c;
  printf("\n%d\n", delta);
  
  if(delta > 0)
  {
    float x1, x2; 
    double raiz;
    raiz = sqrt(delta);
    x1 = (-b + raiz) / (2 * a);
    
    x2 = (-b - raiz) / (2 * a);
    
    printf("\nRaiz 1: %f", x1);
    printf("\nRaiz 2: %f", x2);
  }
  
  else
  {
    printf("\nRaízes inexistentes!");
  }
  
  return delta;
}

int main()
{
  int a, b, c;
  
  printf("\nInsira o valor para A: ");
  scanf("%d", &a);
  
  printf("\nInsira o valor para B: ");
  scanf("%d", &b);
  
  printf("\nInsira o valor para C: ");
  scanf("%d", &c);

  delta(a, b, c);
  
  return 0;
}
