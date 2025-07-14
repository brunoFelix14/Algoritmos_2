/*3 - Faça um programa que inclua recebimentos no arquivo criado no
Exercício 1, devendo verificar se o cliente já se encontra cadastrado.*/

#include <stdio.h>

int main()
{
    FILE *arquivoClientes;
    FILE *arquivoReceb;
    int cod_cli, num_doc, cod_lido, achou = 0;
    float valor_doc;
    char data_emissao[20];
    char data_vencimento[20];
    char linha[200];

    arquivoClientes = fopen("Exercício 1 - Clientes", "r");
    if (arquivoClientes == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return 1;
    }

    printf("Código do cliente: ");
    scanf("%d", &cod_cli);

    while (fgets(linha, sizeof(linha), arquivoClientes) != NULL)
    {
        if (sscanf(linha, "Cod_Cli: %d", &cod_lido) == 1)
        {
            if (cod_lido == cod_cli)
            {
                achou = 1;
                break;
            }
        }
    }

    fclose(arquivoClientes);

    if (achou == 0)
    {
        printf("Cliente não encontrado.\n");
        return 0;
    }

    printf("Número do documento: ");
    scanf("%d", &num_doc);

    printf("Valor do documento: ");
    scanf("%f", &valor_doc);

    printf("Data de emissão: ");
    scanf(" %[^\n]", data_emissao);

    printf("Data de vencimento: ");
    scanf(" %[^\n]", data_vencimento);

    arquivoReceb = fopen("Exercício 1 - Recebimentos", "a");
    if (arquivoReceb == NULL)
    {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return 1;
    }

    fprintf(arquivoReceb, "Num_doc: %d\n", num_doc);
    fprintf(arquivoReceb, "Valor_doc: %.2f\n", valor_doc);
    fprintf(arquivoReceb, "Data_Emissão: %s\n", data_emissao);
    fprintf(arquivoReceb, "Data_Vencimento: %s\n", data_vencimento);
    fprintf(arquivoReceb, "Cod_Cli: %d\n\n", cod_cli);

    fclose(arquivoReceb);

    printf("Recebimento registrado com sucesso!\n");

    return 0;
}
