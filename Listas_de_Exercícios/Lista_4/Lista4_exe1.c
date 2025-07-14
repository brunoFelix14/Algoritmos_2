/*1) Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e
armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados da
estrutura lida.*/

#include<stdio.h>

struct pessoa
{
    char nome[50];
    int idade;
    char endereco[50];
};

int main()
{
    struct pessoa pessoa1;

    printf("Insira seu nome: ");
    scanf(" %[^\n]", pessoa1.nome);

    printf("\nInsira sua idade: ");
    scanf("%d", &pessoa1.idade);

    printf("\nInsira seu endereço: ");
    scanf(" %[^\n]", pessoa1.endereco);

    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Endereço: %s\n", pessoa1.endereco);

return 0;
}