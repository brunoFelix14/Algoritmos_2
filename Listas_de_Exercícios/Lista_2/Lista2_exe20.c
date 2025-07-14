/*20 – Faça um programa para consultar todos os produtos cujos nomes
comecem pela letra M.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivo;
    char linha[200];
    char descricao[100];
    int mostrar = 0;

    arquivo = fopen("PRODUTOS.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Produtos com descrição iniciada por 'M':\n\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "Descrição: %[^\n]", descricao) == 1)
        {
            if (descricao[0] == 'M' || descricao[0] == 'm')
            {
                mostrar = 1;
                printf("- %s\n", descricao);
            }
            else
            {
                mostrar = 0;
            }
        }

        if (mostrar)
        {
            if (strncmp(linha, "Código:", 7) == 0 ||
                strncmp(linha, "Preço:", 6) == 0)
            {
                printf("%s", linha);
            }
        }
    }

    fclose(arquivo);
    return 0;
}
