/*6) Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve
conter o número de matrícula do aluno, seu nome e as notas de três provas. Agora, escreva
um programa que leia os dados de cinco alunos e os armazene nessa estrutura. Em
seguida, exiba o nome e as notas do aluno que possui a maior média geral dentre os cinco.*/

#include <stdio.h>

struct aluno
{
    int matricula;
    char nome[50];
    int nota1, nota2, nota3;
};

int main()
{
    struct aluno alunos[5];
    float media, maior_media = 0;
    int aluno_destaque = 0;

    for(int i = 0; i < 5; i++)
    {
        printf("Insira o nome do aluno: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("\nInsira o numero de matricula do aluno: ");
        scanf("%d", &alunos[i].matricula);

        printf("\nInsira a nota 1 do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].nota1);

        printf("\nInsira a nota 2 do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].nota2);

        printf("\nInsira a nota 3 do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].nota3);

        media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        if(media > maior_media)
        {
            maior_media = media;
            aluno_destaque = i;
        }
    }

    printf("\nNome do aluno destaque: %s", alunos[aluno_destaque].nome);
    printf("\nMaior média: %.2f", maior_media);

return 0;
}
