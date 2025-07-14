/*8) Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma pessoa.
Agora, escreva um programa que leia os dados de seis pessoas. Calcule e exiba os nomes
da pessoa mais nova e da mais velha.*/

#include <stdio.h>

struct Pessoas
{
    char nome[50];
    int dia;
    int mes;
    int ano;
};

int main()
{
    struct Pessoas pessoas[6];
    int i;

    for (i = 0; i < 6; i++)
    {
        printf("Insira o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", pessoas[i].nome);

        printf("Insira a data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &pessoas[i].dia, &pessoas[i].mes, &pessoas[i].ano);
    }

    int mais_novo = 0;
    int mais_velho = 0;

    for (i = 1; i < 6; i++)
    {
        int data_atual = pessoas[i].ano * 10000 + pessoas[i].mes * 100 + pessoas[i].dia;
        int data_mais_novo = pessoas[mais_novo].ano * 10000 + pessoas[mais_novo].mes * 100 + pessoas[mais_novo].dia;
        int data_mais_velho = pessoas[mais_velho].ano * 10000 + pessoas[mais_velho].mes * 100 + pessoas[mais_velho].dia;

        if (data_atual > data_mais_novo)
            mais_novo = i;

        if (data_atual < data_mais_velho)
            mais_velho = i;
    }

    printf("\nPessoa mais nova: %s (%02d/%02d/%04d)\n", 
        pessoas[mais_novo].nome, pessoas[mais_novo].dia, pessoas[mais_novo].mes, pessoas[mais_novo].ano);

    printf("Pessoa mais velha: %s (%02d/%02d/%04d)\n", 
        pessoas[mais_velho].nome, pessoas[mais_velho].dia, pessoas[mais_velho].mes, pessoas[mais_velho].ano);

    return 0;
}
