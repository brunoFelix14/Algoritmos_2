/*7 - Faça um programa que mostre todos os recebimentos com data de
vencimento dentro de um período qualquer. Não esqueça de mostrar também
o nome do cliente e o total de dias em atraso. Quando não houver atraso,
mostrar zero.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int data_para_dias(int dia, int mes, int ano)
{
    return ano * 365 + mes * 30 + dia;
}

int main()
{
    FILE *receb, *clientes;
    char linha[200];
    int dia_ini, mes_ini, ano_ini;
    int dia_fim, mes_fim, ano_fim;
    int dia_hoje, mes_hoje, ano_hoje;

    printf("Data inicial do período (dd mm aaaa): ");
    scanf("%d %d %d", &dia_ini, &mes_ini, &ano_ini);

    printf("Data final do período (dd mm aaaa): ");
    scanf("%d %d %d", &dia_fim, &mes_fim, &ano_fim);

    printf("Data atual (dd mm aaaa): ");
    scanf("%d %d %d", &dia_hoje, &mes_hoje, &ano_hoje);

    int data_ini_dias = data_para_dias(dia_ini, mes_ini, ano_ini);
    int data_fim_dias = data_para_dias(dia_fim, mes_fim, ano_fim);
    int data_hoje_dias = data_para_dias(dia_hoje, mes_hoje, ano_hoje);

    receb = fopen("Exercício 1 - Recebimentos", "r");

    if (receb == NULL)
    {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return 1;
    }

    char num_doc[50], valor[50], emissao[50], venc[50], cod_cli_str[50];
    int cod_cli;

    printf("\n--- RECEBIMENTOS NO PERÍODO ---\n");

    while (fgets(num_doc, sizeof(num_doc), receb) != NULL)
    {
        fgets(valor, sizeof(valor), receb);
        fgets(emissao, sizeof(emissao), receb);
        fgets(venc, sizeof(venc), receb);
        fgets(cod_cli_str, sizeof(cod_cli_str), receb);
        fgets(linha, sizeof(linha), receb); 

        int dv, mv, av;
        sscanf(venc, "Data_Vencimento: %d/%d/%d", &dv, &mv, &av);
        int venc_dias = data_para_dias(dv, mv, av);

        if (venc_dias >= data_ini_dias && venc_dias <= data_fim_dias)
        {
            sscanf(cod_cli_str, "Cod_Cli: %d", &cod_cli);

            clientes = fopen("Exercício 1 - Clientes", "r");
            if (clientes == NULL)
            {
                printf("Erro ao abrir o arquivo de clientes.\n");
                return 1;
            }

            char nome[100];
            int cod_atual;
            int achou = 0;

            while (fgets(linha, sizeof(linha), clientes) != NULL)
            {
                if (sscanf(linha, "Cod_Cli: %d", &cod_atual) == 1)
                {
                    if (cod_atual == cod_cli)
                    {
                        fgets(nome, sizeof(nome), clientes);
                        achou = 1;
                        break;
                    }
                    else
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            fgets(linha, sizeof(linha), clientes);
                        }
                    }
                }
            }

            fclose(clientes);

            if (achou)
            {
                printf("\nCliente: %s", nome);
                printf("%s", num_doc);
                printf("%s", valor);
                printf("%s", emissao);
                printf("%s", venc);
                printf("%s", cod_cli_str);

                int atraso = data_hoje_dias - venc_dias;
                if (atraso < 0)
                {
                    atraso = 0;
                }

                printf("Dias em atraso: %d\n", atraso);
            }
        }
    }

    fclose(receb);
    return 0;
}
