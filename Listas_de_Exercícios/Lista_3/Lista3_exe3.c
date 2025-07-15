/*3) Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, a idade e o
endereço de uma pessoa. Agora, escreva uma função que receba um inteiro positivo N e
retorne o ponteiro para um vetor de tamanho N, alocado dinamicamente, dessa estrutura.
Solicite também que o usuário digite os dados desse vetor dentro da função.*/

#include <stdio.h>
#include <stdlib.h>

struct Cadastro
{
    char nome[50];
    int idade;
    char endereco[50];
};

struct Cadastro* criarCadastro(int n)
{
    struct Cadastro *vetor;
    vetor = (struct Cadastro*) malloc(n * sizeof(struct Cadastro));

    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Pessoa %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", vetor[i].nome);

        printf("Idade: ");
        scanf("%d", &vetor[i].idade);

        printf("Endereço: ");
        scanf(" %[^\n]", vetor[i].endereco);

        printf("\n");
    }

    return vetor;
}

int main()
{
    int n;
    struct Cadastro *pessoas;

    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);

    pessoas = criarCadastro(n);

    printf("\nDados cadastrados:\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Pessoa %d\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Endereço: %s\n", pessoas[i].endereco);
        printf("\n");
    }

    free(pessoas);
    return 0;
}
