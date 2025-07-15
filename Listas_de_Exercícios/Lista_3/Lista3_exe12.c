/*12) Escreva uma função que receba como parâmetro um valor N e retorne o ponteiro para
uma matriz alocada dinamicamente contendo N linhas e N colunas. Essa matriz deve
conter o valor 1 na diagonal secundária e 0 nas demais posições.*/

#include <stdio.h>
#include <stdlib.h>

int** criarMatrizDiagonalSecundaria(int n)
{
    if (n <= 0)
        return NULL;

    int **matriz = (int **) malloc(n * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *) malloc(n * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
            {
                matriz[i][j] = 1;
            }
                
            else
            {
                matriz[i][j] = 0;
            }                
        }
    }

    return matriz;
}

int main()
{
    int n;
    int **matriz;

    printf("Digite o tamanho da matriz quadrada (N): ");
    scanf("%d", &n);

    matriz = criarMatrizDiagonalSecundaria(n);

    if (matriz == NULL)
    {
        printf("Valor inválido para N.\n");
        return 1;
    }

    printf("Matriz com diagonal secundária:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
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
