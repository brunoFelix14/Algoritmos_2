/*19 – Faça um programa para alterar os preços dos produtos em R$ 10,00,
mas apenas os produtos que já custam mais de R$ 100,00.*/
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *original, *temp;
    char linha[200];
    int codigo;
    char descricao[100];
    float preco;

    original = fopen("PRODUTOS.txt", "r");
    temp = fopen("TEMP.txt", "w");

    if (original == NULL || temp == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), original))
    {
        if (sscanf(linha, "Código: %d", &codigo) == 1)
        {
            fprintf(temp, "%s", linha);
        }
        else if (sscanf(linha, "Descrição: %[^\n]", descricao) == 1)
        {
            fprintf(temp, "Descrição: %s\n", descricao);
        }
        else if (sscanf(linha, "Preço: %f", &preco) == 1)
        {
            if (preco > 100)
            {
                preco = preco + 10.0;
            }
            fprintf(temp, "Preço: %.2f\n", preco);
        }
        else
        {
            fprintf(temp, "%s", linha); // escreve linha em branco
        }
    }

    fclose(original);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    printf("Preços atualizados com sucesso!\n");

    return 0;
}
