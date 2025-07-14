/*21 – Faça um programa para excluir produtos do arquivo criado no Exercício 15.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *original, *temp;
    char linha[200];
    int codigo, codigo_lido;
    int codigo_excluir;
    char descricao[100];
    float preco;
    int encontrado = 0;

    printf("Digite o código do produto para excluir: ");
    scanf("%d", &codigo_excluir);

    original = fopen("PRODUTOS.txt", "r");
    if (original == NULL)
    {
        printf("Erro ao abrir o arquivo original!\n");
        return 1;
    }

    temp = fopen("TEMP.txt", "w");
    if (temp == NULL)
    {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(original);
        return 1;
    }

    while (fgets(linha, sizeof(linha), original))
    {
        if (sscanf(linha, "Código: %d", &codigo_lido) == 1)
        {
            codigo = codigo_lido;

            if (codigo == codigo_excluir)
            {
                // Ignora este registro: lê as próximas 3 linhas para pular descrição, preço e linha em branco
                fgets(linha, sizeof(linha), original); // descrição
                fgets(linha, sizeof(linha), original); // preço
                fgets(linha, sizeof(linha), original); // linha em branco
                encontrado = 1;
                continue; // não copia nada para o arquivo temporário
            }
            else
            {
                // Escreve código e as próximas 3 linhas
                fprintf(temp, "Código: %d\n", codigo);
                fgets(linha, sizeof(linha), original); // descrição
                fprintf(temp, "%s", linha);
                fgets(linha, sizeof(linha), original); // preço
                fprintf(temp, "%s", linha);
                fgets(linha, sizeof(linha), original); // linha em branco
                fprintf(temp, "%s", linha);
            }
        }
    }

    fclose(original);
    fclose(temp);

    if (encontrado)
    {
        remove("PRODUTOS.txt");
        rename("TEMP.txt", "PRODUTOS.txt");
        printf("Produto excluído com sucesso!\n");
    }
    else
    {
        remove("TEMP.txt");
        printf("Produto com código %d não encontrado.\n", codigo_excluir);
    }

    return 0;
}
