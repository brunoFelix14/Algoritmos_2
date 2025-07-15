/*13) Escreva um programa que leia um inteiro N e crie uma matriz alocada dinamicamente
contendo N linhas e N colunas. Essa matriz deve conter o valor 0 na diagonal principal,
o valor 1 nos elementos acima da diagonal principal e o valor −1 nos elementos abaixo
da diagonal principal.*/

#include <stdio.h>
#include <stdlib.h>

int** criarMatriz(int n)
{
    if (n <= 0)
        return NULL;

    int **matriz = (int **) malloc(n * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *) malloc(n * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 0;
            }
                
            else if (i < j)
            {
                matriz[i][j] = 1;
            }
                
            else
            {
                matriz[i][j] = -1;
            }                
        }
    }

    return matriz;
}

int main()
{
    int n;
    int **matriz;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    matriz = criarMatriz(n);

    if (matriz == NULL)
    {
        printf("Valor inválido.\n");
        return 1;
    }

    printf("\nMatriz gerada:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
        
    free(matriz);

    return 0;
}
