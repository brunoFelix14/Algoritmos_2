/*1 - Faça um programa para criar os arquivos a seguir:
Clientes: Cod_Cli, Nome, Endereco, Fone
Recebimentos: Num_doc, Valor_doc, Data_Emissao, Data_Vencimento,
Cod_Cli.
*/

#include <stdio.h>

int main()
{
    char *arquiv1 = "Exercício 1 - Clientes";
    char *arquiv2 = "Exercício 1 - Recebimentos";
    FILE *arquivo;
    FILE *arquivo2;

    arquivo = fopen(arquiv1, "a");

    if(fopen != NULL)
    {
        printf("Arquivo aberto!");
    }
    else
    {
        printf("Erro!");
    }

    fprintf(arquivo, "Cod_Cli: ");
    fprintf(arquivo, "\nNome: ");
    fprintf(arquivo, "\nEndereço: ");
    fprintf(arquivo, "\nFone: ");
    fprintf(arquivo, "\n\n");
    
    fclose(arquivo);

    arquivo2 = fopen(arquiv2, "a");

    if(fopen != NULL)
    {
        printf("Arquivo aberto!");
    }
    else
    {
        printf("Erro!");
    }

    fprintf(arquivo2, "Num_doc: ");
    fprintf(arquivo2, "\nValor_doc: ");
    fprintf(arquivo2, "\nData_Emissão: ");
    fprintf(arquivo2, "\nData_Vencimento: ");
    fprintf(arquivo2, "\nCod_Cli: ");  
    fprintf(arquivo2, "\n\n");

    fclose(arquivo2);

return 0;
}