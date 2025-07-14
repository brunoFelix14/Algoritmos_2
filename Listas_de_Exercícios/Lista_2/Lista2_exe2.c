/*2 - Faça um programa para cadastrar clientes no arquivo criado no
Exercício1.*/

#include <stdio.h>

int main()
{
    int cod;
    char nome[100];
    char endereco[100];
    char fone[20];
    char *arquiv1 = "Exercício 1 - Clientes";
    FILE *arquivo;

    arquivo = fopen(arquiv1, "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }

    printf("Código do cliente: ");
    scanf("%d", &cod);

    printf("Nome: ");
    scanf(" %[^\n]", nome);

    printf("Endereço: ");
    scanf(" %[^\n]", endereco);

    printf("Telefone: ");
    scanf(" %[^\n]", fone);

    fprintf(arquivo, "Cod_Cli: %d\n", cod);
    fprintf(arquivo, "Nome: %s\n", nome);
    fprintf(arquivo, "Endereço: %s\n", endereco);
    fprintf(arquivo, "Fone: %s\n\n", fone);

    fclose(arquivo);

    printf("Cliente cadastrado com sucesso!\n");

    return 0;
}
