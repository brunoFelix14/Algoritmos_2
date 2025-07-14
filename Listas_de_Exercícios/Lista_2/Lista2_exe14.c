/*14 - Faça um programa que apresente o seguinte menu de opções:
1. Criar
2. Incluir
3. Sair
Digite a opção desejada
Na opcão 1: criar um arquivo com os campos: numero, nome, nota1 e nota2.
Na opção 2: incluir todos os dados digitados, podendo haver repetição. No
final da inclusão após pressionar ENTER o programa deve mostrar todos os
registros cadastrados, calcular e mostrar a média das notas de cada registro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int opc;
    char nome[100];
    int numero;
    float nota1, nota2;
    FILE *f;

    do
    {
        printf("\n1-Criar arquivo\n2-Incluir registro\n3-Sair\nEscolha: ");
        scanf("%d", &opc);
        getchar();

        if (opc == 1)
        {
            f = fopen("Registros.txt", "w");
            if (f == NULL)
            {
                printf("Erro ao criar arquivo!\n");
                continue;
            }
            fprintf(f, "Número,Nome,Nota1,Nota2\n");
            fclose(f);
            printf("Arquivo criado com sucesso!\n");
        }
        else if (opc == 2)
        {
            f = fopen("Registros.txt", "a");
            if (f == NULL)
            {
                printf("Erro ao abrir arquivo!\n");
                continue;
            }

            printf("Número: ");
            scanf("%d", &numero);
            getchar();
            printf("Nome: ");
            scanf(" %[^\n]", nome);
            printf("Nota1: ");
            scanf("%f", &nota1);
            printf("Nota2: ");
            scanf("%f", &nota2);

            fprintf(f, "%d,%s,%.2f,%.2f\n", numero, nome, nota1, nota2);
            fclose(f);

            printf("\n--- Registros cadastrados ---\n");
            f = fopen("Registros.txt", "r");
            if (f != NULL)
            {
                char linha[200];
                fgets(linha, sizeof(linha), f);
                while (fgets(linha, sizeof(linha), f))
                {
                    int num;
                    char nm[100];
                    float n1, n2;
                    sscanf(linha, "%d,%[^,],%f,%f", &num, nm, &n1, &n2);
                    float media = (n1 + n2) / 2.0f;
                    printf("Número: %d  Nome: %s  Nota1: %.2f  Nota2: %.2f  Média: %.2f\n", num, nm, n1, n2, media);
                }
                fclose(f);
            }
        }
    }
    while (opc != 3);

    printf("Saindo...\n");
    return 0;
}
