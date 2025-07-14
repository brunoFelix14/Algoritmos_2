/*24 – Faça um programa para excluir todos os produtos com preço superior a
R$ 200,00.*/

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
        printf("Erro ao abrir os arquivos!\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), original))
    {
        if (sscanf(linha, "Código: %d", &codigo) == 1)
        {
            fgets(linha, sizeof(linha), original);
            sscanf(linha, "Descrição: %[^\n]", descricao);

            fgets(linha, sizeof(linha), original);
            sscanf(linha, "Preço: %f", &preco);

            fgets(linha, sizeof(linha), original);

            if (preco <= 200.0)
            {
                fprintf(temp, "Código: %d\n", codigo);
                fprintf(temp, "Descrição: %s\n", descricao);
                fprintf(temp, "Preço: %.2f\n", preco);
                fprintf(temp, "\n");
            }
        }
    }

    fclose(original);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    printf("Produtos com preço acima de R$ 200,00 foram excluídos.\n");

    return 0;
}
