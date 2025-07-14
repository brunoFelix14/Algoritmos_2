/*9) Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do
atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados de cinco
atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho*/

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
    int maior = 0, mais_velho = 0;

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

        if(atleta[i].altura > atleta[maior].altura)
        {
            maior = i;
        }
        if(atleta[i].idade > atleta[mais_velho].idade)
        {
            mais_velho = i;
        }
    }
    printf("\nAtleta mais alto: %s (%.2f m)\n", atleta[maior].nome, atleta[maior].altura);
    printf("Atleta mais velho: %s (%d anos)\n", atleta[mais_velho].nome, atleta[mais_velho].idade);

return 0;
}
