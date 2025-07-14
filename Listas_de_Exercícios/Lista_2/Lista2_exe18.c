/*18 – Faça um programa para alterar os preços de todos os produtos em 15%.*/

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
            preco = preco * 1.15;
            fprintf(temp, "Preço: %.2f\n", preco);
        }
        else
        {
            fprintf(temp, "%s", linha); 
        }
    }

    fclose(original);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    printf("Preços atualizados em 15%% com sucesso!\n");

    return 0;
}
