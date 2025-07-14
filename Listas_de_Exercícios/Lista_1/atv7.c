//7 - Faça uma função que verifique se um valor é perfeito ou não. Um valor é dito perfeito quando ele é igual a soma dos seus divisores excetuando ele próprio. (Ex: 6 é perfeito, 6 = 1 + 2 + 3, que são seus divisores). A função deve retornar o valor inteiro 1 para verdadeiro e 0 caso contrário
#include<stdio.h>
#include<locale.h>

int valor_perfeito(int v)
{
  int somadiv = 0;
  for(int i = 1; i < v; i++)
  {
    if(v % i == 0)
    {
      somadiv += i;
    }
  }
  
  if(v == somadiv)
  {
    printf("\nValor perfeito! Retorno 1");
    return 1;
  }
  else
  {
    printf("\nValor imperfeito! Retorno 0");
    return 0;
  }
}

int main()
{
  setlocale(LC_ALL, "");
  int valor;
  
  printf("\nInsira um valor para verificar se ele é perfeito: ");
  scanf("%d", &valor);
  
  valor_perfeito(valor);
  
  return 0;
}
