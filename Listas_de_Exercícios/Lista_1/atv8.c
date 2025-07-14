//8 - Faça um procedimento que recebe a idade de um nadador por parâmetro e retorna, também por parâmetro, a categoria desse nadador de acordo com a tabela abaixo:
#include<stdio.h>
#include<locale.h>

int categoria_nadador(int valor)
{
  
  if(valor >= 5 && valor <= 7)
  {
    printf("\nCategoria Infantil A!");
  }
  if(valor >= 8 && valor <= 10)
  {
    printf("\nCategoria Infantil B!");
  }
  if(valor >= 11 && valor <= 13)
  {
    printf("\nCategoria Juvenil A!");
  }
  if(valor >= 14 && valor <= 17)
  {
    printf("\nCategoria Juvenil B!");
  }
  if(valor >= 18)
  {
    printf("\nCategoria Adulto!");
  }
  if(valor <= 4)
  {
    printf("\nCategoria Indefinida!");
  }
  
  return valor;
}

int main()
{
  int idade;
  
  printf("\nInsira a idade do nadador: ");
  scanf("%d", &idade);
  
  categoria_nadador(idade);

  return 0;
}

