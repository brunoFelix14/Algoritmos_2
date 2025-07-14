//9 - Faça uma função que recebe um valor inteiro e verifica se o valor é positivo ou negativo. A função deve retornar um valor inteiro.
#include<stdio.h>
#include<locale.h>

int verificador(int num)
{
  if(num > 0)
  {
    printf("\nO número inserido é positivo!");
  }
  else
  {
    printf("\nO número inserido é negativo!");
  }

  return num;
}

int main()
{
  setlocale(LC_ALL,"");
  int valor;
  
  printf("\nInsira um número inteiro: ");
  scanf("%d", &valor);
  
  verificador(valor);

  return 0;
}
