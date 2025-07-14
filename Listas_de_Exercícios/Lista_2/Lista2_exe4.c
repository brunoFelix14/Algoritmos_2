/*4 - Faça um programa que exclua clientes e, consequentemente, todos os seus
recebimentos, dos arquivos criados no Exercício l.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *clientes, *clientesTemp;
    FILE *receb, *recebTemp;
    char linha[200];
    int cod_excluir, cod_atual;
    int apagarCliente = 0;

    printf("Código do cliente a ser excluído: ");
    scanf("%d", &cod_excluir);

    clientes = fopen("Exercício 1 - Clientes", "r");
    clientesTemp = fopen("temp_clientes.txt", "w");

    if (clientes == NULL || clientesTemp == NULL)
    {
        printf("Erro ao abrir os arquivos de clientes.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), clientes) != NULL)
    {
        if (sscanf(linha, "Cod_Cli: %d", &cod_atual) == 1)
        {
            if (cod_atual == cod_excluir)
            {
                apagarCliente = 1;
                for (int i = 0; i < 4; i++) fgets(linha, sizeof(linha), clientes);
                continue;
            }
        }

        fputs(linha, clientesTemp);
    }

    fclose(clientes);
    fclose(clientesTemp);

    receb = fopen("Exercício 1 - Recebimentos", "r");
    recebTemp = fopen("temp_receb.txt", "w");

    if (receb == NULL || recebTemp == NULL)
    {
        printf("Erro ao abrir os arquivos de recebimentos.\n");
        return 1;
    }

    char bloco[5][200];
    int i, ignorar;

    while (1)
    {
        for (i = 0; i < 5; i++)
        {
            if (fgets(bloco[i], sizeof(bloco[i]), receb) == NULL)
            {
                break;
            }             
        }

        if (i == 0)
        {
            break;
        }      

        ignorar = 0;
        for (int j = 0; j < i; j++)
        {
            if (sscanf(bloco[j], "Cod_Cli: %d", &cod_atual) == 1)
            {
                if (cod_atual == cod_excluir)
                {
                    ignorar = 1;
                    break;
                }
            }
        }

        if (!ignorar)
        {
            for (int j = 0; j < i; j++)
            {
                fputs(bloco[j], recebTemp);
            }
        }

        if (fgets(linha, sizeof(linha), receb) != NULL)
        {
            if (!ignorar)
            {
                fputs(linha, recebTemp);
            }             
        }
    }

    fclose(receb);
    fclose(recebTemp);

    remove("Exercício 1 - Clientes");
    rename("temp_clientes.txt", "Exercício 1 - Clientes");

    remove("Exercício 1 - Recebimentos");
    rename("temp_receb.txt", "Exercício 1 - Recebimentos");

    if (apagarCliente)
        printf("Cliente e seus recebimentos excluídos com sucesso.\n");
    else
        printf("Cliente não encontrado.\n");

    return 0;
}
