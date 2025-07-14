/*16 - Faça um programa para incluir produtos no arquivo criado no Exercício
15 lembrando que não podem existir dois produtos com o mesmo código.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivo;
    int codigo, codigo_existente;
    char descricao[100], linha[200];
    float preco;
    int repetido = 0;

    printf("Código do produto: ");
    scanf("%d", &codigo);

    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo != NULL)
    {
        while (fgets(linha, sizeof(linha), arquivo))
        {
            if (sscanf(linha, "Código: %d", &codigo_existente) == 1)
            {
                if (codigo_existente == codigo)
                {
                    repetido = 1;
                    break;
                }
            }
        }
        fclose(arquivo);
    }

    if (repetido)
    {
        printf("Produto com esse código já existe!\n");
    }
    else
    {
        arquivo = fopen("PRODUTOS.txt", "a");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo!\n");
            return 1;
        }

        printf("Descrição do produto: ");
        scanf(" %[^\n]", descricao);

        printf("Preço do produto: ");
        scanf("%f", &preco);

        fprintf(arquivo, "Código: %d\n", codigo);
        fprintf(arquivo, "Descrição: %s\n", descricao);
        fprintf(arquivo, "Preço: %.2f\n", preco);
        fprintf(arquivo, "\n");

        fclose(arquivo);

        printf("Produto incluído com sucesso!\n");
    }

    return 0;
}
