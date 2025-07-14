/*10 - Faça um programa que mostre todos os recebimentos com valor abaixo
de um valor dado pelo usuário.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *receb;
    char linha[200];
    float valor_limite, valor_doc;
    int encontrou = 0;

    printf("Informe o valor máximo: ");
    scanf("%f", &valor_limite);

    receb = fopen("Exercício 1 - Recebimentos", "r");

    if (receb == NULL)
    {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return 1;
    }

    char bloco[6][200];
    int i;

    printf("\n--- RECEBIMENTOS COM VALOR ABAIXO DE %.2f ---\n", valor_limite);

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
            if (sscanf(bloco[j], "Valor_doc: %f", &valor_doc) == 1)
            {
                if (valor_doc < valor_limite)
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
        printf("Nenhum recebimento encontrado com valor abaixo de %.2f.\n", valor_limite);
    }

    return 0;
}
