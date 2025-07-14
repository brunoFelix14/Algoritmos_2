/*10) Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia os
dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.*/

#include <stdio.h>

struct Atleta
{
    char nome[50];
    char esporte[20];
    int idade;
    float altura;
};

int main()
{
    struct Atleta atleta[5];
    struct Atleta temp;

    for(int i = 0; i < 5; i++)
    {
        printf("Nome do atleta: ");
        scanf(" %[^\n]", &atleta[i].nome);

        printf("\nEsporte do atleta: ");
        scanf(" %[^\n]", &atleta[i].esporte);

        printf("\nIdade do atleta: ");
        scanf("%d", &atleta[i].idade);

        printf("\nAltura do atleta em metros: ");
        scanf("%f", &atleta[i].altura);
    }

    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (atleta[j].idade < atleta[j + 1].idade)
            {
                temp = atleta[j];
                atleta[j] = atleta[j + 1];
                atleta[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\nNome: %s\n", atleta[i].nome);
        printf("Esporte: %s\n", atleta[i].esporte);
        printf("Idade: %d anos\n", atleta[i].idade);
        printf("Altura: %.2f m\n", atleta[i].altura);
    }

return 0;
}