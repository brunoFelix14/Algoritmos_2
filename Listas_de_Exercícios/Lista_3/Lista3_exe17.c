/*17) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e
N colunas. A função deve retornar o ponteiro para um vetor B de tamanho N alocado
dinamicamente, em que cada posição de B é a soma dos números daquela coluna da
matriz.*/

#include <stdio.h>
#include <stdlib.h>

int* somarColunas(int **a, int n)
{
    int *b = (int *) malloc(n * sizeof(int));
    if (b == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int j = 0; j < n; j++)
    {
        b[j] = 0;
        for (int i = 0; i < n; i++)
        {
            b[j] += a[i][j];
        }
    }

    return b;
}

int main()
{
    int n;
    int **a, *b;

    printf("Digite o tamanho da matriz quadrada (N x N): ");
    scanf("%d", &n);

    a = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *) malloc(n * sizeof(int));
    }

    if (a == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    b = somarColunas(a, n);

    printf("Soma das colunas (vetor B):\n");
    for (int j = 0; j < n; j++)
    {
        printf("B[%d] = %d\n", j, b[j]);
    }

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
        
    free(a);
    free(b);

    return 0;
}
