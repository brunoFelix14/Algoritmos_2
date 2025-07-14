/*23 – Faça um programa para consultar todos os produtos com nomes
começados por uma letra digitada pelo usuário e com preços entre dois
valores também fornecidos pelo usuário.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arquivo;
    char linha[200];
    int codigo;
    char descricao[100];
    float preco;
    char letra;
    float minimo, maximo;

    printf("Letra inicial da descrição: ");
    scanf(" %c", &letra);
    letra = tolower(letra); // para comparar sem se preocupar com maiúscula/minúscula

    printf("Preço mínimo: ");
    scanf("%f", &minimo);

    printf("Preço máximo: ");
    scanf("%f", &maximo);

    arquivo = fopen("PRODUTOS.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("\nProdutos encontrados:\n\n");

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
            if (tolower(descricao[0]) == letra && preco >= minimo && preco <= maximo)
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
