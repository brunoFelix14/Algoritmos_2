//13 - Escreva um procedimento que recebes 3 valores reais X, Y e Z e que verifique se esses valores podem ser os comprimentos dos lados de um triângulo e, neste caso, retornar qual o tipo de triângulo formado. Para que X, Y e Z formem um triângulo é necessário que a seguinte propriedade seja satisfeita: o comprimento de cada lado de um triângulo é menor do que a soma do comprimento dos outros dois lados. O procedimento deve identificar o tipo de triângulo formado observando as seguintes definições: o Triângulo Equilátero: os comprimentos dos 3 lados são iguais. o Triângulo Isósceles: os comprimentos de 2 lados são iguais. o Triângulo Escaleno: os comprimentos dos 3 lados são diferentes.
#include<stdio.h>
#include<locale.h>

void triangulo(int x, int y, int z)
{
  if(x < y + z && y < x + z && z < x + y)
  {
    printf("\nCondição verdadeira para existência de um triângulo!\n");
    
    if(x == y && y == z)
    {
      printf("\nTriângulo Equilátero");
    }
    if(x != y && y != z)
    {
      printf("\nTriângulo Escaleno");
    }
    if((x == y && x != z) || (y == z && y != x))
    {
      printf("\nTriângulo Isósceles");
    }
  }
  else
  {
    printf("\nOs valores não formam um triângulo!");
  }
}

int main()
{
  int lado_x, lado_y, lado_z;
 
  printf("\nInsira o valor para o lado X do triângulo: ");
  scanf("%d", &lado_x);

  printf("\nInsira o valor para o lado Y do triângulo: ");
  scanf("%d", &lado_y);
 
  printf("\nInsira o valor para o lado Z do triângulo: ");
  scanf("%d", &lado_z);
 
  triangulo(lado_x, lado_y, lado_z);
 
  return 0;
}
