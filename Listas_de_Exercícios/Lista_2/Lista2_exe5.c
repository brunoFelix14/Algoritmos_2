/*5 - Faça um programa que altere o cadastro de clientes do Exercício 1. O
usuário deve informar o código do cliente que será alterado.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *clientes, *temp;
    char linha[200];
    int cod_busca, cod_atual, encontrado = 0;

    char nome[100], endereco[100], fone[30];

    printf("Código do cliente que deseja alterar: ");
    scanf("%d", &cod_busca);

    clientes = fopen("Exercício 1 - Clientes", "r");
    temp = fopen("temp_clientes.txt", "w");

    if (clientes == NULL || temp == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), clientes) != NULL)
    {
        if (sscanf(linha, "Cod_Cli: %d", &cod_atual) == 1)
        {
            if (cod_atual == cod_busca)
            {
                encontrado = 1;

                printf("Novo nome: ");
                scanf(" %[^\n]", nome);

                printf("Novo endereço: ");
                scanf(" %[^\n]", endereco);

                printf("Novo telefone: ");
                scanf(" %[^\n]", fone);

                fprintf(temp, "Cod_Cli: %d\n", cod_atual);
                fprintf(temp, "Nome: %s\n", nome);
                fprintf(temp, "Endereço: %s\n", endereco);
                fprintf(temp, "Fone: %s\n\n", fone);

                for (int i = 0; i < 4; i++)
                    fgets(linha, sizeof(linha), clientes);
                continue;
            }
        }

        fputs(linha, temp);
    }

    fclose(clientes);
    fclose(temp);

    remove("Exercício 1 - Clientes");
    rename("temp_clientes.txt", "Exercício 1 - Clientes");

    if (encontrado)
        printf("Cadastro alterado com sucesso!\n");
    else
        printf("Cliente com esse código não foi encontrado.\n");

    return 0;
}
