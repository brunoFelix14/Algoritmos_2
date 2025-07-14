/*12 - Faça um programa para criar os arquivos a seguir:
-Estilista (código do estilista, nome do estilista, salário)
-Roupa (código da roupa, descrição da roupa, código do estilista,
código da estação, ano)
-Estação (código da estação, nome da estação)*/

#include <stdio.h>

int main()
{
    FILE *Estilista;
    FILE *Roupa;
    FILE *Estacao;

    Estilista = fopen("Estilista", "a");
    if (Estilista == NULL)
    {
        printf("Erro ao criar/abrir Estilista\n");
        return 1;
    }
    fprintf(Estilista, "Código do estilista: \n");
    fprintf(Estilista, "Nome do estilista: \n");
    fprintf(Estilista, "Salário: \n\n");

    fclose(Estilista);

    Roupa = fopen("Roupa", "a");
    if (Roupa == NULL)
    {
        printf("Erro ao criar/abrir Roupa\n");
        return 1;
    }
    fprintf(Roupa, "Código da roupa: \n");
    fprintf(Roupa, "Descrição da roupa: \n");
    fprintf(Roupa, "Código do estilista: \n");
    fprintf(Roupa, "Código da estação: \n");
    fprintf(Roupa, "Ano: \n\n");

    fclose(Roupa);

    Estacao = fopen("Estação", "a");
    if (Estacao == NULL)
    {
        printf("Erro ao criar/abrir Estação\n");
        return 1;
    }
    fprintf(Estacao, "Código da estação: \n");
    fprintf(Estacao, "Nome da estação: \n\n");
    fclose(Estacao);

    printf("Arquivos Estilista, Roupa e Estação criados!\n");
    return 0;
}
