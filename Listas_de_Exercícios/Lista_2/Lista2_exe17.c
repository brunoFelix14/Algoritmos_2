/*17 - Faça um programa para consultar a descrição de todos os produtos que
possuem preço superior a R$ 500,00.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivo;
    char linha[200];
    char descricao[100];
    float preco;
    int mostrar = 0;

    arquivo = fopen("PRODUTOS.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Produtos com preço acima de R$ 500,00:\n\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "Descrição: %[^\n]", descricao) == 1)
        {
            mostrar = 1;
        }

        if (sscanf(linha, "Preço: %f", &preco) == 1)
        {
            if (preco > 500 && mostrar)
            {
                printf("- %s (R$ %.2f)\n", descricao, preco);
            }
            mostrar = 0;
        }
    }

    fclose(arquivo);
    return 0;
}
