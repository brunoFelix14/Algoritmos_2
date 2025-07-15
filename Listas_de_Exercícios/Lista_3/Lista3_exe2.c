/*2) Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve
conter o número de matrícula do aluno, seu nome e as notas de três provas. Escreva um
programa que mostre o tamanho em byte dessa estrutura.*/
#include <stdio.h>

  struct aluno
  {   
    int Numero_Matricula;
    char Nome_aluno;
    int nota1;
    int nota2;
    int nota3;
  };

int main()
{
    struct aluno exemplo;
    int tamanho = sizeof(struct aluno);

    printf("O tamanho da estrutura aluno é: %d\n", tamanho);
    printf("Tamanho de Numero_Matricula: %lu bytes\n", sizeof(exemplo.Numero_Matricula));
    printf("Tamanho de Nome_aluno: %lu bytes\n", sizeof(exemplo.Nome_aluno));
    printf("Tamanho de nota1: %lu bytes\n", sizeof(exemplo.nota1));
    printf("Tamanho de nota2: %lu bytes\n", sizeof(exemplo.nota2));
    printf("Tamanho de nota3: %lu bytes\n", sizeof(exemplo.nota3));

  return 0;
}
