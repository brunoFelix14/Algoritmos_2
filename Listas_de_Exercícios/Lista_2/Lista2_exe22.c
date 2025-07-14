/*22 – Faça um programa para consultar os produtos com preços inferiores a R$ 15,00.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivo;
    char linha[200];
    int codigo;
    char descricao[100];
    float preco;
    int mostrar = 0;

    arquivo = fopen("PRODUTOS.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Produtos com preço inferior a R$ 15,00:\n\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "Código: %d", &codigo) == 1)
        {
        }
        else if (sscanf(linha, "Descrição: %[^\n]", descricao) == 1)
        {
        }
        else if (sscanf(linha, "Preço: %f", &preco) == 1)
        {
            if (preco < 15.0)
            {
                printf("Descrição: %s\n", descricao);
                printf("Preço: R$ %.2f\n", preco);
                printf("\n");
            }
        }
    }

    fclose(arquivo);
    return 0;
}
