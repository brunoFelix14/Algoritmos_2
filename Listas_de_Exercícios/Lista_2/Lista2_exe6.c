/*6 - Faça um programa que altere um recebimento de um cliente, ou seja, o
usuário informa o número do documento e o número do cliente e faz as
alterações desejadas.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *receb, *temp;
    char linha[200], novo_valor[50], nova_emissao[50], novo_venc[50];
    int num_doc_alterar, cod_cli_alterar;
    int num_doc_atual, cod_cli_atual;
    int encontrado = 0;

    printf("Número do documento a ser alterado: ");
    scanf("%d", &num_doc_alterar);

    printf("Código do cliente: ");
    scanf("%d", &cod_cli_alterar);

    receb = fopen("Exercício 1 - Recebimentos", "r");
    temp = fopen("temp_receb.txt", "w");

    if (receb == NULL || temp == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    char bloco[6][200];
    int i;

    while (1)
    {
        for (i = 0; i < 6; i++)
        {
            if (fgets(bloco[i], sizeof(bloco[i]), receb) == NULL)
            {
                break;
            }              
        }

        if (i == 0)
        {
            break;
        }
            
        int achou_doc = 0, achou_cli = 0;

        for (int j = 0; j < i; j++)
        {
            if (sscanf(bloco[j], "Num_doc: %d", &num_doc_atual) == 1)
            {
                if (num_doc_atual == num_doc_alterar)
                {
                    achou_doc = 1;
                }
            }

            if (sscanf(bloco[j], "Cod_Cli: %d", &cod_cli_atual) == 1)
            {
                if (cod_cli_atual == cod_cli_alterar)
                {
                    achou_cli = 1;
                }
            }             
        }

        if (achou_doc && achou_cli && !encontrado)
        {
            encontrado = 1;

            float novo_valor_doc;
            printf("Novo valor do documento: ");
            scanf("%f", &novo_valor_doc);

            printf("Nova data de emissão: ");
            scanf(" %[^\n]", nova_emissao);

            printf("Nova data de vencimento: ");
            scanf(" %[^\n]", novo_venc);

            fprintf(temp, "Num_doc: %d\n", num_doc_alterar);
            fprintf(temp, "Valor_doc: %.2f\n", novo_valor_doc);
            fprintf(temp, "Data_Emissão: %s\n", nova_emissao);
            fprintf(temp, "Data_Vencimento: %s\n", novo_venc);
            fprintf(temp, "Cod_Cli: %d\n\n", cod_cli_alterar);
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                fputs(bloco[j], temp);
            }              
        }
    }

    fclose(receb);
    fclose(temp);

    remove("Exercício 1 - Recebimentos");
    rename("temp_receb.txt", "Exercício 1 - Recebimentos");

    if (encontrado)
    {
        printf("Recebimento alterado com sucesso!\n");
    }
        
    else
    {
        printf("Recebimento não encontrado.\n");
    }
        
    return 0;
}
