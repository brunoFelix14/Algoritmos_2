/*15 - Faça um programa para criar um arquivo chamado PRODUTOS.txt,
onde cada registro será composto pelos seguintes campos: codigo, descricao
e preco.*/

#include <stdio.h>

int main()
{
    FILE *arquivo;

    arquivo = fopen("PRODUTOS.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    printf("Arquivo PRODUTOS.txt criado com sucesso!\n");

    fprintf(arquivo, "Código: \n");
    fprintf(arquivo, "Descrição: \n");
    fprintf(arquivo, "Preço: \n");
    fprintf(arquivo, "\n");

    fclose(arquivo);

    printf("Produto cadastrado com sucesso!\n");

    return 0;
}
