/*8 - Faça um programa que mostre todos os recebimentos de um determinado
cliente.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *receb;
    char linha[200];
    int cod_cliente, cod_atual;

    printf("Digite o código do cliente: ");
    scanf("%d", &cod_cliente);

    receb = fopen("Exercício 1 - Recebimentos", "r");

    if (receb == NULL)
    {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return 1;
    }

    char bloco[6][200];
    int i;
    int encontrou = 0;

    printf("\n--- RECEBIMENTOS DO CLIENTE %d ---\n", cod_cliente);

    while (1)
    {
        for (i = 0; i < 6; i++)
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

        for (int j = 0; j < i; j++)
        {
            if (sscanf(bloco[j], "Cod_Cli: %d", &cod_atual) == 1)
            {
                if (cod_atual == cod_cliente)
                {
                    for (int k = 0; k < i; k++)
                    {
                        printf("%s", bloco[k]);
                    }
                    encontrou = 1;
                    break;
                }
            }
        }
    }

    fclose(receb);

    if (!encontrou)
    {
        printf("Nenhum recebimento encontrado para esse cliente.\n");
    }

    return 0;
}
