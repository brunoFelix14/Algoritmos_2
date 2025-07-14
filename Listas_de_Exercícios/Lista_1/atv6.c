//6 - Faça uma função que recebe a idade de uma pessoa em anos, meses e dias e retorna essa idade expressa em dias.
#include<stdio.h>
#include<locale.h>

int idade(int a, int m, int d)
{
  int idade_dias = 0, idade_mes;
  if(a > 0)
  {
    idade_dias += a * 365;
  }
  if(m <= 12)
  {
    idade_mes = m * 31;
  }
  
  idade_dias += d;
  
  printf("\nIdade em dias: %d", idade_dias + idade_mes); 

  return idade_dias;
}

int main()
{
  setlocale(LC_ALL,"");
  int anos, meses, dias;
  
  printf("\n------------------------------Conversor de Idades------------------------------\n");
  printf("\nQuantos anos você tem: ");
  scanf("%d", &anos);
  
  printf("\nQuantos meses: ");
  scanf("%d", &meses);  
  
  printf("\nQuantos dias: ");
  scanf("%d", &dias);
  
  idade(anos, meses, dias);
  
  return 0;
}

