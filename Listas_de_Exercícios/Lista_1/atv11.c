//11 - Faça uma função que recebe a média final de um aluno por parâmetro e retorna o seu conceito, conforme a tabela abaixo:
#include<stdio.h>
#include<locale.h>

float medias(float n1, float n2, float n3)
{
  float conceito;
  conceito = (n1 + n2 + n3) / 3;
  
  if(conceito >= 0.0 && conceito <= 4.9)
  {
    printf("\nO conceito do aluno ficou: %.2f", conceito);  
    printf("\nMédia Final: D!");
  }
  if(conceito >= 5.0 && conceito <= 6.9)
  {
    printf("\nO conceito do aluno ficou: %.2f", conceito);
    printf("\nMédia Final: C!");
  }
  if(conceito >= 7.0 && conceito <= 8.9)
  {
    printf("\nO conceito do aluno ficou: %.2f", conceito);
    printf("\nMédia Final: B!");
  }
  if(conceito >= 9.0 && conceito <= 10.0)
  {
    printf("\nO conceito do aluno ficou: %.2f", conceito);
    printf("\nMédia Final: A!");
  }
  
  return conceito;
}

int main()
{
  setlocale(LC_ALL, "");
  float nota1, nota2, nota3;
  
  printf("\n--------------------CONCEITO FINAL--------------------\n");
  
  printf("\nInsira a primeira nota do aluno: ");
  scanf("%f", &nota1);

  printf("\nInsira a segunda nota do aluno: ");
  scanf("%f", &nota2);
  
  printf("\nInsira a terceira nota do aluno: ");
  scanf("%f", &nota3);
  
  medias(nota1, nota2, nota3);
  
  return 0;
}
