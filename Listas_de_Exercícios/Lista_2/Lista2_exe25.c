/*25 – Faça um programa para conceder um percentual de desconto dado pelo
usuário aos produtos cujos preços estão entre dois valores, também
fornecidos pelo usuário.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *original, *temp;
    char linha[200];
    int codigo;
    char descricao[100];
    float preco, desconto;
    float minimo, maximo;

    printf("Informe o percentual de desconto (ex: 10 para 10%%): ");
    scanf("%f", &desconto);

    printf("Preço mínimo: ");
    scanf("%f", &minimo);

    printf("Preço máximo: ");
    scanf("%f", &maximo);

    desconto = desconto / 100.0; 

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

            if (preco >= minimo && preco <= maximo)
            {
                preco = preco - (preco * desconto);
            }

            fprintf(temp, "Código: %d\n", codigo);
            fprintf(temp, "Descrição: %s\n", descricao);
            fprintf(temp, "Preço: %.2f\n", preco);
            fprintf(temp, "\n");
        }
    }

    fclose(original);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    printf("Desconto aplicado com sucesso!\n");

    return 0;
}
